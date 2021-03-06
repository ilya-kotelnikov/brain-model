﻿//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/output_layer.h"

#include <iostream>
#include <numeric>
#include <stdexcept>
#include <utility>

#include <assert.h>
#include <math.h>
#include <stdint.h>

#include "data/dataset_file_reader.h"
#include "neural_network/layer/layer.h"
#include "neural_network/node/node.h"

namespace neunet {

OutputLayer::OutputLayer(Delegate* delegate, uint32_t output_count)
    : Layer(delegate), last_neuron_layer_(nullptr), dataset_(nullptr) {
  outputs_.resize(output_count);
}

OutputLayer::~OutputLayer() {
}

void OutputLayer::BindToLastNeuronLayer(Layer* last_neuron_layer) {
  assert(last_neuron_layer->count() <= kMaxLastLayerNeuronCount);
  last_neuron_layer_ = last_neuron_layer;
}

void OutputLayer::BindToDataset(const data::DatasetFileReader* dataset) {
  assert(dataset->GetDataSize() == 1);
  dataset_ = dataset;

  const uint32_t average_i_output_hit_count =
      dataset->GetDataCount() / outputs_.size();
  for (auto& i_outputs : outputs_) {
    i_outputs.clear();
    i_outputs.reserve(average_i_output_hit_count);
  }
}

void OutputLayer::AnalyzeAndReport() {
  if (delegate()->IsTraining())
    AnalyzeAndReportForTraining();
  else
    AnalyzeAndReportForTesting();
}

void OutputLayer::Calculate() {
  // Put the output neurons' spikes into a number as bits.
  SpikeBitsHoldingType spike_bits;
  for (uint32_t i = 0; i < last_neuron_layer_->count(); ++i) {
    if (last_neuron_layer_->node(i)->CurrentValue() > 0.)
      spike_bits.set(i);
  }

  // Fetch expected output class.
  const uint8_t expected_index = dataset_->GetDataBuffer()[0];
  if (expected_index > outputs_.size()) {
    throw std::runtime_error(
        "OutputLayer::Calculate() unexpected dataset value range");
  }

  // Save the spikes' pattern associated with expected value from dataset for
  // the final analysis.
  outputs_[expected_index].push_back(spike_bits);
}

void OutputLayer::AnalyzeAndReportForTraining() {
  // 1. For each class calculate how much similar outputs of all the cases.
  std::vector<SpikeBitsHoldingType> outputs_intersection_bits;
  std::vector<uint32_t> outputs_diff_bits_count;
  outputs_intersection_bits.reserve(outputs_.size());
  outputs_diff_bits_count.reserve(outputs_.size());
  for (const auto& i_outputs : outputs_) {
    SpikeBitsHoldingType intersection_bits(-1);
    SpikeBitsHoldingType union_bits;
    for (const auto& i_output_case_bits : i_outputs) {
      intersection_bits &= i_output_case_bits;
      union_bits |= i_output_case_bits;
    }

    outputs_diff_bits_count.emplace_back(
        (intersection_bits ^ union_bits).count());
    outputs_intersection_bits.emplace_back(std::move(intersection_bits));
  }

  // 2. For each class calculate how much different match-mask it has comparing
  // to all the other classes.
  for (uint32_t i = 0; i < outputs_intersection_bits.size(); ++i) {
    const auto& i_outputs_intersection_bits = outputs_intersection_bits[i];

    uint32_t min_diff_bits_count = -1;
    for (const auto& j_outputs_intersection_bits : outputs_intersection_bits) {
      if (&i_outputs_intersection_bits == &j_outputs_intersection_bits)
        continue;  // the same bitset object (i.e. i == j) -> skip it.

      const uint32_t diff_bits_count =
          (i_outputs_intersection_bits ^ j_outputs_intersection_bits).count();
      if (diff_bits_count < min_diff_bits_count) {
        min_diff_bits_count = diff_bits_count;
        if (min_diff_bits_count == 0)
          break;  // no sense to compare further.
      }
    }

    std::cout << "Output #" << i << ": match-mask="
              << i_outputs_intersection_bits << " (spread="
              << outputs_diff_bits_count[i] << ", uniqueness="
              << min_diff_bits_count << ")" << std::endl;
  }

  output_match_masks_ = std::move(outputs_intersection_bits);
}

void OutputLayer::AnalyzeAndReportForTesting() {
  // Use the output pattern masks gathered during training to validate the
  // testing hits accuracy.
  auto it_outputs = outputs_.begin();
  for (uint32_t i = 0; i < outputs_.size(); ++i, ++it_outputs) {
    std::vector<int> output_hit_count(outputs_.size(), 0);
    for (const auto& i_output_case_bits : (*it_outputs)) {
      auto it_output_match_mask = output_match_masks_.begin();
      for (uint32_t j = 0;
           j < output_match_masks_.size(); ++j, ++it_output_match_mask) {
        if ((i_output_case_bits & (*it_output_match_mask)) ==
                 (*it_output_match_mask)) {
          ++output_hit_count[j];
        }
      }
    }

    std::cout << "Output #" << i << ": "
              << floor(float(output_hit_count[i]) / it_outputs->size() * 100.)
              << "%";

    output_hit_count[i] = 0;
    int sum_other_output_hit_count = 0;
    int other_matched_output_count = 0;
    for (const int i_output_hit_count : output_hit_count) {
      if (i_output_hit_count > 0) {
        sum_other_output_hit_count += i_output_hit_count;
        ++other_matched_output_count;
      }
    }

    if (other_matched_output_count > 0) {
      std::cout << " ("
                << ceil(float(sum_other_output_hit_count) /
                            it_outputs->size() /
                            other_matched_output_count * 100.)
                << "% hits " << other_matched_output_count << " other classes)";
    }

    std::cout << std::endl;
  }
}

}  // namespace neunet
