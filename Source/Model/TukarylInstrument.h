/*
  ==============================================================================

    TukarylInstrument.h
    Created: 13 Apr 2025 7:39:30pm
    Author:  hsstraub

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "IntervalModel.h"
#include "TuningTable.h"

struct TukarylInstrument
{
    IntervalModel baseFrequency = IntervalModel::perfectPrime();
    unsigned short baseOscLevel;

    IntervalModel partial1Frequency;
    unsigned short partial1Level;

    TuningTable tuningTable = TuningTable::standard12Edo();

    ADSR::Parameters mainEnvelope = ADSR::Parameters(0.1f, 0.1f, 1.0f, 0.1f);

    TukarylInstrument(
        unsigned short newBaseOscLevel,
        IntervalModel newPartial1Frequency,
        unsigned short newPartial1Level,
        TuningTable newTuningTable,
        ADSR::Parameters newMainEnvelope)
    : baseOscLevel(newBaseOscLevel)
    , partial1Frequency(newPartial1Frequency)
    , partial1Level(newPartial1Level)
    , tuningTable(newTuningTable)
    , mainEnvelope(newMainEnvelope)
    {
    }
};
