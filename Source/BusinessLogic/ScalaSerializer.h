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
        NoTunigValuesFound = 13,
        LessTuningValuesThanSize = 14,
        MoreTuningValuesThanSize = 15,

        // Errors
        InvalidScalaFile = -11,
        InvalidTuningValue = -12,

    };

    static DeserializationResult deserialize(const StringArray& stringArray, TuningTable& tuningTable);
};
