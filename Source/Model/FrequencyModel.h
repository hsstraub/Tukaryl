/*
  ==============================================================================

    FrequencyModel.h
    Created: 11 May 2025 11:33:41am
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../HajuLib/RationalNumber.h"

// A pitch frequency, specified  is either as a frequency ratio or as number of cents.
class FrequencyModel
{
public:
    FrequencyModel(RationalNumber intervalRatio);
    FrequencyModel(float valueInCents);


    double getValueInCents() const;
    double getValueAsFrequencyRatio() const;
    juce::String toString();

private:
    std::variant<RationalNumber, float> value;
};

