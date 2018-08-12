//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/neuron_node_synapse.h"

#include "neural_network/constants.h"

namespace neunet {

NeuronNodeSynapse::NeuronNodeSynapse(Node* pre_node)
    : pre_node_(pre_node),
      weight_(kDefaultInitialNeuronNodeSynapseWeight) {
}

NeuronNodeSynapse::~NeuronNodeSynapse() {
}

float NeuronNodeSynapse::weight() const {
  return weight_;
}

void NeuronNodeSynapse::set_weight(float value) {
  weight_ = value;
}

float NeuronNodeSynapse::CalculateValue() {
  return pre_node_->CurrentValue() * weight_;
}

}  // namespace neunet
