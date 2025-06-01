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
    if (std::holds_alternative<float>(value))
    {
        // Value is in cents
        auto valueInCents = std::get<float>(value);
        return juce::String(valueInCents);
    }
    else
    {
        // Value is a ratio
        auto intervalRatio = std::get<RationalNumber>(value);
        return intervalRatio.asString();
    }
}

FrequencyModel FrequencyModel::add(FrequencyModel const& second) const
{
    if (std::holds_alternative<float>(value) || std::holds_alternative<float>(second.value))
    {
        // At least one of the values is in cents
        return FrequencyModel(getValueInCents() + second.getValueInCents());
    }
    else
    {
        // Both values are ratios
        return FrequencyModel(std::get<RationalNumber>(value) * std::get<RationalNumber>(second.value));
    }
}

FrequencyModel FrequencyModel::getInverse() const
{
    if (std::holds_alternative<float>(value))
    {
        // Value is in cents
        auto valueInCents = std::get<float>(value);
        return FrequencyModel(-valueInCents);
    }
    else
    {
        // Value is a ratio
        auto intervalRatio = std::get<RationalNumber>(value);
        return FrequencyModel(intervalRatio.getInverse());
    }
}

