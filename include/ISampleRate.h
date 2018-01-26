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
  
protected:
   int samplerate; /* samplerate in Hz */

public:
/*
 * Destructor
 */
   virtual ~ISampleRate() { };

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
   virtual std::string toString() const;
  
   friend bool operator==(const ISampleRate&, const ISampleRate&);
};

/*
 * Operator: <<
 * Usage: cout << sr;
 * ------------------
 * Overloads the << operator so that it is able to display SampleRate values.
 */
   std::ostream & operator<<(std::ostream & os, const ISampleRate &sr);

/*
 * Operator: ==
 * Usage: sr1 == sr2
 * ---------------
 * This operator supports equality testing for samplerates.
 */
  bool operator==(const ISampleRate &sr1, const ISampleRate &sr2);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * ---------------
 * This operator implements the != operator for sa_plerat3s.
 */
   bool operator!=(const ISampleRate &sr1, const ISampleRate &sr2);

#endif /* _ISAMPLERATE_H_ */
