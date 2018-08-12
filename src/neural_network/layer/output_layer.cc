//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "neural_network/layer/output_layer.h"

#include <assert.h>
#include <stdint.h>

#include "neural_network/node/output_node.h"

namespace neunet {

OutputLayer::OutputLayer(uint32 output_count, Layer* last_neuron_layer)
    : GenericLayer<OutputNode>(output_count),
      last_neuron_layer_(last_neuron_layer) {
  assert(output_count == last_neuron_layer->count());
}

OutputLayer::~OutputLayer() {
}

Layer* OutputLayer::last_neuron_layer() {
  return last_neuron_layer_;
}

}  // namespace neunet
