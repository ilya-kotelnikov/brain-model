//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#pragma once

#include <stdint.h>

namespace neunet {

constexpr uint32_t kDefaultNeuronPerLayerCount = 100;
constexpr uint32_t kDefaultSynapsesPerNeuronCount = 20;

constexpr float kDefaultInitialNeuronNodeSynapseWeight = 0.;
constexpr float kDefaultNeuronNodeSynapseWeightStep = 0.01;
constexpr float kDefaultNeuronNodeSynapseWeightMaximum = 1.;
constexpr float kDefaultNeuronSpikeTresholdValue = 0.05;
constexpr float kDefaultNeuronSpikeValue = 1.;
constexpr float kDefaultNeuronMaxAgeForSponteniousSpike = 100000;
constexpr float kDefaultNeuronSponteniousSpikeProbability = 0.20;

}  // namespace neunet
