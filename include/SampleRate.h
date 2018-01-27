#ifndef _ISAMPLERATE_H
#define _ISAMPLERATE_H

#include "ISampleRate.h"

/*
 * Derived classes definitions
 */   
class SampleRate: public ISampleRate {  
public:
    SampleRate(const int &);
    virtual ~SampleRate() override;
    int getSamplerate() const override;
    bool equalTo(const SampleRate &) const;
    std::string toString() const;
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

#endif /* _SAMPLERATE_H_ */