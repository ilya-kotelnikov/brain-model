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
    uint32_t synapses_per_neuron_count;
    float spike_treshold_value;
    float spike_value;
    int max_age_for_spontenious_spike;
    float spontenious_spike_probability;

    NeuronNodeParams();
  };

 public:
  NeuronLayer(Delegate* delegate, uint32_t neuron_count);
  ~NeuronLayer();

  const NeuronNodeParams& neuron_node_params() const;

  void GenerateSynapses(Layer* pre_layer);
  void Visualize() const;

 private:
  NeuronNodeParams neuron_node_params_;

  DECLARE_NON_COPYABLE(NeuronLayer);
};

}  // namespace neunet

