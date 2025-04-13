#pragma once

#include <JuceHeader.h>

#include "View/TukarylSoundEdit.h"
#include "Model/TukarylInstrument.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent, public juce::ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

	void changeListenerCallback(juce::ChangeBroadcaster *source) override;

    TukarylInstrument theInstrument;

private:
    //==============================================================================
    // Your private member variables go here...
    double currentSampleRate = 0.0, currentAngle = 0.0, angleDelta = 0.0;

    std::unique_ptr<TukarylSoundEdit> soundEditComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
