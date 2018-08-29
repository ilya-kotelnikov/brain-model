//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/neuron_layer.h"

#include <stdint.h>
#include <stdlib.h>

#include "neural_network/constants.h"
#include "neural_network/node/neuron_node.h"

namespace neunet {

NeuronLayer::NeuronNodeParams::NeuronNodeParams()
   : synapses_per_neuron_count(kDefaultSynapsesPerNeuronCount),
     spike_treshold_value(kDefaultNeuronSpikeTresholdValue),
     spike_value(kDefaultNeuronSpikeValue) {
}

NeuronLayer::NeuronLayer(uint32_t neuron_count)
    : GenericLayer<NeuronNode>(neuron_count) {
}

NeuronLayer::~NeuronLayer() {
}

const NeuronLayer::NeuronNodeParams& NeuronLayer::neuron_node_params() const {
  return neuron_node_params_;
}

void NeuronLayer::GenerateSynapses(Layer* pre_layer) {
  const uint32_t pre_nodes_count = pre_layer->count();
  const uint32_t synapses_per_neuron_count =
      neuron_node_params_.synapses_per_neuron_count;

  for (auto& node : nodes_) {
    for (uint32_t i = 0; i < synapses_per_neuron_count; ++i) {
      const uint32_t pre_node_index = uint32_t(rand() % pre_nodes_count);
      node->AddSynapse(pre_layer->node(pre_node_index));
    }
  }
}

}  // namespace neunet
