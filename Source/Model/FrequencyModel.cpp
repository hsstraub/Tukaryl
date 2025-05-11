/*
  ==============================================================================

    FrequencyModel.cpp
    Created: 11 May 2025 11:33:41am
    Author:  hsstraub

  ==============================================================================
*/

#include "FrequencyModel.h"

FrequencyModel::FrequencyModel(RationalNumber intervalRatio)
    : value(intervalRatio)
{
}

FrequencyModel::FrequencyModel(float valueInCents)
    : value(valueInCents)
{
}

double FrequencyModel::getValueInCents() const
{
    if (std::holds_alternative<float>(value))
    {
        // Value is in cents
        return std::get<float>(value);
    }
    else
    {
        // Value is a ratio
        auto intervalRatio = std::get<RationalNumber>(value);
        return std::log2(intervalRatio.asDouble()) * 1200;
    }
}

double FrequencyModel::getValueAsFrequencyRatio() const
{
    if (std::holds_alternative<float>(value))
    {
        // Value is in cents
        auto valueInCents = std::get<float>(value);
        return std::exp2(valueInCents/1200.0);
    }
    else
    {
        // Value is a ratio
        auto intervalRatio = std::get<RationalNumber>(value);
        return intervalRatio.asDouble();
    }
}

juce::String FrequencyModel::toString()
{
    if (std::holds_alternative<float>)
    {
        // Value is in cents
        auto cents = std::get<float>(value);
        return juce::String(cents);
    }
    else
    {
        // Value is a ratio
        auto intervalRatio = td::get<RationalNumber>(value);
        return intervalRatio.asString();
    }
}

