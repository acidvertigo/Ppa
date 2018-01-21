#include "SampleRate.h"
#include "SampleRateTest.h"

int Test::SampleRateTest() 
{
  SampleRate sr(15);
  static_assert(sr.getSamplerate() == 0, "SampleRate ctor does not set 0 to samplerate property");
    return 0;
}