//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include <iostream>
#include <exception>
#include <vector>

#include <stdlib.h>
#include <time.h>

#include "data/mnist_dataset.h"
#include "neural_network/layer/input_layer.h"
#include "neural_network/layer/output_layer.h"
#include "neural_network/neural_network.h"

int main() {
  srand(unsigned(time(nullptr)));

  try {
    neunet::NeuralNetwork nnet(28 * 28, 10);

    nnet.AddNeuronLayer();
    nnet.AddNeuronLayer();

    nnet.GenerateSynapses();

    data::MNISTDataset dataset(L"../data/mnist/train-images.idx3-ubyte",
                               L"../data/mnist/train-labels.idx1-ubyte");
    nnet.BindToDataset(&dataset);
    for (size_t i = 0; i < 1000 && dataset.ReadNext(); ++i) {
      if (i % 100 == 0)
        std::cout << "Processing dataset record #" << i << "..." << std::endl;
      nnet.Calculate();
    }
    std::cout << "Analyzing results..." << std::endl;
    nnet.output_layer()->AnalyzeAndReport();
  } catch(const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
