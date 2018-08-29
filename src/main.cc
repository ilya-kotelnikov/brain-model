//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include <vector>

#include <stdlib.h>
#include <time.h>

#include "neural_network/layer/output_layer.h"
#include "neural_network/neural_network.h"

int main() {
  srand(unsigned(time(nullptr)));

  neunet::NeuralNetwork nnet(3, 2);

  nnet.AddNeuronLayer();
  nnet.AddNeuronLayer();

  nnet.GenerateSynapses();

  nnet.Calculate();

  nnet.output_layer()->Report();

  return 0;
}
