//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "neural_network/layer/generic_layer.h"
#include "neural_network/node/input_node.h"

namespace neunet {

using InputLayer = GenericLayer<InputNode>;

}  // namespace neunet
