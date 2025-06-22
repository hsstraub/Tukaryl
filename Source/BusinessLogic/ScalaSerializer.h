/*
  ==============================================================================

    ScalaSerializer.h
    Created: 14 Jun 2025 10:49:30am
    Author:  hsstraub

  ==============================================================================
*/

#pragma once
#include "../Model/TuningTable.h"
#include "../Model/IntervalModel.h"

// Serializing of Scala files
class ScalaSerializer
{
public:
    enum DeserializationResult
    {
        OK = 0,

        // Warnings
        SizeSpecifiedAsZero = 12,
        LessTuningValuesThanSize = 13,
        MoreTuningValuesThanSize = 14,

        // Errors
        InvalidScalaFile = -11,
        NoTunigValuesFound = -12,
        InvalidTuningValue = -13,
        NonAscendingPeriodInterval = -14,

    };

    static bool deserializationResultIsError(DeserializationResult deserializationResult) { return deserializationResult < 0; }

    static DeserializationResult deserialize(const StringArray& stringArray, TuningTable& tuningTable);
};
