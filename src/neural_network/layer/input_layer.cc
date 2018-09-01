//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/input_layer.h"

#include <iostream>

#include <assert.h>
#include <stdint.h>

#include "data/dataset_file_reader.h"
#include "data/dataset_value_cast.h"
#include "neural_network/node/input_node.h"

namespace neunet {

InputLayer::InputLayer(uint32_t input_count)
    : GenericLayer<InputNode>(input_count),
      dataset_(nullptr) {
}

InputLayer::~InputLayer() {
}

void InputLayer::BindToDataset(const data::DatasetFileReader* dataset) {
  assert(count() == dataset->GetDataSize());
  dataset_ = dataset;
}

void InputLayer::Report() {
  std::cout << "Input image:" << std::endl;
  std::cout << "----------------------------" << std::endl;
  uint32_t i = 0;
  for (const auto& node : nodes_) {
    std::cout << ((node->CurrentValue() > 0.) ? '*' : ' ');
    if (++i == 28) {
      std::cout << std::endl;
      i = 0;
    }
  }
  std::cout << "----------------------------" << std::endl;
}

float InputLayer::GetNodeValueFromDataset(uint32_t node_index) const {
  assert(node_index < dataset_->GetDataSize());
  return dataset_->GetDataValueCast().AsFloat(
             dataset_->GetDataBuffer()[node_index]);
}

}  // namespace neunet
