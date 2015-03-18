#ifndef MSYNTH
#define MSYNTH

/* ********************************
 *            MSynth
 * ********************************
 *
 * MSynth is a modular-synth library for Arduino.
 *
 * Author:
 *   Akshay Cadambi
 *   Graduate student in Media Arts and Technology
 *   UC Santa Barbara
 *
 * */

#include "TimerOne.h"
#include "ugens.h"

#define AUDIO_OUTPUT_REGISTER OCR1A

using namespace ugen;

// This function will defined by the user in the Ardunino Sketch
inline sample audioLoop(void);

inline void audioISR(void){
    /*
     * Writes audio to port.
     * This function is called by the Timer1 Routine within MSynthMaster
     * This is simply an non-exposed alias for audioLoop()
     * */

    // TODO: Range conversion
    AUDIO_OUTPUT_REGISTER = audioLoop();
}

class MSynthMaster
{
    /*
     * Used to automate the ISR and provide an interface between the sketch
     * and the backend.
     *
     * Note:
     *  The interrupt service routine MUST be the audioISR defined in this file.
     * */
public:
    MSynthMaster(void)
    {
        _ISRfrequency = SystemSR; // SystemSR is defined in table.h
        initTimer();
    }

    void initTimer()
    {
        int ISRPeriod_inMicroseconds = 1000000 / (double) _ISRfrequency ;
        Timer1.initialize( ISRPeriod_inMicroseconds );
        Timer1.attachInterrupt( audioISR );
    }

private:
    long int _ISRfrequency;
    TimerOne Timer1;

} MSynth;

#endif // MSYNTH
