/* 
Example 2: Sine Oscillator
--------------------------
This example shows you how to output a Sine-wave. 


MSynth: A modular-synthesis library for Arduino
Author: Akshay Cadambi (akshay19.92@gmail.com)
*/

sample audioLoop(void)
{	
	sample out;			

	Sine osc(440.0);	// Sine-oscillator of frequency 440Hz

	out = osc();		// Send the sine-wave to the output
    return out;
}


void setup()
{
    MSynth.init();
}

void loop()
{

}


