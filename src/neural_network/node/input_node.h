//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"
#include "neural_network/node/node.h"

namespace neunet {

class InputNode : public Node {
 public:
  InputNode(Layer* layer);
  ~InputNode();

  float set_value_from_dataset(float value);

  float value() override;

 private:
  float value_from_dataset_;

  DECLARE_NON_COPYABLE(InputNode);
};

}  // namespace neunet
