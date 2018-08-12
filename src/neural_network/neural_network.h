//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <memory>
#include <vector>

#include <stdint.h>

#include "base/macros.h"
#include "neural_network/constants.h"

namespace neunet {

class InputLayer;
class NeuronLayer;
class OutputLayer;

class NeuralNetwork {
 public:
  NeuralNetwork(uint32 input_count, uint32 output_count);
  ~NeuralNetwork();

  NeuronLayer* AddNeuronLayer(
      uint32 neuron_count = kDefaultNeuronPerLayerCount);
  void GenerateSynapses();

 private:
  std::unique_ptr<InputLayer> input_layer_;
  std::vector<std::unique_ptr<NeuronLayer>> neuron_layers_;
  std::unique_ptr<OutputLayer> output_layer_;

  DECLARE_NON_COPYABLE(NeuralNetwork);
};

}  // namespace neunet
