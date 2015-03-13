#ifndef OSCILLATOR
#define OSCILLATOR

#include <inttypes.h>
#include <cstdlib>
#include "table.h"
#include "math.h"

namespace oscillator{

class WavetableSynth
    {
    public:
        float frequency;
        float phase;
        int current_phase;
        int phase_inc;
        double *tbl;

        WavetableSynth();
        void setFreq(float freq);
        double tick();
        double freqMod(float freq);

    protected:
    };

class Sine : public WavetableSynth
    {
    public:
        Sine(float freq);
    };

class Saw: public WavetableSynth
    {
    public:
        Saw(float freq);
    };

}

#endif // OSCILLATOR
