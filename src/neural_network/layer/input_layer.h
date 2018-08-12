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

class InputNode;

class InputLayer : public Layer {
 public:
  InputLayer(uint32 input_count);
  ~InputLayer();

  uint32 count() const override;
  Node* node(uint32 i) override;

 private:
  std::vector<std::unique_ptr<InputNode>> inputs_;

  DECLARE_NON_COPYABLE(InputLayer);
};

}  // namespace neunet
