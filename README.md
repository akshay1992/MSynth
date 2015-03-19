MSynth
======
#####A modular synthesis library for Arduino. 
Author: Akshay Cadambi

MSynth was designed to make modular synthesis on the arduino simple and easy to use. It tries to combine the idea of SynthDefs, like in [SuperCollider](http://supercollider.sourceforge.net/) with [Gamma](http://mat.ucsb.edu/gamma/)'s simple syntax that is a result of it's per-sample processing architecture. 

The intent of this project was to make the sketch code as decluttered as possible, and yet, have the ability to work with powerful modular-synthesis tools. 

Therefore, the design of the syntax focuses on ease of programming and ease of use: connect modules together, create synths, and have fun with it. 

Please see examples for a step-by-step instructions of how to use MSynth. 

######Hardware Specs:
* Tested on `Arduino Uno`. 
* Uses `Pin 9` as `audio output` pin (PWM based).

######Features (at the moment)
* Wavetable based oscillators: Sine, Triangle, Saw, Reverse-Saw, Square
* Amplitude and Frequency modulation. 
* Custom synth definitions to connect oscillators in any manner. 
* Per-sample processing at 16kHz.
* 8-bit audio. 
* Uses the `TimerOne` library (included in the source). 

######Features (future)
* Control Rate / Audio Rate ISR system. 
* Envelopes: Linear, exponential. 
* Control Rate Amplitude and frequency modulation.
* Filters, effects, etc.

######Caveats:
* Uses Timer1. You can no longer use the `Servo Library` or any other library that makes use of Timer1.

------
This project was conceived as a part of the *240B: Audio Synthesis and Processing* course at the Media, Arts and Technology Program, UC Santa Barbara.
Contact: akshay19.92@gmail.com
