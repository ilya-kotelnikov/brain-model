//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/neural_network.h"

#include <memory>

#include <assert.h>
#include <stdint.h>

#include "neural_network/layer/input_layer.h"
#include "neural_network/layer/neuron_layer.h"
#include "neural_network/layer/output_layer.h"

namespace neunet {

NeuralNetwork::NeuralNetwork(uint32 input_count, uint32 output_count) {
  input_layer_ = std::make_unique<InputLayer>(input_count);
  output_layer_ = std::make_unique<OutputLayer>(output_count);
}

NeuralNetwork::~NeuralNetwork() {
}

NeuronLayer* NeuralNetwork::AddNeuronLayer(uint32 neuron_count) {
  neuron_layers_.emplace_back(std::make_unique<NeuronLayer>(neuron_count));
  return neuron_layers_.back().get();
}

void NeuralNetwork::GenerateSynapses() {
  assert(!neuron_layers_.empty());
  assert(neuron_layers_.back().count() == output_layer_.count());

  //TODO: impl!
}

}  // namespace neunet

