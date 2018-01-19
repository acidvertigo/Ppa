/*
 * File: SampleRate.h
 * -------------
 * This interface exports the SampleRate class, which represents audio
 * sample rate frequency.
 */
#ifndef _SAMPLERATE_H
#define _SAMPLERATE_H

#include <string>

class SampleRate {

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
   int getSampleRate();
    
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
 * This operator implements the != operator for points.  It is good
 * practice to overload this operator whenever you overload == to
 * ensure that clients can perform either test.
 */
   bool operator!=(Samplerate sr1, Samplerate sr2);

/*
 * Method: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Returns a string representation of the samplerate.
 */
   std::string toString();

private:
   int samplerate; /* samplerate in Hz */
    
}; 

#endif /* _SAMPLERATE_H_ */