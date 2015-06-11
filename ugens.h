#ifndef UGENS
#define UGENS

#include "synth.h"
#include "audio_config.h"

// Optimizes square-wave ugen to use lesser memory
#define SQUAREWAVE_OPTIMIZE_MEMORY

namespace ugen{

class Sine : public synth::WavetableSynth
    {
    public:
        Sine(float freq);
        sample operator()(void);
    };

class Tri : public synth::WavetableSynth
    {
    public:
        Tri(float freq);
        sample operator()(void);
    };

class Saw: public synth::WavetableSynth
    {
    public:
        Saw(float freq);
        sample operator()(void);
    };

class ReverseSaw: public synth::WavetableSynth
    {
    public:
        ReverseSaw(float freq);
        sample operator()(void);
    };

class Square: public synth::WavetableSynth
    {
    public:

#ifdef SQUAREWAVE_OPTIMIZE_MEMORY
        int half_length;
#endif
        Square(float freq);
        sample operator()(void);
    };

} // End of ugen namespace

#endif
