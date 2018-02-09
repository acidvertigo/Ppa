/*
 * File: SampleRate.h
 * -------------
 * This interface exports the SampleRate class, which represents audio
 * sample rate frequency.
 */
#ifndef _SAMPLERATE_H_
#define _SAMPLERATE_H_

#include <iostream>

#include "audio_export.h"
#include "ISampleRate.h"

namespace Ppa {
namespace Audio {

/*
 * Derived classes definitions
 */
class SampleRate : public ISampleRate {
 public:
  AUDIO_EXPORT SampleRate(int sampleratec);
  AUDIO_EXPORT ~SampleRate() override;

  int AUDIO_EXPORT GetSampleRate() const override;
  std::string AUDIO_EXPORT toString() const override;

  /*
   * friend method needed from comparison operator
   */
  friend bool operator==(const SampleRate& s1, const SampleRate& s2);

 protected:
  int samplerate; /* samplerate in Hz */
};

/*
 * Operator: <<
 * Usage: cout << sr;
 * ------------------
 * Overloads the << operator so that it is able to display SampleRate values.
 */
AUDIO_EXPORT std::ostream& operator<<(std::ostream&, const SampleRate&);

/*
 * Operator: ==
 * Usage: sr1 == sr2
 * -----------------
 * This operator supports equality testing for samplerates.
 */
AUDIO_EXPORT bool operator==(const SampleRate&, const SampleRate&);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * -----------------
 * This operator implements the != operator for samplerate.
 */
AUDIO_EXPORT bool operator!=(const SampleRate&, const SampleRate&);

}  // namespace Audio end
}  // namespace Ppa end

#endif /* _SAMPLERATE_H_ */
