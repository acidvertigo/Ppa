/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include "ISampleRate.h"
#include "SampleRate.h"
#include "libString.h"

using namespace std;

namespace Paa {

/*
 * Constructor: SampleRate
 * Usage: Samplerate sr(sampleratec);
 * ------------------------
 * Creates a SampleRate object.  The parameter sets the samplerate;
 */
  SampleRate::SampleRate(const int &sampleratec) : samplerate(0) {
    samplerate = sampleratec;
  }

  SampleRate::~SampleRate() = default;

  int SampleRate::getSamplerate() const {
    return samplerate;
  }

  std::string SampleRate::toString() const {
    return NumberToString(samplerate);
  }

//------------------------------------

bool operator==(const SampleRate &s1, const SampleRate &s2) {
 return s1.samplerate == s2.samplerate;
}

bool operator!=(const SampleRate &s1, const SampleRate &s2) {
 return !(s1 == s2);
}

std::ostream & operator<<(ostream & os, const SampleRate &sr) {
 return os << sr.toString();
}
}