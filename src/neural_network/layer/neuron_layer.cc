﻿//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/neuron_layer.h"

#include <memory>

#include <assert.h>
#include <stdint.h>

#include "neural_network/constants.h"
#include "neural_network/node/neuron_node.h"

namespace neunet {

NeuronLayer::NeuronLayer(uint32 neuron_count)
    : synapses_per_neuron_count_(kDefaultSynapsesPerNeuronCount) {
  for (uint32 i = 0; i < output_count; ++i)
    neurons_.emplace_back(std::make_unique<NeuronNode>(this));
}

NeuronLayer::~NeuronLayer() {
}

uint32 NeuronLayer::synapses_per_neuron_count() {
  return synapses_per_neuron_count_;
}

void NeuronLayer::set_synapses_per_neuron_count(uint32 value) {
  synapses_per_neuron_count_ = value;
}

uint32 NeuronLayer::count() const {
  return neurons_.size();
}

Node* NeuronLayer::node(uint32 i) {
  assert(i < neurons_.size());
  return neurons_.at(i).get();
}

void NeuronLayer::GenerateSynapses(Layer* pre_layer) {
  //TODO: impl!
}

}  // namespace neunet
