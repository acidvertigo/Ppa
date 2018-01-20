#include "SampleRate.h"
#include "SampleRateTest.h"
namespace Test {
  int SampleRateTest() {
    SampleRate obj = new SampleRate();
    static_assert(obj == 0, "SampleRate ctor does not set 0 to samplerate property");
  }
}