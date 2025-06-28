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

//[Headers] You can add your own extra header files here...
#include "ViewConstants.h"
//[/Headers]

#include "OscSubComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OscSubComponent::OscSubComponent (IntervalModel& injectedFrequencyVariable, unsigned short& injectedLevelVariable, bool isDraggable)
    : frequencyVariable(injectedFrequencyVariable), levelVariable(injectedLevelVariable), draggingEnabled(isDraggable),
      isDragging(false)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    levelSlider.reset (new juce::Slider ("levelSlider"));
    addAndMakeVisible (levelSlider.get());
    levelSlider->setRange (0, 127, 1);
    levelSlider->setSliderStyle (juce::Slider::LinearVertical);
    levelSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    levelSlider->addListener (this);

    levelSlider->setBounds (8, 48, 38, 136);

    descriptionLabel.reset (new juce::Label ("descriptionLabel",
                                             TRANS ("Partial")));
    addAndMakeVisible (descriptionLabel.get());
    descriptionLabel->setFont (juce::Font (15.00f, juce::Font::plain));
    descriptionLabel->setJustificationType (juce::Justification::centredTop);
    descriptionLabel->setEditable (false, false, false);
    descriptionLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    descriptionLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    descriptionLabel->setBounds (0, 24, 54, 24);


    //[UserPreSize]
    levelSlider->setValue(levelVariable);
    //[/UserPreSize]

    setSize (60, 184);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OscSubComponent::~OscSubComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    levelSlider = nullptr;
    descriptionLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OscSubComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    descriptionLabel->setText(frequencyVariable.toString(), juce::NotificationType::dontSendNotification);
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    juce::Colour fillColour = juce::Colour(0xff2aa583);

    auto width = getWidth();

    thePointer.clear();
    thePointer.startNewSubPath(0, POINTERHEIGHT);
    thePointer.lineTo(width, POINTERHEIGHT);
    thePointer.lineTo(width/2, 0);
    thePointer.closeSubPath();

    g.setColour(fillColour);
    g.fillPath(thePointer, juce::AffineTransform::translation(0, 0));
    //[/UserPaint]
}

void OscSubComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OscSubComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == levelSlider.get())
    {
        //[UserSliderCode_levelSlider] -- add your slider handling code here..
        levelVariable = sliderThatWasMoved->getValue();
        // sendChangeMessage();
        //[/UserSliderCode_levelSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void OscSubComponent::mouseDown (const juce::MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    if (draggingEnabled)
    {
        juce::Point<float> localPoint = getLocalPoint(e.eventComponent, e.position);
        if (thePointer.contains(localPoint))
        {
            dragStart = e.position;
            dragEnd = e.position;
            isDragging = true;
        }
    }
    //[/UserCode_mouseDown]
}

void OscSubComponent::mouseDrag (const juce::MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    if (isDragging)
    {
        dragEnd = e.position;

        this->listeners.call(&Listener::OnDrag, this);
    }
    //[/UserCode_mouseDrag]
}

void OscSubComponent::mouseUp (const juce::MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    if (isDragging)
    {
        isDragging = false;
    }
    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void OscSubComponent::addListener(OscSubComponent::Listener* listener)
{
    listeners.add(listener);
}

void OscSubComponent::removeListener(OscSubComponent::Listener* listener)
{
    listeners.remove(listener);
}

void OscSubComponent::setFrequency(IntervalModel newFrequency)
{
    frequencyVariable = newFrequency;
    sendChangeMessage();
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OscSubComponent" componentName=""
                 parentClasses="public juce::Component, public juce::ChangeBroadcaster"
                 constructorParams="IntervalModel&amp; injectedFrequencyVariable, unsigned short&amp; injectedLevelVariable, bool isDraggable"
                 variableInitialisers="frequencyVariable(injectedFrequencyVariable), levelVariable(injectedLevelVariable), draggingEnabled(isDraggable),&#10;isDragging(false)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="60" initialHeight="184">
  <METHODS>
    <METHOD name="mouseDown (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const juce::MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="levelSlider" id="a347fb19da583b72" memberName="levelSlider"
          virtualName="" explicitFocusOrder="0" pos="8 48 38 136" min="0.0"
          max="127.0" int="1.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="descriptionLabel" id="d3b401035144e02f" memberName="descriptionLabel"
         virtualName="" explicitFocusOrder="0" pos="0 24 54 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Partial" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

