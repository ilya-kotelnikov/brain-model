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

class OutputLayer : public Layer {
 public:
  OutputLayer();
  ~OutputLayer();

 private:
  DECLARE_NON_COPYABLE(OutputLayer);
};

}  // namespace neunet
