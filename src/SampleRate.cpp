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
  SampleRate(const int &sampleratec) {
    samplerate = sampleratec;
  }

  ~SampleRate() override { };

  int getSamplerate() const override {
    return samplerate;
  }

  virtual bool equalsTo(const SampleRate &) const override {
    return samplerate == other.samplerate;
  }
  
  std::string toString() const override {
    return NumberToString(samplerate);
  }
};

bool operator==(const SampleRate &s1, const SampleRate &s2) {
 return s1.equalsTo(s2);
}

bool operator!=(const SampleRate &s1, const SampleRate &s2) {
 return !(s1 == s2);
}

std::ostream & operator<<(ostream & os, const SampleRate &sr) {
 return os << sr.toString();
}
