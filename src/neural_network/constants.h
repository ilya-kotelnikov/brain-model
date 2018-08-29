//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

namespace neunet {

constexpr uint32_t kDefaultNeuronPerLayerCount = 1000;
constexpr uint32_t kDefaultSynapsesPerNeuronCount = 10;

constexpr float kDefaultInitialNeuronNodeSynapseWeight = 0.;
constexpr float kDefaultNeuronSpikeTresholdValue = 0.05;
constexpr float kDefaultNeuronSpikeValue = 1.;

}  // namespace neunet
