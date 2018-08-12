//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

#include "base/macros.h"
#include "neural_network/layer/generic_layer.h"
#include "neural_network/node/neuron_node.h"

namespace neunet {

class NeuronLayer : public GenericLayer<NeuronNode> {
 public:
  struct NeuronNodeParams {
    uint32 synapses_per_neuron_count;
    float spike_treshold_value;
    float spike_value;

    NeuronNodeParams();
  };

 public:
  NeuronLayer(uint32 neuron_count);
  ~NeuronLayer();

  const NeuronNodeParams& neuron_node_params() const; 

  void GenerateSynapses(Layer* pre_layer);

 private:
  NeuronNodeParams neuron_node_params_;

  DECLARE_NON_COPYABLE(NeuronLayer);
};

}  // namespace neunet

