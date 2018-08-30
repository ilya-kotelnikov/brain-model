//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

namespace data {

struct DatasetValueCast {
  virtual float AsFloat(uint8_t ubyte_value) const = 0;
};

}  // namespace data
