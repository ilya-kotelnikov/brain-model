//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/input_node.h"

#include <stdint.h>

#include "neural_network/layer/input_layer.h"

namespace neunet {

InputNode::InputNode(Layer* layer, uint32_t index) : Node(layer, index) {
}

InputNode::~InputNode() {
}

void InputNode::UpdateValue() {
  // Nothing to do: the value is static during a neunet calculation.
}

float InputNode::CurrentValue() {
  return static_cast<InputLayer*>(layer_)->GetNodeValueFromDataset(index_);
}

}  // namespace neunet
