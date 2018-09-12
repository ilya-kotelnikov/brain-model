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
    // Construct.
    neunet::NeuralNetwork nnet(28 * 28, 10);

    nnet.AddNeuronLayer(50);
    //nnet.AddNeuronLayer(250);
    //nnet.AddNeuronLayer(100);

    nnet.GenerateSynapses();
    nnet.Visualize();

    // Train.
    auto run_nnet_on_training_dataset = [&nnet](int k) {
      data::MNISTDataset dataset(L"../data/mnist/train-images.idx3-ubyte",
                                 L"../data/mnist/train-labels.idx1-ubyte");
      nnet.BindToDataset(&dataset);
      for (size_t i = 0; dataset.ReadNext() && i < 3; ++i) {
        //if (i % 1000 == 0) {
          std::cout << "[Train #" << k << "] Processing dataset record #"
                    << i << "..." << std::endl;
        //}
        nnet.Calculate();
        //if (i % 1000 == 0) {
          nnet.Visualize();
        //}
      }
      std::cout << "[Train #" << k << "] Analyzing results..." << std::endl;
      nnet.Visualize();
    };
    for (int k = 0; k < 2; ++k)
      run_nnet_on_training_dataset(k);
    //nnet.Maturate();
    //run_nnet_on_training_dataset(-1);

    // Test.
    // TODO
  } catch(const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
