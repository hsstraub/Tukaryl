/*
  ==============================================================================

    IntervalModel.cpp
    Created: 11 May 2025 11:33:41am
    Author:  hsstraub

  ==============================================================================
*/

#include "IntervalModel.h"

IntervalModel::IntervalModel(RationalNumber intervalRatio)
    : value(intervalRatio)
{
}

IntervalModel::IntervalModel(float valueInCents)
    : value(valueInCents)
{
}

double IntervalModel::getValueInCents() const
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

double IntervalModel::getValueAsFrequencyRatio() const
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

juce::String IntervalModel::toString()
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

IntervalModel IntervalModel::add(IntervalModel const& second) const
{
    if (std::holds_alternative<float>(value) || std::holds_alternative<float>(second.value))
    {
        // At least one of the values is in cents
        return IntervalModel(getValueInCents() + second.getValueInCents());
    }
    else
    {
        // Both values are ratios
        return IntervalModel(std::get<RationalNumber>(value) * std::get<RationalNumber>(second.value));
    }
}

IntervalModel IntervalModel::getInverse() const
{
    if (std::holds_alternative<float>(value))
    {
        // Value is in cents
        auto valueInCents = std::get<float>(value);
        return IntervalModel(-valueInCents);
    }
    else
    {
        // Value is a ratio
        auto intervalRatio = std::get<RationalNumber>(value);
        return IntervalModel(intervalRatio.getInverse());
    }
}

