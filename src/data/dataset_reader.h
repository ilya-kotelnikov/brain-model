﻿//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

namespace data {

struct DatasetFileReader;

struct DatasetReader {
  virtual const DatasetFileReader* GetInputReader() const = 0;
  virtual const DatasetFileReader* GetOutputReader() const = 0;
};

}  // namespace data
