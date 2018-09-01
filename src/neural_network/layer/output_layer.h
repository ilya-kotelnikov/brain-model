﻿//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

#include "neural_network/layer/generic_layer.h"
#include "neural_network/node/output_node.h"

namespace data {
struct DatasetFileReader;
}

namespace neunet {

class OutputLayer : public GenericLayer<OutputNode> {
 public:
  OutputLayer(uint32_t output_count);
  ~OutputLayer();

  void BindToLastNeuronLayer(Layer* last_neuron_layer);
  void BindToDataset(const data::DatasetFileReader* dataset);
  void Report();

  // Layer overrides:
  void Calculate() override;

 private:
  const data::DatasetFileReader* dataset_;

  DECLARE_NON_COPYABLE(OutputLayer);
};

}  // namespace neunet
