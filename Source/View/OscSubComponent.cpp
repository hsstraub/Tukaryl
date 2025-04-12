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
//[/Headers]

#include "OscSubComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OscSubComponent::OscSubComponent (juce::String labelText)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    levelSlider.reset (new juce::Slider ("levelSlider"));
    addAndMakeVisible (levelSlider.get());
    levelSlider->setRange (0, 127, 1);
    levelSlider->setSliderStyle (juce::Slider::LinearVertical);
    levelSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    levelSlider->addListener (this);

    levelSlider->setBounds (16, 64, 38, 152);

    descriptionLabel.reset (new juce::Label ("descriptionLabel",
                                             TRANS ("Partial")));
    addAndMakeVisible (descriptionLabel.get());
    descriptionLabel->setFont (juce::Font (15.00f, juce::Font::plain));
    descriptionLabel->setJustificationType (juce::Justification::centredTop);
    descriptionLabel->setEditable (false, false, false);
    descriptionLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    descriptionLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    descriptionLabel->setBounds (8, 32, 62, 24);

    internalPath1.startNewSubPath (40.0f, 4.0f);
    internalPath1.lineTo (72.0f, 24.0f);
    internalPath1.lineTo (8.0f, 24.0f);
    internalPath1.closeSubPath();


    //[UserPreSize]
    //[/UserPreSize]

    setSize (32, 216);


    //[Constructor] You can add your own custom stuff here..
    descriptionLabel->setText(labelText, juce::NotificationType::dontSendNotification);
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
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        float x = 0, y = 0;
        juce::Colour fillColour = juce::Colour (0xff2aa583);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath1, juce::AffineTransform::translation (x, y));
    }

    //[UserPaint] Add your own custom painting code here..
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
        //[/UserSliderCode_levelSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OscSubComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="juce::String labelText"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="32" initialHeight="216">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="solid: ff2aa583" hasStroke="0" nonZeroWinding="1">s 40 4 l 72 24 l 8 24 x</PATH>
  </BACKGROUND>
  <SLIDER name="levelSlider" id="a347fb19da583b72" memberName="levelSlider"
          virtualName="" explicitFocusOrder="0" pos="16 64 38 152" min="0.0"
          max="127.0" int="1.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="descriptionLabel" id="d3b401035144e02f" memberName="descriptionLabel"
         virtualName="" explicitFocusOrder="0" pos="8 32 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Partial" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

