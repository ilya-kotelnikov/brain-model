//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/output_layer.h"

#include <iostream>

#include <assert.h>
#include <stdint.h>

#include "neural_network/node/output_node.h"

namespace neunet {

OutputLayer::OutputLayer(uint32_t output_count)
    : GenericLayer<OutputNode>(output_count) {
}

OutputLayer::~OutputLayer() {
}

void OutputLayer::BindToLastNeuronLayer(Layer* last_neuron_layer) {
  assert(nodes_.size() == last_neuron_layer->count());
  for (uint32_t i = 0; i < nodes_.size(); ++i)
    nodes_[i]->BindToLastNeuronLayerNode(last_neuron_layer->node(i));
}

void OutputLayer::Report() {
  std::cout << "Output values:" << std::endl;
  std::cout << "--------------" << std::endl;
  uint32_t i = 0;
  for (const auto& node : nodes_) {
    std::cout << i++ << ":\t" << node->CurrentValue() << std::endl;
  }
  std::cout << "--------------" << std::endl;
}

}  // namespace neunet
