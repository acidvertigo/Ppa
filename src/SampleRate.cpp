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

  std::string toString() const override {
    return NumberToString(samplerate);
  }
};

bool SampleRate::operator==(const SampleRate &s1, const SampleRate &s2) {
 return s1.samplerate == s2.samplerate;
}

bool SampleRate::operator!=(const SampleRate &s1, const SampleRate &s2) {
 return !(s1 == s2);
}

std::ostream & SampleRate::operator<<(ostream & os, const SampleRate &sr) {
 return os << sr.toString();
}
