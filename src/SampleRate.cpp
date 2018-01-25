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
/*
 * Constructor: SampleRate
 * Usage: Samplerate sr(sampleratec);
 * ------------------------
 * Creates a SampleRate object.  The parameter sets the samplerate;
 */
  SampleRate(int sampleratec) {
    samplerate = sampleratec;
  }

  ~SampleRate() override { };

  int getSamplerate() override {
    return samplerate;
  }

  std::string toString() override {
    return NumberToString(samplerate);
  }

bool operator==(SampleRate s1, SampleRate s2) override {
 return s1.samplerate == s2.samplerate;
}

bool operator!=(SampleRate s1, SampleRate s2) override {
 return !(s1 == s2);
}

std::ostream & operator<<(ostream & os, SampleRate sr) override {
 return os << sr.toString();
}

};