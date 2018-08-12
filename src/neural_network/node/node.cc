//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/node.h"

namespace neunet {

Node::Node(Layer* layer) : layer_(layer) {
}

Node::~Node() {
}

Layer* Node::layer() {
  return layer_;
}

}  // namespace neunet
