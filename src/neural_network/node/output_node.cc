﻿//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/output_node.h"

namespace neunet {

OutputNode::OutputNode(Layer* layer, Node* last_neuron_layer_node)
    : Node(layer), last_neuron_layer_node_(last_neuron_layer_node) {
}

OutputNode::~OutputNode() {
}

void OutputNode::UpdateValue() {
  // Nothing to do: for now output is just same as the last neuron node value.
}

float OutputNode::CurrentValue() {
  return last_neuron_layer_node_->CurrentValue();
}

}  // namespace neunet
