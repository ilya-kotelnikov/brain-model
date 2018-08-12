//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/neuron_node.h"

#include "neural_network/layer/neuron_layer.h"
#include "neural_network/node/neuron_node_synapse.h"

namespace neunet {

NeuronNode::NeuronNode(Layer* layer) : Node(layer), current_value_(0.) {
}

NeuronNode::~NeuronNode() {
}

void NeuronNode::AddSynapse(Node* pre_node) {
  synapses_.emplace_back(std::make_unique<NeuronNodeSynapse>(pre_node));
}

void NeuronNode::UpdateValue() {
  const NeuronLayer::NeuronNodeParams& params_by_layer =
      static_cast<NeuronLayer*>(layer())->neuron_node_params();

  // Sum pre-nodes' values taking into account synapses' weights and produce
  // a spike if the treshold has been reached.
  float summary_synapses_value = 0.;
  for (const auto& synapse : synapses_) {
    summary_synapses_value += synapse->CalculateValue();
  }

  current_value_ =
      (summary_synapses_value > params_by_layer.spike_treshold_value)
          ? params_by_layer.spike_value
          : 0.;
}

float NeuronNode::CurrentValue() {
  return current_value_;
}

}  // namespace neunet
