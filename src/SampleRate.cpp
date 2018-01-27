/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include <string>
#include "ISampleRate.h"
#include "libString.h"

using namespace std;

/*
 * Constructor: SampleRate
 * Usage: Samplerate sr(sampleratec);
 * ------------------------
 * Creates a SampleRate object.  The parameter sets the samplerate;
 */
  SampleRate::SampleRate(const int &sampleratec) {
    samplerate = sampleratec;
  }

  SampleRate::~SampleRate() override { };

  int SampleRate::getSamplerate() const override {
    return samplerate;
  }

  bool SampleRate::equalTo(const SampleRate &other) const {
    return samplerate == other.samplerate;
  }
  
  std::string SampleRate::toString() const override {
    return NumberToString(samplerate);
  }

bool operator==(const SampleRate &s1, const SampleRate &s2) {
 return s1.equalTo(s2);
}

bool operator!=(const SampleRate &s1, const SampleRate &s2) {
 return !(s1 == s2);
}

std::ostream & operator<<(ostream & os, const SampleRate &sr) {
 return os << sr.toString();
}
