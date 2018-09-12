//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

#include "base/macros.h"

namespace neunet {

class Node;

class Layer {
 public:
  struct Delegate {
    virtual bool IsTraining() const = 0;
  };

  Layer(Delegate* delegate);
  ~Layer();

  Delegate* delegate();

  virtual uint32_t count() const = 0;
  virtual Node* node(uint32_t i) = 0;

  virtual void Calculate();

 private:
  Delegate* delegate_;

  DECLARE_NON_COPYABLE(Layer);
};

}  // namespace neunet
