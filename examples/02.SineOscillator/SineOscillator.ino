/* 
Example 2: Sine Oscillator
--------------------------
This example shows you how to output a Sine-wave. 

MSynth: A modular-synthesis library for Arduino
Author: Akshay Cadambi (akshay19.92@gmail.com)
*/

#include "MSynth.h"

void setup()
{
    MSynth.init();
}

void loop()
{

}

sample audioLoop(void)
{	
	sample out;			

	static Sine osc(440.0);	// Sine-oscillator of frequency 440Hz (Make sure all declarations are 'static')

	out = osc();			// Send the sine-wave to the output
    return out;
}

