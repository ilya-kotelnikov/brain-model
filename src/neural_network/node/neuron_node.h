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

class NeuronNode : public Node {
 public:
  NeuronNode(Layer* layer);
  ~NeuronNode();

  float value() override;

 private:
  DECLARE_NON_COPYABLE(NeuronNode);
};

}  // namespace neunet
