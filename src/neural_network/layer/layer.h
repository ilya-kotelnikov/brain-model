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

class Node;

class Layer {
 public:
  Layer();
  ~Layer();

  virtual uint32 count() const = 0;
  virtual Node* node(uint32 i) = 0;

 private:
  DECLARE_NON_COPYABLE(Layer);
};

}  // namespace neunet
