/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include "audio/SampleRate.h"
#include "common/String.h"

using namespace std;
using namespace Ppa::Audio;
using namespace Ppa::Common;

/*
 * Constructor: SampleRate
 * Usage: Samplerate sr(int sampleratec);
 * ------------------------
 * Creates a SampleRate object.  The parameter sets the samplerate;
 */
  SampleRate::SampleRate(int sampleratec) : samplerate(0) {
    samplerate = sampleratec;
  }

  SampleRate::~SampleRate() = default;

  int SampleRate::GetSampleRate() const {
    return samplerate;
  }

  string SampleRate::toString() const {
    return NumberToString(samplerate);
  }

//------------------------------------

  bool Ppa::Audio::operator==(const SampleRate &s1, const SampleRate &s2) const {
    return s1.samplerate == s2.samplerate;
  }

  bool Ppa::Audio::operator!=(const SampleRate &s1, const SampleRate &s2) const {
    return !(s1 == s2);
  }

  std::ostream & Ppa::Audio::operator<<(ostream & os, const SampleRate &sr) {
    return os << sr.toString();
  }
