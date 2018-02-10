/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include "audio/SampleRate.h"
#include "common/String.h"

using namespace std;
using namespace Ppa::Common;

namespace Ppa {
namespace Audio {

/*
 * Constructor: SampleRate
 * Usage: Samplerate sr(int sampleratec);
 * ------------------------
 * Creates a SampleRate object.  The parameter sets the samplerate;
 */
SampleRate::SampleRate(int sampleratec) : samplerate(0), allowed{22050,44100,48000,88200,96000,172000,196000} {
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

bool operator==(const SampleRate& s1, const SampleRate& s2) {
  return s1.samplerate == s2.samplerate;
}

bool operator!=(const SampleRate& s1, const SampleRate& s2) {
  return !(s1 == s2);
}

ostream& operator<<(ostream& os, const SampleRate& sr) {
  return os << sr.toString();
}

}  // namespace Audio end
}  // namespace Ppa end
