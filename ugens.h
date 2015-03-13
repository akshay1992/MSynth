#ifndef UGENS
#define UGENS

#include "synth.h"

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
        Square(float freq);
        sample operator()(void);
    };

} // End of ugen namespace

#endif
