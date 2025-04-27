/*
  ==============================================================================

    TukarylAudioSource.cpp
    Created: 27 Apr 2025 11:29:43am
    Author:  hsstraub

  ==============================================================================
*/

#include "TukarylAudioSource.h"
#include"TukarylSound.h"

TukarylAudioSource::TukarylAudioSource(juce::MidiKeyboardState& keyState)
: keyboardState (keyState)
{
    synth.addSound (new TukarylSound());
}

void TukarylAudioSource::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    synth.setCurrentPlaybackSampleRate (sampleRate);
}

void TukarylAudioSource::TukarylAudioSource::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    juce::MidiBuffer incomingMidi;
    keyboardState.processNextMidiBuffer (incomingMidi, bufferToFill.startSample, bufferToFill.numSamples, true);
    synth.renderNextBlock (*bufferToFill.buffer, incomingMidi, bufferToFill.startSample, bufferToFill.numSamples);
}

void TukarylAudioSource::TukarylAudioSource::releaseResources()
{
}

