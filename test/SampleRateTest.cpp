#include "SampleRate.h"
#include "SampleRateTest.h"

int Test::SampleRateTest() 
{
  SampleRate sr(44100);
  static_assert(sr.getSamplerate() == 44100, "SampleRate ctor does not set 0 to samplerate property");
    return 0;
}