/*
 * File: ISampleRate.h
 * -------------
 * Interface for the BitDepth class.
 */
#ifndef _IBITDEPTH_H_
#define _IBITDEPTH_H_

#include <string>

namespace Ppa {
namespace Audio {

class IBitDepth {
  
public:

   virtual ~IBitDepth() = default;

/*
 * Method: GetBitDepth
 * Usage: int x = bd.GetBitDepth();
 * ----------------------------------
 * These methods returns the bit depth set
 */
   virtual int GetBitDepth() const = 0;

/*
 * Method: toString
 * Usage: string str = bd.toString();
 * ----------------------------------
 * Returns a string representation of the bit depth.
 */
   virtual std::string toString() const = 0;

 protected:
/*
 * Method: IsValid
 * Usage: bool ok = bd.IsValid(24);
 * ———————————————————————————————-
 * Check if bit depth value is allowed
 */
   virtual bool IsValid(const int&) const = 0;
};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IBITDEPTH_H_ */
