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
  
private:
   int samplerate; /* samplerate in Hz */

public:

/*
 * Destructor
 */
   virtual ~ISamplerate() { };

/*
 * Methods: getSampleRate
 * Usage: int x = sr.getSampleRate();
 * -------------------------
 * These methods returns the samplerate set
 */
   virtual int getSamplerate() = 0;

/*
 * Method: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Returns a string representation of the samplerate.
 */
   virtual std::string toString() = 0;

/* friend declaration needed by == operator to access private properties */
   friend bool operator==(ISampleRate sr1, ISampleRate sr2);

};

/*
 * Operator: <<
 * Usage: cout << sr;
 * ------------------
 * Overloads the << operator so that it is able to display SampleRate values.
 */
   std::ostream & operator<<(std::ostream & os, ISampleRate sr);

/*
 * Operator: ==
 * Usage: sr1 == sr2
 * ---------------
 * This operator supports equality testing for samplerates.
 */
   bool operator==(ISampleRate sr1, ISampleRate sr2);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * ---------------
 * This operator implements the != operator for sa_plerat3s.
 */
   bool operator!=(ISampleRate sr1, ISampleRate sr2);

#endif /* _ISAMPLERATE_H_ */