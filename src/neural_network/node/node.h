//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

#include "base/macros.h"

namespace neunet {

class Layer;

class Node {
 public:
  Node(Layer* layer, uint32_t index);
  ~Node();

  virtual void UpdateValue() = 0;
  virtual float CurrentValue() = 0;

 protected:
  Layer* layer_;
  uint32_t index_;

 private:
  DECLARE_NON_COPYABLE(Node);
};

}  // namespace neunet
