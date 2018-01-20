/*
 * File: SampleRate.h
 * -------------
 * This interface exports the SampleRate class, which represents audio
 * sample rate frequency.
 */
#ifndef _SAMPLERATE_H
#define _SAMPLERATE_H

#include <iostream>
#include <string>

class SampleRate {
  
private:
   int samplerate; /* samplerate in Hz */

public:
/*
 * Constructor: SampleRate
 * Usage: SampleRate origin;
 *        Samplerate sr(sampleratec);
 * ------------------------
 * Creates a SampleRate object.  The default constructor sets the coordinates
 * to 0; the second form sets the samplerate.
 */
   SampleRate();
   SampleRate(int sampleratec);

/*
 * Methods: getSampleRate
 * Usage: int x = sr.getSampleRate();
 * -------------------------
 * These methods returns the samplerate set
 */
   int getSamplerate();


/*
 * Operator: <<
 * Usage: cout << sr;
 * ------------------
 * Overloads the << operator so that it is able to display SampleRate values.
 */
   std::ostream & operator<<(std::ostream & os, const SampleRate& sr);

/*
 * Operator: ==
 * Usage: sr1 == sr2
 * ---------------
 * This operator supports equality testing for samplerates.
 */
   bool operator==(SampleRate sr1, SampleRate sr2);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * ---------------
 * This operator implements the != operator for sa_plerat3s.
 */
   bool operator!=(SampleRate sr1, SampleRate sr2);

/*
 * Method: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Returns a string representation of the samplerate.
 */
   std::string toString();

/* friend declaration needed by == operator to access private properties */
   friend bool operator==(SampleRate sr1, SampleRate sr2);

}; 

#endif /* _SAMPLERATE_H_ */