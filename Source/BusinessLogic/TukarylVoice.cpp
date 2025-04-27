/*
  ==============================================================================

    TukarylVoice.cpp
    Created: 27 Apr 2025 11:59:36am
    Author:  hsstraub

  ==============================================================================
*/

#include "TukarylVoice.h"
#include "TukarylSound.h"

TukarylVoice::TukarylVoice(TukarylInstrument& tukarylInstrument)
: theInstrument(tukarylInstrument)
{
}

bool TukarylVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<TukarylSound*> (sound) != nullptr;
}

void TukarylVoice::startNote(
    int midiNoteNumber, float velocity, juce::SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
    currentBaseFrequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    currentVelocity = velocity;
    currentAngle1 = currentAngle2 = 0.0;

    updateFromInstrument();
}

void TukarylVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
    clearCurrentNote();
    angleDelta1 = angleDelta2 = 0.0;
}


void TukarylVoice::renderNextBlock (juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (angleDelta1 != 0.0 || angleDelta2 != 0.0)
    {
        auto level1 = ((float)theInstrument.baseOscLevel)/1000.0f;
        auto level2 = ((float)theInstrument.partial1Level)/1000.0f;

        for (auto sample = 0; sample < numSamples; ++sample)
        {
            auto currentSample1 = (float) std::sin (currentAngle1);
            auto currentSample2 = (float) std::sin (currentAngle2);

            for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample(
                    i, startSample, (currentSample1 * level1 + currentSample2 * level2) * currentVelocity);

            currentAngle1 += angleDelta1;
            currentAngle2 += angleDelta2;
        }
    }
}

void TukarylVoice::updateFromInstrument()
{
    if (getSampleRate() > 0.0)
    {
        auto cyclesPerSample1 = currentBaseFrequency / getSampleRate();
        angleDelta1 = cyclesPerSample1 * 2.0 * juce::MathConstants<double>::pi;

        auto cyclesPerSample2 = cyclesPerSample1 * theInstrument.partial1Frequency;
        angleDelta2 = cyclesPerSample2 * 2.0 * juce::MathConstants<double>::pi;
    }
}
