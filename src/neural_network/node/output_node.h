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

class OutputNode : public Node {
 public:
  OutputNode();
  ~OutputNode();

 private:
  DECLARE_NON_COPYABLE(OutputNode);
};

}  // namespace neunet