#ifndef UGENS
#define UGENS

#include "synth.h"

// Optimizes square-wave ugen to use lesser memory
#define SQUAREWAVE_MEMORY_OPTIMIZATION 1

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

#if SQUAREWAVE_MEMORY_OPTIMIZATION == 1
        int half_length;
#endif
        Square(float freq);
        sample operator()(void);
    };

} // End of ugen namespace

#endif
