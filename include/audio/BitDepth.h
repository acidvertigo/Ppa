/*
 * File: BitDepth.h
 * -------------
 * This interface exports the BitDepth class, which represents audio
 * bit depth.
 */
#ifndef _BITDEPTH_H_
#define _BITDEPTH_H_

#include "audio_export.h"
#include "IBitDepth.h"

#include <iostream>
#include <set>

namespace Ppa {
namespace Audio {

/*
 * Derived classes definitions
 */
class BitDepth : public IBitDepth {
 public:
  AUDIO_EXPORT BitDepth(int bitdepthc);
  AUDIO_EXPORT ~BitDepth() override;

  AUDIO_EXPORT int GetBitDepth() const override;

  AUDIO_EXPORT std::string toString() const override;

  /*
   * friend method needed from comparison operator
   */
  AUDIO_EXPORT friend bool operator==(const BitDepth&, const BitDepth&);

 protected:
  int bitdepth;    /* integer bit depth */
  std::set<int> allowed; /* allowed values */

  bool IsValid(const int&) const override;
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
