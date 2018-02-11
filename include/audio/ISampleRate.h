/*
 * File: ISampleRate.h
 * -------------
 * Interface for the SampleRate class.
 */
#ifndef _ISAMPLERATE_H_
#define _ISAMPLERATE_H_

#include <string>

namespace Ppa {
namespace Audio {

class ISampleRate {
  
public:
   virtual ~ISampleRate() = default;

/*
 * Methods: getSampleRate
 * Usage: int x = sr.getSampleRate();
 * ----------------------------------
 * These methods returns the samplerate set
 */
   virtual int GetSampleRate() const = 0;

/*
 * Method: toString
 * Usage: string str = sr.toString();
 * ----------------------------------
 * Returns a string representation of the samplerate.
 */
   virtual std::string toString() const = 0;

protected:
/*
 * Method: IsValid
 * Usage: bool ok = sr.IsValid(48000);
 * ———————————————————————————————-
 * Check if bit depth value is allowed
 */
   virtual bool IsValid(const int&) const = 0;

};

} // namespace Audio end
} // namespace Ppa end

#endif /* _ISAMPLERATE_H_ */
