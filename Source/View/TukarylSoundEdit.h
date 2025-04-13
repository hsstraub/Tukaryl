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
#include "../Model/TukarylInstrument.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TukarylSoundEdit  : public juce::Component
{
public:
    //==============================================================================
    TukarylSoundEdit (TukarylInstrument& injectedInstrument);
    ~TukarylSoundEdit() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TukarylInstrument& theInstrument;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<OscSubComponent> osc1;
    std::unique_ptr<OscSubComponent> osc2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TukarylSoundEdit)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

