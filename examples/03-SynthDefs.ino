/* 
Example 3: Synth-Definitions
--------------------------
This example shows you how to define a synth and use it in your audioLoop


MSynth: A modular-synthesis library for Arduino
Author: Akshay Cadambi (akshay19.92@gmail.com)
*/

void setup()
{
    MSynth.init();
}

void loop()
{

}

// This is how you define a synth.
sample mySynth() 
{
	sample out;

	static Sine osc(440.0);	

	out = osc();				// Connect osc to the mySynth's output
}

sample audioLoop(void)
{	
	sample out;			
	out = mySynth();			// Connect 'mySynth' to the audioLoop's output
    return out;
}
