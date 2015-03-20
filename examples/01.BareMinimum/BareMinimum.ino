/* 
Example 1: Bare Minimum
-----------------------
This example simply initializes MSynth. This is the bare minimum code for including MSynth in your project. 

MSynth: A modular-synthesis library for Arduino
Author: Akshay Cadambi (akshay19.92@gmail.com)
*/

#include "MSynth.h"

void setup()
{
	// Setup code
    MSynth.init();
}

void loop()
{
	// Regular loop code. 
}

// This is another loop where you put only the audio stuff.
 
sample audioLoop(void)
{	
	sample out; 			// To hold the output. Pass all audio to this variable.

	// This is where the audio code goes. 

	return out;
}
