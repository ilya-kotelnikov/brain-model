//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/neuron_layer.h"

#include <stdint.h>

#include "neural_network/constants.h"
#include "neural_network/node/neuron_node.h"

namespace neunet {

NeuronLayer::NeuronNodeParams::NeuronNodeParams()
   : synapses_per_neuron_count(kDefaultSynapsesPerNeuronCount),
     spike_treshold_value(kDefaultNeuronSpikeTresholdValue),
     spike_value(kDefaultNeuronSpikeValue) {
}

NeuronLayer::NeuronLayer(uint32 neuron_count)
    : GenericLayer<NeuronNode>(neuron_count) {
}

NeuronLayer::~NeuronLayer() {
}

const NeuronLayer::NeuronNodeParams& NeuronLayer::neuron_node_params() const {
  return neuron_node_params_;
}

void NeuronLayer::GenerateSynapses(Layer* pre_layer) {
  //TODO: impl!
}

}  // namespace neunet
