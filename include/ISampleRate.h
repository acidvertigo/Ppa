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

//---------------------------------------

/*
 * Derived classes definitions
 */   
class SampleRate: public ISampleRate 
{  
public:
    SampleRate(const int &);
    virtual ~SampleRate() override;
    int getSamplerate() const override;
    bool equalTo(const SampleRate &) const;
    std::string toString() const override;
};

//--------------------------------------

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
 * -----------------
 * This operator supports equality testing for samplerates.
 */
   bool operator==(const ISampleRate &sr1, const ISampleRate &sr2);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * -----------------
 * This operator implements the != operator for sa_plerat3s.
 */
   bool operator!=(const ISampleRate &sr1, const ISampleRate &sr2);

#endif /* _ISAMPLERATE_H_ */
