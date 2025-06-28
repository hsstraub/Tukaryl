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

#include "EnvelopeEdit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EnvelopeEdit::EnvelopeEdit ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    levelSlider.reset (new juce::Slider ("levelSlider"));
    addAndMakeVisible (levelSlider.get());
    levelSlider->setRange (0, 2, 0.01);
    levelSlider->setSliderStyle (juce::Slider::LinearVertical);
    levelSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    levelSlider->addListener (this);

    levelSlider->setBounds (16, 8, 30, 136);

    labelAttack.reset (new juce::Label ("labelAttack",
                                        TRANS ("Attack")));
    addAndMakeVisible (labelAttack.get());
    labelAttack->setFont (juce::Font (15.00f, juce::Font::plain));
    labelAttack->setJustificationType (juce::Justification::centredTop);
    labelAttack->setEditable (false, false, false);
    labelAttack->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelAttack->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelAttack->setBounds (0, 152, 62, 24);

    levelSlider2.reset (new juce::Slider ("levelSlider"));
    addAndMakeVisible (levelSlider2.get());
    levelSlider2->setRange (0, 2, 0.01);
    levelSlider2->setSliderStyle (juce::Slider::LinearVertical);
    levelSlider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    levelSlider2->addListener (this);

    levelSlider2->setBounds (208, 8, 30, 136);

    labelRelease.reset (new juce::Label ("labelRelease",
                                         TRANS ("Release")));
    addAndMakeVisible (labelRelease.get());
    labelRelease->setFont (juce::Font (15.00f, juce::Font::plain));
    labelRelease->setJustificationType (juce::Justification::centredTop);
    labelRelease->setEditable (false, false, false);
    labelRelease->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelRelease->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelRelease->setBounds (192, 152, 62, 24);

    levelSlider3.reset (new juce::Slider ("levelSlider"));
    addAndMakeVisible (levelSlider3.get());
    levelSlider3->setRange (0, 2, 0.01);
    levelSlider3->setSliderStyle (juce::Slider::LinearVertical);
    levelSlider3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    levelSlider3->addListener (this);

    levelSlider3->setBounds (80, 8, 30, 136);

    labelDecay.reset (new juce::Label ("labelDecay",
                                       TRANS ("Decay")));
    addAndMakeVisible (labelDecay.get());
    labelDecay->setFont (juce::Font (15.00f, juce::Font::plain));
    labelDecay->setJustificationType (juce::Justification::centredTop);
    labelDecay->setEditable (false, false, false);
    labelDecay->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelDecay->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelDecay->setBounds (64, 152, 62, 24);

    levelSlider4.reset (new juce::Slider ("levelSlider"));
    addAndMakeVisible (levelSlider4.get());
    levelSlider4->setRange (0, 1, 0.01);
    levelSlider4->setSliderStyle (juce::Slider::LinearVertical);
    levelSlider4->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    levelSlider4->addListener (this);

    levelSlider4->setBounds (144, 8, 30, 136);

    labelSustain.reset (new juce::Label ("labelSustain",
                                         TRANS ("Sustain")));
    addAndMakeVisible (labelSustain.get());
    labelSustain->setFont (juce::Font (15.00f, juce::Font::plain));
    labelSustain->setJustificationType (juce::Justification::centredTop);
    labelSustain->setEditable (false, false, false);
    labelSustain->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelSustain->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelSustain->setBounds (128, 152, 62, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (256, 184);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

EnvelopeEdit::~EnvelopeEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    levelSlider = nullptr;
    labelAttack = nullptr;
    levelSlider2 = nullptr;
    labelRelease = nullptr;
    levelSlider3 = nullptr;
    labelDecay = nullptr;
    levelSlider4 = nullptr;
    labelSustain = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EnvelopeEdit::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EnvelopeEdit::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EnvelopeEdit::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == levelSlider.get())
    {
        //[UserSliderCode_levelSlider] -- add your slider handling code here..
        //[/UserSliderCode_levelSlider]
    }
    else if (sliderThatWasMoved == levelSlider2.get())
    {
        //[UserSliderCode_levelSlider2] -- add your slider handling code here..
        //[/UserSliderCode_levelSlider2]
    }
    else if (sliderThatWasMoved == levelSlider3.get())
    {
        //[UserSliderCode_levelSlider3] -- add your slider handling code here..
        //[/UserSliderCode_levelSlider3]
    }
    else if (sliderThatWasMoved == levelSlider4.get())
    {
        //[UserSliderCode_levelSlider4] -- add your slider handling code here..
        //[/UserSliderCode_levelSlider4]
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

<JUCER_COMPONENT documentType="Component" className="EnvelopeEdit" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="256" initialHeight="184">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="levelSlider" id="a347fb19da583b72" memberName="levelSlider"
          virtualName="" explicitFocusOrder="0" pos="16 8 30 136" min="0.0"
          max="2.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="labelAttack" id="d3b401035144e02f" memberName="labelAttack"
         virtualName="" explicitFocusOrder="0" pos="0 152 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="levelSlider" id="9ff57e166e767502" memberName="levelSlider2"
          virtualName="" explicitFocusOrder="0" pos="208 8 30 136" min="0.0"
          max="2.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="labelRelease" id="72d6f2a0484a707c" memberName="labelRelease"
         virtualName="" explicitFocusOrder="0" pos="192 152 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="levelSlider" id="92ef75266e7af86" memberName="levelSlider3"
          virtualName="" explicitFocusOrder="0" pos="80 8 30 136" min="0.0"
          max="2.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="labelDecay" id="5e0ccbcb5d648017" memberName="labelDecay"
         virtualName="" explicitFocusOrder="0" pos="64 152 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="levelSlider" id="9b23709c8504fc47" memberName="levelSlider4"
          virtualName="" explicitFocusOrder="0" pos="144 8 30 136" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="labelSustain" id="e71a0400c01b2884" memberName="labelSustain"
         virtualName="" explicitFocusOrder="0" pos="128 152 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

