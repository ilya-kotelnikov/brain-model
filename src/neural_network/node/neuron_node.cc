//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/neuron_node.h"

namespace neunet {

NeuronNode::NeuronNode(Layer* layer) : Node(layer) {
}

NeuronNode::~NeuronNode() {
}

float NeuronNode::value() {
  //TODO: impl!
  return 0.;
}

}  // namespace neunet
