//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include "data/mnist_dataset_file.h"

#include <array>
#include <stdexcept>

#include <assert.h>
#include <stdint.h>

namespace data {

MNISTDatasetFile::MNISTDatasetFile(const wchar_t* ubyte_idx_filepath)
    : ubyte_idx_file_(nullptr), data_count_(0), data_size_(0) {
  errno_t res = _wfopen_s(&ubyte_idx_file_, ubyte_idx_filepath, L"rb");
  if (res != 0)
    throw std::runtime_error("MNISTDatasetFile can't open the ubyte idx file");

  struct {
    uint16_t zero;
    uint8_t data_type_code;
    uint8_t dimension_count;
  } idx_file_header;
  size_t read_count =
      fread(&idx_file_header, sizeof(idx_file_header), 1, ubyte_idx_file_);
  if (read_count != 1) {
    throw std::runtime_error(
        "MNISTDatasetFile can't read the ubyte idx file's header");
  }
  if (idx_file_header.zero != 0 || idx_file_header.data_type_code != 8 ||
      idx_file_header.dimension_count == 0) {
    throw std::runtime_error(
        "MNISTDatasetFile ubyte idx file's header is invalid");
  }

  // Read dimensions' sizes then the data starts.
  // We treat any idx file as a vector where the first dimension is the number
  // of elements and all the other dimensions are multiplied and give the
  // element size.
  data_count_ = ReadBigEndeanUint32();
  data_size_ = 1;
  for (uint8_t i = 1; i < idx_file_header.dimension_count; ++i)
    data_size_ *= ReadBigEndeanUint32();

  // Allocate buffer for one complete data entry.
  data_read_next_.resize(data_size_);
}

MNISTDatasetFile::~MNISTDatasetFile() {
  if (ubyte_idx_file_)
    fclose(ubyte_idx_file_);
}

bool MNISTDatasetFile::ReadNext() {
  assert(data_read_next_.size() == data_size_);
  size_t read_count =
      fread(&data_read_next_.front(), sizeof(uint8_t), data_size_,
            ubyte_idx_file_);
  if (read_count == 0)
    return false;
  if (read_count != data_size_) {
    throw std::runtime_error(
        "MNISTDatasetFile the ubyte idx file has invalid data");
  }
  return true;
}

uint32_t MNISTDatasetFile::GetDataSize() const {
  return data_size_;
}

const uint8_t* MNISTDatasetFile::GetDataBuffer() const {
  return &data_read_next_.front();
}

const DatasetValueCast& MNISTDatasetFile::GetDataValueCast() const {
  return data_value_cast_;
}

uint32_t MNISTDatasetFile::ReadBigEndeanUint32() {
  std::array<uint8_t, 4> uint32_bytes;
  size_t read_count =
      fread(uint32_bytes.data(), sizeof(uint8_t), uint32_bytes.size(),
            ubyte_idx_file_);
  if (read_count != uint32_bytes.size()) {
    throw std::runtime_error(
        "MNISTDatasetFile the ubyte idx file has invalid format");
  }

  return (uint32_t(uint32_bytes[0]) << 24) |
         (uint32_t(uint32_bytes[1]) << 16) |
         (uint32_t(uint32_bytes[2]) <<  8) |
         (uint32_t(uint32_bytes[3]));
}

}  // namespace data
