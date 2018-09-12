//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "data/mnist_dataset.h"

namespace data {

MNISTDataset::MNISTDataset(const wchar_t* input_ubyte_idx_filepath,
                           const wchar_t* output_ubyte_idx_filepath)
    : input_reader_(input_ubyte_idx_filepath),
      output_reader_(output_ubyte_idx_filepath) {
}

MNISTDataset::~MNISTDataset() {
}

bool MNISTDataset::ReadNext() {
  // TODO: test code.
  const uint8_t curr_label = output_reader_.GetDataBuffer()[0];
  do {
    if (!(input_reader_.ReadNext() && output_reader_.ReadNext()))
      return false;
  } while(output_reader_.GetDataBuffer()[0] != curr_label);
  return true;
  //return input_reader_.ReadNext() && output_reader_.ReadNext();
}

const DatasetFileReader* MNISTDataset::GetInputReader() const {
  return &input_reader_;
}

const DatasetFileReader* MNISTDataset::GetOutputReader() const {
  return &output_reader_;
}

}  // namespace data
