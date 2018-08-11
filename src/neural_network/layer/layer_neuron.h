//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"
#include "neural_network/layer/layer.h"

namespace neunet {

class LayerNeuron : public Layer {
 public:
  LayerNeuron();
  ~LayerNeuron();

 private:
  DECLARE_NON_COPYABLE(LayerNeuron);
};

}  // namespace neunet
