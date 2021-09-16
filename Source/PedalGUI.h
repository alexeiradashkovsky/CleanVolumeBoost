/*
  ==============================================================================

    PedalGUI.h
    Created: 16 Sep 2021 11:16:23am
    Author:  Alexei Radashkovsky 

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>
#include "PluginProcessor.h"
//==============================================================================
/*
*/

namespace BrutalARAudio {
  using KnobData = std::tuple<juce::StringRef, float*>;
  class PedalGUI  : public juce::Component,
                    public juce::Slider::Listener {
  public:
      PedalGUI(
        juce::StringRef&&            _name,
        juce::StringRef&&            _pedalName,
        juce::Colour&&               _colour,
        std::vector<KnobData>& _knobsAndValues
      );
      ~PedalGUI() override;

      void paint (juce::Graphics&) override;
      void resized() override;

  private:
      std::vector<juce::Slider> mKnobs;

      // TODO: add processor here
      JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PedalGUI)
  };
}

