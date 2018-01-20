#include "SampleRate.h"
#include "SampleRateTest.h"

namespace Test {
  
  int SampleRateTest() {
    SampleRate obj = new SampleRate;
    if (obj == 0)
      return 0;
    else
      return -1;
  }
  
}