#include "SampleRate.h"
#include "SampleRateTest.h"

int Test::SampleRateTest() 
{
  SampleRate sr();
  static_assert(sr.getSamplerate() == 0, "SampleRate ctor does not set 0 to samplerate property");
    return 0;
}