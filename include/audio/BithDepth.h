/*
 * File: BitDepth.h
 * -------------
 * This interface exports the BitDepth class, which represents audio
 * bit depth.
 */
#ifndef _BITDEPTH_H_
#define _BITDEPTH_H_

#include <iostream>

#include "audio_export.h"
#include "ISampleRate.h"

namespace Ppa {
namespace Audio {

/*
 * Derived classes definitions
 */
class BithDepth : public IBithDepth {
 public:
  AUDIO_EXPORT BithDepth(int bitdepthc);
  AUDIO_EXPORT ~BithDepth() override;

  int AUDIO_EXPORT GetBitDepth() const override;
  std::string AUDIO_EXPORT toString() const override;

  /*
   * friend method needed from comparison operator
   */
  friend bool operator==(const BitDepth&, const BitDepth&);

 protected:
  int bithdepth; /* bit depth */
};

/*
 * Operator: <<
 * Usage: cout << sr;
 * ------------------
 * Overloads the << operator so that it is able to display BitDepth values.
 */
AUDIO_EXPORT std::ostream& operator<<(std::ostream&, const BitDepth&);

/*
 * Operator: ==
 * Usage: sr1 == sr2
 * -----------------
 * This operator supports equality testing for BitDepths.
 */
AUDIO_EXPORT bool operator==(const BitDepth&, const BitDepth&);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * -----------------
 * This operator implements the != operator for BitDepth.
 */
AUDIO_EXPORT bool operator!=(const BitDepth&, const BitDepth&);

}  // namespace Audio end
}  // namespace Ppa end

#endif /* _BITDEPTH_H_ */
