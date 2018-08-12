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
#include "neural_network/layer/layer.h"

namespace neunet {

class NeuronNode;

class NeuronLayer : public Layer {
 public:
  NeuronLayer(uint32 neuron_count);
  ~NeuronLayer();  

  uint32 synapses_per_neuron_count();
  void set_synapses_per_neuron_count(uint32 value);

  uint32 count() const override;
  Node* node(uint32 i) override;

  void GenerateSynapses(Layer* pre_layer);

 private:
  uint32 synapses_per_neuron_count_;

  std::vector<std::unique_ptr<NeuronNode>> neurons_;

  DECLARE_NON_COPYABLE(NeuronLayer);
};

}  // namespace neunet
