//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/output_node.h"

namespace neunet {

OutputNode::OutputNode(Layer* layer) : Node(layer), value_from_pre_layer_(0.) {
}

OutputNode::~OutputNode() {
}

float OutputNode::value() {
  return value_from_pre_layer_;
}

}  // namespace neunet
