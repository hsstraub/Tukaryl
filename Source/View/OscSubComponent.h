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
#include "../Model/IntervalModel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OscSubComponent  : public juce::Component,
                         public juce::ChangeBroadcaster,
                         public juce::Slider::Listener
{
public:
    //==============================================================================
    OscSubComponent (IntervalModel& injectedFrequencyVariable, unsigned short& injectedLevelVariable, bool isDraggable);
    ~OscSubComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    // Types
public:
    // Listener class, to notify changes
    class Listener
    {
    public:
        // Destructor
        virtual ~Listener() {}

        virtual void OnDrag(OscSubComponent* component) = 0;
    };

    void addListener(Listener* listenerToAdd);
    void removeListener(Listener* listenerToRemove);

    juce::Point<float> getDragStart() const { return dragStart; }
    juce::Point<float> getDragEnd() const { return dragEnd; }

    void setFrequency(IntervalModel newFrequency);

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void mouseDown (const juce::MouseEvent& e) override;
    void mouseDrag (const juce::MouseEvent& e) override;
    void mouseUp (const juce::MouseEvent& e) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    IntervalModel& frequencyVariable;
    unsigned short& levelVariable;

    bool draggingEnabled;
    juce::Point<float> dragStart;
    juce::Point<float> dragEnd;
    bool isDragging;
    juce::ListenerList<Listener> listeners;

    juce::Path thePointer;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> levelSlider;
    std::unique_ptr<juce::Label> descriptionLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscSubComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

