//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

namespace data {

struct DatasetValueCast;

struct DatasetFileReader {
  virtual uint32_t GetDataCount() const = 0;
  virtual uint32_t GetDataSize() const = 0;
  virtual const uint8_t* GetDataBuffer() const = 0;
  virtual const DatasetValueCast& GetDataValueCast() const = 0;
};

}  // namespace data
