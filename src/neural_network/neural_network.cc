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

#include "data/dataset_reader.h"
#include "neural_network/layer/input_layer.h"
#include "neural_network/layer/neuron_layer.h"
#include "neural_network/layer/output_layer.h"

namespace neunet {

NeuralNetwork::NeuralNetwork(uint32_t input_count, uint32_t output_count) {
  input_layer_ = std::make_unique<InputLayer>(input_count);
  output_layer_ = std::make_unique<OutputLayer>(output_count);
}

NeuralNetwork::~NeuralNetwork() {
}

void NeuralNetwork::BindToDataset(const data::DatasetReader* dataset) {
  input_layer_->BindToDataset(dataset->GetInputReader());
  output_layer_->BindToDataset(dataset->GetOutputReader());
}

InputLayer* NeuralNetwork::input_layer() const {
  return input_layer_.get();
}

OutputLayer* NeuralNetwork::output_layer() const {
  return output_layer_.get();
}

NeuronLayer* NeuralNetwork::AddNeuronLayer(uint32_t neuron_count) {
  neuron_layers_.emplace_back(std::make_unique<NeuronLayer>(neuron_count));
  return neuron_layers_.back().get();
}

void NeuralNetwork::GenerateSynapses() {
  // Add a special pre-output neuron layer with certain number of nodes suitable
  // for classifying the outputs - output layer will analyze values of this
  // neuron layer and associate output patterns with output classes.
  output_layer_->BindToLastNeuronLayer(
      AddNeuronLayer(OutputLayer::kMaxLastLayerNeuronCount));

  auto i_neuron_layer = neuron_layers_.begin();
  (*i_neuron_layer)->GenerateSynapses(input_layer_.get());
  while (++i_neuron_layer != neuron_layers_.end())
    (*i_neuron_layer)->GenerateSynapses((i_neuron_layer - 1)->get());
}

void NeuralNetwork::Calculate() {
  input_layer_->Calculate();

  for (auto& neuron_layer : neuron_layers_)
    neuron_layer->Calculate();

  output_layer_->Calculate();
}

}  // namespace neunet
