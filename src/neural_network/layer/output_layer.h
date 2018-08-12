//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <memory>
#include <vector>

#include <stdint.h>

#include "base/macros.h"
#include "neural_network/layer/layer.h"

namespace neunet {

class OutputNode;

class OutputLayer : public Layer {
 public:
  OutputLayer(uint32 output_count);
  ~OutputLayer();

  uint32 count() const override;
  Node* node(uint32 i) override;

 private:
  std::vector<std::unique_ptr<OutputNode>> outputs_;

  DECLARE_NON_COPYABLE(OutputLayer);
};

}  // namespace neunet
