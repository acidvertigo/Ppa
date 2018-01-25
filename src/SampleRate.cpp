/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include <string>
#include "ISampleRate.h"
#include "libString.h"
using namespace std;

class SampleRate: public ISampleRate
{
public:
  SampleRate(int sampleratec) {
    samplerate = sampleratec;
  }

  int getSamplerate() {
    return samplerate;
  }

  std::string toString() {
    return NumberToString(samplerate);
  }
}

bool operator==(SampleRate s1, SampleRate s2) {
   return s1.samplerate == s2.samplerate;
}

bool operator!=(SampleRate s1, SampleRate s2) {
   return !(s1 == s2);
}

std::ostream & operator<<(ostream & os, SampleRate sr) {
   return os << sr.toString();
}