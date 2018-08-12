//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "neural_network/layer/generic_layer.h"
#include "neural_network/node/output_node.h"

namespace neunet {

class OutputLayer : public GenericLayer<OutputNode> {
 public:
  OutputLayer(uint32 output_count, Layer* last_neuron_layer);
  ~OutputLayer();

  Layer* last_neuron_layer();

 private:
  Layer* last_neuron_layer_;

  DECLARE_NON_COPYABLE(OutputLayer);
};

}  // namespace neunet
