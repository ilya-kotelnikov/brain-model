//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"
#include "neural_network/node/node.h"

namespace neunet {

class OutputNode : public Node {
 public:
  OutputNode(Layer* layer, Node* last_neuron_layer_node);
  ~OutputNode();

  // Node implementation:
  void UpdateValue() override;
  float CurrentValue() override;

 private:
  Node* last_neuron_layer_node_;

  DECLARE_NON_COPYABLE(OutputNode);
};

}  // namespace neunet
