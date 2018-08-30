//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include "data/dataset_value_cast.h"

namespace data {

struct MNISTDatasetValueCast : public DatasetValueCast {
  float AsFloat(uint8_t ubyte_value) const override {
    constexpr float kScaleFactor = 1. / 255.;
    return ubyte_value * kScaleFactor;
  }
};

}  // namespace data
