//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/input_layer.h"

#include <memory>

#include <assert.h>
#include <stdint.h>

#include "neural_network/node/input_node.h"

namespace neunet {

InputLayer::InputLayer(uint32 input_count) {
  for (uint32 i = 0; i < input_count; ++i)
    inputs_.emplace_back(std::make_unique<InputNode>(this));
}

InputLayer::~InputLayer() {
}

uint32 InputLayer::count() const {
  return inputs_.size();
}

Node* InputLayer::node(uint32 i) {
  assert(i < inputs_.size());
  return inputs_.at(i).get();
}

}  // namespace neunet
