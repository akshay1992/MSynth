#ifndef AUDIO_CONFIG
#define AUDIO_CONFIG


// TODO: Frequency division of sample rate (for control rate) - Comments in synth and ugens.
#define LF_FREQ_DIV 2

#define SystemSR 16000
typedef char sample;    // Signed 8-bit Audio Sample
typedef int sample16;   // Signed 16-bit audio (used behind the scenes for + and * operations)

#endif
