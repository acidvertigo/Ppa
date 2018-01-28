/*
 * File: SampleRate.h
 * -------------
 * This interface exports the SampleRate class, which represents audio
 * sample rate frequency.
 */
#ifndef _SAMPLERATE_H_
#define _SAMPLERATE_H_

#include <iostream>
#include "ISampleRate.h"

namespace Paa {
/*
 * Derived classes definitions
 */  
class SampleRate: public ISampleRate {  
public:
    SampleRate(const int &);
    virtual ~SampleRate() override;
    int getSamplerate() const override;
    std::string toString() const;

protected:
    int samplerate; /* samplerate in Hz */
  
friend bool operator==(const SampleRate &sr1, const SampleRate &sr2);

};

//--------------------------------------

/*
 * Operator: <<
 * Usage: cout << sr;
 * ------------------
 * Overloads the << operator so that it is able to display SampleRate values.
 */
   std::ostream & operator<<(std::ostream & os, const SampleRate &sr);

/*
 * Operator: ==
 * Usage: sr1 == sr2
 * -----------------
 * This operator supports equality testing for samplerates.
 */
   bool operator==(const SampleRate &sr1, const SampleRate &sr2);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * -----------------
 * This operator implements the != operator for sa_plerat3s.
 */
   bool operator!=(const SampleRate &sr1, const SampleRate &sr2);
}
#endif /* _SAMPLERATE_H_ */