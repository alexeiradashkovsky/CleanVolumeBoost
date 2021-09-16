/*
  ==============================================================================

    PedalGUI.cpp
    Created: 16 Sep 2021 11:16:23am
    Author:  alexei

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PedalGUI.h"

using namespace BrutalARAudio;

//==============================================================================
PedalGUI::PedalGUI(
      juce::StringRef&&            _name,
      juce::StringRef&&            _pedalName,
      juce::Colour&&               _colour,
      std::vector<KnobData>& _knobsAndValues
) {
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setName(_name);
    setComponentID(_pedalName);

    uint8_t place = 0;
    for (KnobData& _newKnob : _knobsAndValues) {
      juce::Slider newSlider;
      mKnobs.push_back(std::move(newSlider));
      mKnobs[place].addListener(this);
      mKnobs[place].setName(std::get<0>(_newKnob));
      mKnobs[place].setTooltip(std::get<0>(_newKnob));
      mKnobs[place].setColour(juce::Slider::thumbColourId, _colour);
      mKnobs[place].setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
      mKnobs[place].setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
      mKnobs[place].setRange(0.f, 1.f);
      mKnobs[place].setValue(*(std::get<1>(_newKnob)));
      addAndMakeVisible(mKnobs[place]);
      ++place;
    }
}

PedalGUI::~PedalGUI()
{
}

void PedalGUI::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("PedalGUI", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void PedalGUI::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
