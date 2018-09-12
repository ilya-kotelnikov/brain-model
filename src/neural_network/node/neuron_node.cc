//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/node/neuron_node.h"

#include <iostream>

#include <stdint.h>

#include "neural_network/constants.h"
#include "neural_network/layer/neuron_layer.h"
#include "neural_network/node/neuron_node_synapse.h"

namespace neunet {

NeuronNode::NeuronNode(Layer* layer, uint32_t index)
    : Node(layer, index), current_value_(0.), age_(0) {
}

NeuronNode::~NeuronNode() {
}

void NeuronNode::AddSynapse(Node* pre_node) {
  synapses_.emplace_back(std::make_unique<NeuronNodeSynapse>(pre_node));
}

void NeuronNode::Visualize() const {
  std::cout << "age=" << age_ << ", value=" << current_value_ << ", "
            << synapses_.size() << " synapses (";
  for (const auto& synapse : synapses_) {
    std::cout << synapse->weight() << ",";
  }
  std::cout << ")";
}

void NeuronNode::UpdateValue() {
  const NeuronLayer::NeuronNodeParams& params_by_layer =
      static_cast<NeuronLayer*>(layer_)->neuron_node_params();

  // Sum pre-nodes' values taking into account synapses' weights and produce
  // a spike if the treshold has been reached.
  float summary_pre_node_value = 0.;
  float summary_synapses_value = 0.;
  for (const auto& synapse : synapses_) {
    const float pre_node_value = synapse->pre_node_value();
    summary_pre_node_value += pre_node_value;
    summary_synapses_value += pre_node_value * synapse->weight();
  }
  if (summary_pre_node_value == 0.) {
    // No active inputs for this node: skip any further logic - we count the
    // neuron resting i.e. its age doesn't grow.
    current_value_ = 0.;
    return;
  }
  bool trigger_spike =
      (summary_synapses_value > params_by_layer.spike_treshold_value);
  ++age_;

  // A special training rule: a neuron may still produce a spike even if
  // the treshold has not been reached - it may do it spontaniously with dynamic
  // probability which depends on its |age_|.
  const bool is_training = layer_->delegate()->IsTraining();
  if (!trigger_spike && is_training &&
      age_ <= params_by_layer.max_age_for_spontenious_spike) {
    trigger_spike = (float(rand()) / RAND_MAX <
                        params_by_layer.spontenious_spike_probability *
                            0.5 * (1. + 1. / age_));
  }

  if (!trigger_spike) {
    current_value_ = 0.;
    return;
  }

  current_value_ = params_by_layer.spike_value;

  if (is_training) {
    // Update synapses from active inputs: increase the weights as they lead
    // to a spike - this way the pattern recognition becomes stronger.
    for (const auto& synapse : synapses_) {
      if (synapse->pre_node_value() > 0. &&
          synapse->weight() < kDefaultNeuronNodeSynapseWeightMaximum) {
        float new_weight =
            synapse->weight() + kDefaultNeuronNodeSynapseWeightStep;
        if (new_weight > kDefaultNeuronNodeSynapseWeightMaximum)
          new_weight = kDefaultNeuronNodeSynapseWeightMaximum;
        synapse->set_weight(new_weight);
      }
    }
  }
}

float NeuronNode::CurrentValue() {
  return current_value_;
}

}  // namespace neunet
