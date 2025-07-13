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
    updateTuning();
    updateOscillators();
    updateEnvelopes();
}

bool TukarylVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<TukarylSound*> (sound) != nullptr;
}

void TukarylVoice::startNote(
    int midiNoteNumber, float velocity, juce::SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
    currentBaseFrequency = getMidiNoteInHertz(midiNoteNumber);
    currentVelocity = velocity;
    currentAngle1 = currentAngle2 = currentAngle3 = currentAngle4 = currentAngle5 = currentAngle6 = 0.0;

    updateOscillators();

    partial1Envelope.noteOn();
    partial2Envelope.noteOn();
    mainEnvelope.noteOn();
}

void TukarylVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
    partial1Envelope.noteOff();
    partial2Envelope.noteOff();
    mainEnvelope.noteOff();

    if (!mainEnvelope.isActive())
    {
        clearCurrentNote();
        angleDelta1 = angleDelta2 = angleDelta3 = angleDelta4 = angleDelta5 = angleDelta6 = 0.0;
    }
}


void TukarylVoice::renderNextBlock (juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (angleDelta1 != 0.0 || angleDelta2 != 0.0 || angleDelta3 != 0.0
        || angleDelta4 != 0.0 || angleDelta5 != 0.0 || angleDelta6 != 0.0)
    {
        auto level1 = ((float)theInstrument.baseOscLevel)/1000.0f;
        auto level2 = ((float)theInstrument.partial1Level)/1000.0f;
        auto level3 = ((float)theInstrument.partial2Level)/1000.0f;
        auto level4 = ((float)theInstrument.partial3Level)/1000.0f;
        auto level5 = ((float)theInstrument.partial4Level)/1000.0f;
        auto level6 = ((float)theInstrument.partial5Level)/1000.0f;

        for (auto sample = 0; sample < numSamples; ++sample)
        {
            auto currentSample1 = (float) std::sin (currentAngle1);
            auto currentSample2 = (float) std::sin (currentAngle2);
            auto currentSample3 = (float) std::sin (currentAngle3);
            auto currentSample4 = (float) std::sin (currentAngle4);
            auto currentSample5 = (float) std::sin (currentAngle5);
            auto currentSample6 = (float) std::sin (currentAngle6);

            auto alloverSample =
                (currentSample1 * level1
                    + currentSample2 * level2 * partial1Envelope.getNextSample()
                    + currentSample3 * level3 * partial2Envelope.getNextSample()
                    + currentSample4 * level4
                    + currentSample5 * level5
                    + currentSample6 * level6)
                * currentVelocity * mainEnvelope.getNextSample();

            for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample(i, startSample, alloverSample);

            currentAngle1 += angleDelta1;
            currentAngle2 += angleDelta2;
            currentAngle3 += angleDelta3;
            currentAngle4 += angleDelta4;
            currentAngle5 += angleDelta5;
            currentAngle6 += angleDelta6;
            ++startSample;
        }
    }
}

void TukarylVoice::setCurrentPlaybackSampleRate (double newRate)
{
    if (newRate > 0.0)
    {
        juce::SynthesiserVoice::setCurrentPlaybackSampleRate(newRate);
        partial1Envelope.setSampleRate(newRate);
        mainEnvelope.setSampleRate(newRate);
    }
}

void TukarylVoice::updateTuning()
{
    tuningTableSize = (int)theInstrument.tuningTable.size();
}

void TukarylVoice::updateOscillators()
{
    if (getSampleRate() > 0.0)
    {
        auto cyclesPerSample1 = currentBaseFrequency / getSampleRate();
        angleDelta1 = cyclesPerSample1 * 2.0 * juce::MathConstants<double>::pi;

        auto cyclesPerSample2 = cyclesPerSample1 * theInstrument.partial1Frequency.getValueAsFrequencyRatio();
        angleDelta2 = cyclesPerSample2 * 2.0 * juce::MathConstants<double>::pi;

        auto cyclesPerSample3 = cyclesPerSample1 * theInstrument.partial2Frequency.getValueAsFrequencyRatio();
        angleDelta3 = cyclesPerSample3 * 2.0 * juce::MathConstants<double>::pi;

        auto cyclesPerSample4 = cyclesPerSample1 * theInstrument.partial3Frequency.getValueAsFrequencyRatio();
        angleDelta4 = cyclesPerSample4 * 2.0 * juce::MathConstants<double>::pi;

        auto cyclesPerSample5 = cyclesPerSample1 * theInstrument.partial4Frequency.getValueAsFrequencyRatio();
        angleDelta5 = cyclesPerSample5 * 2.0 * juce::MathConstants<double>::pi;

        auto cyclesPerSample6 = cyclesPerSample1 * theInstrument.partial5Frequency.getValueAsFrequencyRatio();
        angleDelta6 = cyclesPerSample6 * 2.0 * juce::MathConstants<double>::pi;
    }
}

void TukarylVoice::updateEnvelopes()
{
    if (partial1Envelope.isActive())
    {
        partial1Envelope.reset();
    }
    partial1Envelope.setParameters(theInstrument.partial1Envelope);

    if (partial2Envelope.isActive())
    {
        partial2Envelope.reset();
    }
    partial2Envelope.setParameters(theInstrument.partial2Envelope);

    if (mainEnvelope.isActive())
    {
        mainEnvelope.reset();
    }
    mainEnvelope.setParameters(theInstrument.mainEnvelope);
}

double TukarylVoice::getMidiNoteInHertz (int midiNoteNumber)
{
    static int middleCNoteNumber = 60;

    int midiNoteNumberFromMiddleC = midiNoteNumber - middleCNoteNumber;

    int abstractOctaveNoFromMiddleC = 0;
    int midiNrOfAbstractOctaveStart = middleCNoteNumber;

    int tempMidiNoteNumber = midiNoteNumberFromMiddleC;
    if (tempMidiNoteNumber >= tuningTableSize)
    {
        while (tempMidiNoteNumber > tuningTableSize)
        {
            abstractOctaveNoFromMiddleC++;
            midiNrOfAbstractOctaveStart += tuningTableSize;
            tempMidiNoteNumber -= tuningTableSize;
        }
    }
    else if (tempMidiNoteNumber < 0)
    {
        while (tempMidiNoteNumber < 0)
        {
            abstractOctaveNoFromMiddleC--;
            midiNrOfAbstractOctaveStart -= tuningTableSize;
            tempMidiNoteNumber += tuningTableSize;
        }
    }

    double abstractOctaveStartInHertz = getAbstractOctaveStartInHertz(abstractOctaveNoFromMiddleC);

    if (midiNoteNumber == midiNrOfAbstractOctaveStart)
    {
        return abstractOctaveStartInHertz;
    }

    int noteNumberFromAbstractOctaveStart = midiNoteNumber - midiNrOfAbstractOctaveStart;

    return abstractOctaveStartInHertz * theInstrument.tuningTable.at(noteNumberFromAbstractOctaveStart-1).getValueAsFrequencyRatio();
}


double TukarylVoice::getAbstractOctaveStartInHertz(int abstractOctaveNoFromMiddleC)
{
    static double middleCInHertz = 440.0 / IntervalModel(900.0).getValueAsFrequencyRatio();

    double abstractOctaveStartInHertz = middleCInHertz;
    if (abstractOctaveNoFromMiddleC != 0)
    {
        abstractOctaveStartInHertz *= std::pow(
            theInstrument.tuningTable.periodInterval().getValueAsFrequencyRatio(), abstractOctaveNoFromMiddleC);
    }

    return abstractOctaveStartInHertz;
}


