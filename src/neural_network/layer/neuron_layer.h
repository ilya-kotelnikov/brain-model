//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "base/macros.h"
#include "neural_network/layer/generic_layer.h"
#include "neural_network/node/neuron_node.h"

namespace neunet {

class NeuronLayer : public GenericLayer<NeuronNode> {
 public:
  NeuronLayer(uint32 neuron_count);
  ~NeuronLayer();  

  uint32 synapses_per_neuron_count();
  void set_synapses_per_neuron_count(uint32 value);

  void GenerateSynapses(Layer* pre_layer);

 private:
  uint32 synapses_per_neuron_count_;

  DECLARE_NON_COPYABLE(NeuronLayer);
};

}  // namespace neunet
