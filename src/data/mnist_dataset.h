//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <memory>
#include <vector>

#include <stdio.h>
#include <stdint.h>

#include "data/dataset_reader.h"
#include "data/mnist_dataset_file.h"

namespace data {

class MNISTDataset : public DatasetReader {
 public:
  MNISTDataset(const wchar_t* input_ubyte_idx_filepath,
               const wchar_t* output_ubyte_idx_filepath);
  ~MNISTDataset();

  bool ReadNext();

  // DatasetReader overrides:
  const DatasetFileReader* GetInputReader() const override;
  const DatasetFileReader* GetOutputReader() const override;

 private:
   MNISTDatasetFile input_reader_;
   MNISTDatasetFile output_reader_;
};

}  // namespace data
