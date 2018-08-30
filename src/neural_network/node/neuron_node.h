//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <memory>
#include <vector>

#include <stdint.h>

#include "base/macros.h"
#include "neural_network/node/node.h"

namespace neunet {

class NeuronNodeSynapse;

class NeuronNode : public Node {
 public:
  NeuronNode(Layer* layer, uint32_t index);
  ~NeuronNode();

  void AddSynapse(Node* pre_node);

  // Node implementation:
  void UpdateValue() override;
  float CurrentValue() override;

 private:
  std::vector<std::unique_ptr<NeuronNodeSynapse>> synapses_;

  float current_value_;

  DECLARE_NON_COPYABLE(NeuronNode);
};

}  // namespace neunet
