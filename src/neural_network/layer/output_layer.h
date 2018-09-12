//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <bitset>
#include <vector>

#include <stdint.h>

#include "base/macros.h"
#include "neural_network/layer/layer.h"

namespace data {
struct DatasetFileReader;
}

namespace neunet {

class OutputLayer : public Layer {
 public:
  static constexpr uint32_t kMaxLastLayerNeuronCount = 16;
  using SpikeBitsHoldingType = std::bitset<kMaxLastLayerNeuronCount>;

  OutputLayer(Delegate* delegate, uint32_t output_count);
  ~OutputLayer();

  void BindToLastNeuronLayer(Layer* last_neuron_layer);
  void BindToDataset(const data::DatasetFileReader* dataset);
  void AnalyzeAndReport();

  // Layer overrides:
  uint32_t count() const override { return 0; }  // noop
  Node* node(uint32_t i) override { return nullptr; }  // noop
  void Calculate() override;

 private:
  Layer* last_neuron_layer_;
  const data::DatasetFileReader* dataset_;

  std::vector<std::vector<SpikeBitsHoldingType>> outputs_;
  std::vector<SpikeBitsHoldingType> output_match_masks_;

  void AnalyzeAndReportForTraining();
  void AnalyzeAndReportForTesting();

  DECLARE_NON_COPYABLE(OutputLayer);
};

}  // namespace neunet
