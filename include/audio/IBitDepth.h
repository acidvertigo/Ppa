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

/*
 * Method: IsFloat
 * Usage: bool fp = bd.isFloat();
 * —————————————————————————————-
 * Returns if current bit depth is floating point.
 */
   virtual bool IsFloat() const = 0;

};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IBITDEPTH_H_ */
