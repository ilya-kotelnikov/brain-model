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
#include "data/mnist_dataset_value_cast.h"

namespace data {

class MNISTDataset : public DatasetReader {
 public:
  MNISTDataset(const wchar_t* ubyte_idx_filepath);
  ~MNISTDataset();

  bool ReadNext();

  // DatasetReader overrides:
  uint32_t GetDataSize() const override;
  const uint8_t* GetDataBuffer() const override;
  const DatasetValueCast& GetDataValueCast() const override;

 protected:
  FILE* ubyte_idx_file_;
  uint32_t data_count_;
  uint32_t data_size_;
  std::vector<uint8_t> data_read_next_;
  MNISTDatasetValueCast data_value_cast_;

  uint32_t ReadBigEndeanUint32();
};

}  // namespace data
