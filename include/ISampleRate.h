/*
 * File: SampleRate.h
 * -------------
 * This interface exports the SampleRate class, which represents audio
 * sample rate frequency.
 */
#ifndef _ISAMPLERATE_H
#define _ISAMPLERATE_H

#include <iostream>
#include <string>

class ISampleRate {
  
public:

   virtual ~ISampleRate() { };

/*
 * Methods: getSampleRate
 * Usage: int x = sr.getSampleRate();
 * ----------------------------------
 * These methods returns the samplerate set
 */
   virtual int getSamplerate() const = 0;
  
/*
 * Method: equalTo
 * Usage: bool x = sr1.equalsTo(sr2);
 * ----------------------------------
 * Returns true if properties are equal
 */
   virtual bool equalTo(const ISampleRate &other) const = 0;

/*
 * Method: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Returns a string representation of the samplerate.
 */
   virtual std::string toString() const = 0;

protected:
   int samplerate; /* samplerate in Hz */

};  

#endif /* _ISAMPLERATE_H_ */
