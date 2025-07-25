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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class EnvelopeEdit  : public juce::Component,
                      public juce::ChangeBroadcaster,
                      public juce::Slider::Listener
{
public:
    //==============================================================================
    EnvelopeEdit (float& injectedAttackVariable, float& injectedDecayVariable, float& injectedSustainVariable, float& injectedReleaseVariable);
    ~EnvelopeEdit() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    float& attackVariable;
    float& decayVariable;
    float& sustainVariable;
    float& releaseVariable;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> sliderAttack;
    std::unique_ptr<juce::Label> labelAttack;
    std::unique_ptr<juce::Slider> sliderRelease;
    std::unique_ptr<juce::Label> labelRelease;
    std::unique_ptr<juce::Slider> sliderDecay;
    std::unique_ptr<juce::Label> labelDecay;
    std::unique_ptr<juce::Slider> sliderSustain;
    std::unique_ptr<juce::Label> labelSustain;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeEdit)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

