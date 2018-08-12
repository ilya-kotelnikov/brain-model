//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/input_node.h"

namespace neunet {

InputNode::InputNode(Layer* layer) : Node(layer), value_from_dataset_(0.) {
}

InputNode::~InputNode() {
}

float InputNode::set_value_from_dataset(float value) {
  value_from_dataset_ = value;
}

void InputNode::UpdateValue() {
  // Nothing to do: the value is static during a neunet calculation.
}

float InputNode::CurrentValue() {
  return value_from_dataset_;
}

}  // namespace neunet
