/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.12

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>

#include "OscSubComponent.h"
#include "EnvelopeEdit.h"
#include "../Model/TukarylInstrument.h"
#include "../Model/IntervalModel.h"
#include "../HajuLib/HajuErrorVisualizer.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TukarylSoundEdit  : public juce::Component,
                          public OscSubComponent::Listener,
                          public juce::ChangeBroadcaster,
                          public juce::Button::Listener
{
public:
    //==============================================================================
    TukarylSoundEdit (TukarylInstrument& injectedInstrument);
    ~TukarylSoundEdit() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void addChangeListener (juce::ChangeListener* const listener);

    void OnDrag(OscSubComponent* component) override;

private:
    void paintRuler(juce::Graphics& g);
    void paintRulerMark(juce::Graphics& g, int rulerYPos, IntervalModel frequency);

    int getXPosOfFrequency(IntervalModel frequency);
    IntervalModel getFrequencyOfXPos(double xPos);

    void OpenSclFileDialog();

    void displayMessage(String message, HajuErrorVisualizer::ErrorLevel errorLevel = HajuErrorVisualizer::ErrorLevel::noError);

public:
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TukarylInstrument& theInstrument;

    const IntervalModel maxFrequency = IntervalModel::doubleOctave();

    std::unique_ptr<FileChooser> chooser;
    File	currentFile;

    HajuErrorVisualizer errorVisualizer;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> groupOscillators;
    std::unique_ptr<OscSubComponent> osc1;
    std::unique_ptr<OscSubComponent> osc2;
    std::unique_ptr<juce::Label> lblTuningDescription;
    std::unique_ptr<juce::TextButton> btnLoadScalaFile;
    std::unique_ptr<juce::TextButton> btnTuningReset;
    std::unique_ptr<juce::Label> labelMessageArea;
    std::unique_ptr<juce::GroupComponent> groupMainEnvelope;
    std::unique_ptr<EnvelopeEdit> mainEnvelopeComponent;
    std::unique_ptr<OscSubComponent> osc3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TukarylSoundEdit)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

