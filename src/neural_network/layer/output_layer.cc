//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/output_layer.h"

#include <memory>

#include <assert.h>
#include <stdint.h>

#include "neural_network/node/output_node.h"

namespace neunet {

OutputLayer::OutputLayer(uint32 output_count) {
  for (uint32 i = 0; i < output_count; ++i)
    outputs_.emplace_back(std::make_unique<OutputNode>(this));
}

OutputLayer::~OutputLayer() {
}

uint32 OutputLayer::count() const {
  return outputs_.size();
}

Node* OutputLayer::node(uint32 i) {
  assert(i < outputs_.size());
  return outputs_.at(i).get();
}

}  // namespace neunet
