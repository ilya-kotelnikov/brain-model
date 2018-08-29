//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/layer.h"

#include "neural_network/node/node.h"

namespace neunet {

Layer::Layer() {
}

Layer::~Layer() {
}

void Layer::Calculate() {
  for (uint32_t i = 0; i < count(); ++i)
    node(i)->UpdateValue();
}

}  // namespace neunet
