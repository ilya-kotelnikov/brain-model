//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

#include "base/macros.h"
#include "neural_network/node/node.h"

namespace neunet {

class InputNode : public Node {
 public:
  InputNode(Layer* layer, uint32_t index);
  ~InputNode();

  // Node implementation:
  void UpdateValue() override;
  float CurrentValue() override;

 private:
  DECLARE_NON_COPYABLE(InputNode);
};

}  // namespace neunet
