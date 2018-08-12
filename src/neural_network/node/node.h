//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"

namespace neunet {

class Layer;

class Node {
 public:
  Node(Layer* layer);
  ~Node();

  float value() = 0;

  Layer* layer();

 private:
  Layer* layer_;

  DECLARE_NON_COPYABLE(Node);
};

}  // namespace neunet
