//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"

namespace neunet {

class Node;

class NeuronNodeSynapse {
 public:
  NeuronNodeSynapse(Node* pre_node);
  ~NeuronNodeSynapse();

  float weight() const;
  void set_weight(float value);

  float CalculateValue();

 private:
  Node* pre_node_;
  float weight_;

  DECLARE_NON_COPYABLE(NeuronNodeSynapse);
};

}  // namespace neunet
