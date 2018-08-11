//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"

namespace neunet {

class NeuralNetwork {
 public:
  NeuralNetwork();
  ~NeuralNetwork();

 private:
  DECLARE_NON_COPYABLE(NeuralNetwork);
};

}  // namespace neunet
