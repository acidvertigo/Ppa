#include "SampleRate.h"
#include "SampleRateTest.h"

int Test::SampleRateTest() 
{
  ::SampleRate sr(44100);
  assert(sr.getSamplerate() == 44100);
  return 0;
}