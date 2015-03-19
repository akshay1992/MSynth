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
#include "wiring_private.h"

#define AUDIO_OUTPUT_REGISTER OCR1A

using namespace ugen;

// This function will defined by the user in the Ardunino Sketch
sample audioLoop(void);

inline void audioISR(void)
{
   /*
    * Writes audio to port.
    * This is the default audio-rate ISR and is a 'hidden' alias for audioLoop()
    * Set within MSynthMaster.
    *
    * TODO: Add a global DC_OFFSET for easier amplitude modulation
    * */

    AUDIO_OUTPUT_REGISTER = audioLoop();
}


class MSynthMaster
{
    /*
     * Used to automate the ISR and provide an interface between the sketch
     * and the backend.
     * */
public:
    MSynthMaster(void)
    {
        _ISRfrequency = SystemSR;
    }

    MSynthMaster(long int SR)
    {
        // TODO: Find a way to integrate this into everything
        // This doesn't really affect the oscillators yet.
        _ISRfrequency = SR;
    }

    void init(void)
    {
        long int ISRPeriod_inMicroseconds = 1000000 / (double) _ISRfrequency ;

        pinMode(9, OUTPUT);
        Timer1.initialize( ISRPeriod_inMicroseconds );
        Timer1.attachInterrupt(audioISR);
        sbi(TCCR1A, COM1A1);                // Associates Pin 9 with the Timer1 Output
    }

    long int _ISRfrequency;                 // Audio Rate

} MSynth;

#endif // MSYNTH
