//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"

namespace neunet {

class Layer {
 public:
  Layer();
  ~Layer();

 private:
  DECLARE_NON_COPYABLE(Layer);
};

}  // namespace neunet
