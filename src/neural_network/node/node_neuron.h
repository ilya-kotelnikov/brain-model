﻿//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"
#include "neural_network/node/node.h"

namespace neunet {

class NodeNeuron : public Node {
 public:
  NodeNeuron();
  ~NodeNeuron();

 private:
  DECLARE_NON_COPYABLE(NodeNeuron);
};

}  // namespace neunet
