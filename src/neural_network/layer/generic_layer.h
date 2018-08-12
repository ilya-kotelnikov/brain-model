//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <memory>
#include <vector>

#include <assert.h>
#include <stdint.h>

#include "base/macros.h"
#include "neural_network/layer/layer.h"

namespace neunet {

template<typename NodeType>
class GenericLayer : public Layer {
 public:
  GenericLayer(uint32 node_count) {
    for (uint32 i = 0; i < node_count; ++i)
      nodes_.emplace_back(std::make_unique<NodeType>(this));
  }

  ~GenericLayer() {
  }

  // Layer implementation:
  uint32 count() const override {
    return nodes_.size();
  }

  Node* node(uint32 i) override {
    assert(i < nodes_.size());
    return nodes_.at(i).get();
  }

 private:
  std::vector<std::unique_ptr<NodeType>> nodes_;

  DECLARE_NON_COPYABLE(GenericLayer<NodeType>);
};

}  // namespace neunet
