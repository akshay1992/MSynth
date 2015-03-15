#include "ugens.h"
#include "math.h"

//--------------------------------------------

ugen::Sine::Sine(float freq)
{
    setFreq(freq);
    tbl = Tables::sine();
}

sample ugen::Sine::operator()(void)
{
    return tick();
}


//--------------------------------------------

ugen::Tri::Tri(float freq)
{
    setFreq(freq);
    tbl = Tables::tri();
}

sample ugen::Tri::operator()(void)
{
    return tick();
}


//--------------------------------------------

ugen::Saw::Saw(float freq)
{
    setFreq(freq);
    tbl = Tables::saw();
}

sample ugen::Saw::operator()(void)
{
    return tick();
}

//--------------------------------------------

ugen::ReverseSaw::ReverseSaw(float freq)
{
    setFreq(freq);
    tbl = Tables::saw();
}

sample ugen::ReverseSaw::operator()(void)
{
    /* This is a neat little trick. It simply reverses the indexing of the saw
     * table to give the reverse saw.
     * The change in indexing uses bitwise operations so it is very fast!
     */
    sample outValue = *(tbl + (~current_phase & Tables::phase_mask()) );
    current_phase += phase_inc;
    current_phase = current_phase & Tables::phase_mask();
    return outValue;
}

//--------------------------------------------

ugen::Square::Square(float freq)
{
    setFreq(freq);
    // Note. This is optimized. See table.cpp for details.
#if SQUAREWAVE_MEMORY_OPTIMIZATION == 1
    tbl = NULL;
    half_length = Tables::length()/2;
#else
    tbl = Tables::square();
#endif
}

sample ugen::Square::operator()(void)
{
#if SQUAREWAVE_MEMORY_OPTIMIZATION == 1
    sample outValue = ( current_phase <= half_length );
    current_phase += phase_inc;
    current_phase = current_phase & Tables::phase_mask();
    return outValue;
#else
    return tick();
#endif

}
