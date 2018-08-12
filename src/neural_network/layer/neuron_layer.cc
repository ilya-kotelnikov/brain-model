//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/neuron_layer.h"

#include "neural_network/constants.h"
#include "neural_network/node/neuron_node.h"

namespace neunet {

NeuronLayer::NeuronLayer(uint32 neuron_count)
    : GenericLayer<NeuronNode>(neuron_count),
      synapses_per_neuron_count_(kDefaultSynapsesPerNeuronCount) {
}

NeuronLayer::~NeuronLayer() {
}

uint32 NeuronLayer::synapses_per_neuron_count() {
  return synapses_per_neuron_count_;
}

void NeuronLayer::set_synapses_per_neuron_count(uint32 value) {
  synapses_per_neuron_count_ = value;
}

void NeuronLayer::GenerateSynapses(Layer* pre_layer) {
  //TODO: impl!
}

}  // namespace neunet
