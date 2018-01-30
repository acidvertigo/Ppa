/*
 * File: ISampleRate.h
 * -------------
 * Interface for the SampleRate class.
 */
#ifndef _ISAMPLERATE_H_
#define _ISAMPLERATE_H_

#include <string>

//namespace Ppa {
class ISampleRate {
  
public:

   virtual ~ISampleRate() = default;

/*
 * Methods: getSampleRate
 * Usage: int x = sr.getSampleRate();
 * ----------------------------------
 * These methods returns the samplerate set
 */
   virtual int getSamplerate() const = 0;

/*
 * Method: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Returns a string representation of the samplerate.
 */
   virtual std::string toString() const = 0;
};  
//}
#endif /* _ISAMPLERATE_H_ */
