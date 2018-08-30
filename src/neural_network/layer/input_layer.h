//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

#include "data/dataset_reader.h"
#include "neural_network/layer/generic_layer.h"
#include "neural_network/node/input_node.h"

namespace neunet {

class InputLayer : public GenericLayer<InputNode> {
 public:
  InputLayer(uint32_t input_count);
  ~InputLayer();

  void BindToDataset(const data::DatasetReader* dataset);
  void Report();

  // Interface for nodes:
  float GetNodeValueFromDataset(uint32_t node_index) const;

 private:
  const data::DatasetReader* dataset_;

  DECLARE_NON_COPYABLE(InputLayer);
};

}  // namespace neunet
