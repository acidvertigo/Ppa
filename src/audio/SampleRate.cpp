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
SampleRate::SampleRate(int sampleratec) : 
samplerate(sampleratec),
allowed{8000,11025,16000,22050,44100,48000,88200,96000,176400,196000,352800,364000} {
  if (!IsValid(sampleratec))
    throw invalid_argument( "samplerate value not allowed" );
}

SampleRate::~SampleRate() = default;

//—————————————————————————————————————
int SampleRate::GetSampleRate() const {
  return samplerate;
}

//———————————————————————————————————
string SampleRate::toString() const {
  return NumberToString(samplerate);
}

//———————————————————————————————————————————————-
bool SampleRate::IsValid(const int& value) const {
  return allowed.count(value) != 0;
}

//----------------------------------————————————————————————-
bool operator==(const SampleRate& s1, const SampleRate& s2) {
  return s1.samplerate == s2.samplerate;
}

//——————————————————————————————————————————————————————————-
bool operator!=(const SampleRate& s1, const SampleRate& s2) {
  return !(s1 == s2);
}

//—————————————————————————————————————————————————————-
ostream& operator<<(ostream& os, const SampleRate& sr) {
  return os << sr.toString();
}

}  // namespace Audio end
}  // namespace Ppa end
