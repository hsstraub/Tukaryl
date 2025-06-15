/*
  ==============================================================================

    ScalaSerializer.cpp
    Created: 14 Jun 2025 10:49:30am
    Author:  hsstraub

  ==============================================================================
*/

#include "ScalaSerializer.h"

ScalaSerializer::DeserializationResult ScalaSerializer::deserialize(const StringArray& stringArray, TuningTable& tuningTable)
{
    StringArray valuesWithoutComments;

    // Omit empty and comment lines
    for ( int i = 0; i < stringArray.size(); i++)
    {
        if (stringArray[i].indexOf("!") < 0 && !stringArray[i].trim().isEmpty())
        {
            valuesWithoutComments.add(stringArray[i]);
        }
    }

    if (valuesWithoutComments.size() < 2)
    {
        return DeserializationResult::InvalidScalaFile;
    }

    if (valuesWithoutComments.size() < 3)
    {
        return DeserializationResult::NoTunigValuesFound;
    }

    auto iterator = valuesWithoutComments.begin();

    auto description = *iterator;
    iterator++;
    size_t scalaSize = iterator->getIntValue();
    iterator++;

    tuningTable.clear();
    tuningTable.setDescription(description);

    for (; iterator != valuesWithoutComments.end(); iterator++)
    {
        auto rationalSeparator = iterator->indexOfChar(0,'/');
        if (rationalSeparator >= 0)
        {
            auto newNumerator = iterator->substring(0, rationalSeparator).getIntValue();
            auto newDenominator = iterator->substring(rationalSeparator+1).getIntValue();

            if (newNumerator <= 0 || newDenominator <= 0)
            {
                return DeserializationResult::InvalidTuningValue;
            }

            tuningTable.push_back(IntervalModel(RationalNumber(newNumerator, newDenominator)));
        }
        else {
            tuningTable.push_back(IntervalModel(iterator->getFloatValue()));
        }
    }

    // Errors
    if (tuningTable.periodInterval().getValueInCents() == 0.0)
    {
        return DeserializationResult::EmptyPeriodInterval;
    }

    // Warnings
    if (tuningTable.size() < scalaSize)
    {
        return DeserializationResult::LessTuningValuesThanSize;
    }

    if (tuningTable.size() > scalaSize)
    {
        return DeserializationResult::MoreTuningValuesThanSize;
    }

    return DeserializationResult::OK;
}

