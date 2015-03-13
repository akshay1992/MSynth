#include <iostream>
#include "oscillator.h"
#include "math.h"

double oscillator::WavetableSynth::freqMod(float freq)
{
    phase_inc = floor( frequency * (double) Tables::table_length() / SystemSR );
    return this->tick();
}

double oscillator::WavetableSynth::tick()
{
    current_phase += phase_inc;
    current_phase = current_phase & Tables::phase_mask();
    return *(tbl + current_phase - phase_inc);
}

void oscillator::WavetableSynth::setFreq(float freq)
{
    frequency = freq;
    phase_inc = lrint( frequency * (double) Tables::table_length() / SystemSR );
}

oscillator::WavetableSynth::WavetableSynth()
{
    current_phase = 0;
    tbl = NULL;
}

oscillator::Sine::Sine(float freq)
{
    setFreq(freq);
    tbl = Tables::sine();
}

oscillator::Saw::Saw(float freq)
{
    setFreq(freq);
    tbl = Tables::saw();
}
