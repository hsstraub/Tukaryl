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

    FrequencyModel add(FrequencyModel const& second) const;
    FrequencyModel getInverse() const;

    static FrequencyModel perfectPrime() { return FrequencyModel(RationalNumber(1, 1)); }
    static FrequencyModel octave() { return FrequencyModel(RationalNumber(2, 1)); }
    static FrequencyModel doubleOctave() { return FrequencyModel(RationalNumber(4, 1)); }

private:
    std::variant<RationalNumber, float> value;
};

