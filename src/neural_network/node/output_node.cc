//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/output_node.h"

#include <assert.h>
#include <stdint.h>

namespace neunet {

OutputNode::OutputNode(Layer* layer, uint32_t index)
    : Node(layer, index), last_neuron_layer_node_(nullptr) {
}

OutputNode::~OutputNode() {
}

void OutputNode::BindToLastNeuronLayerNode(Node* last_neuron_layer_node) {
  assert(!last_neuron_layer_node_);
  last_neuron_layer_node_ = last_neuron_layer_node;
}

void OutputNode::UpdateValue() {
  // Nothing to do: for now output is just same as the last neuron node value.
}

float OutputNode::CurrentValue() {
  return last_neuron_layer_node_->CurrentValue();
}

}  // namespace neunet
