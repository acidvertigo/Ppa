/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include <string>
#include "ISampleRate.h"
#include "libString.h"
using namespace std;

class SampleRate: public ISampleRate
{
public:

  ~SampleRate() override { };

  int getSamplerate() override {
    return getSamplerate();
  }

  std::string toString() override {
    return NumberToString(samplerate);
  }

}

bool operator==(SampleRate s1, SampleRate s2) {
 return s1.getSamplerate() == s2.getSamplerate();
}

bool operator!=(SampleRate s1, SampleRate s2) {
 return !(s1 == s2);
}

std::ostream & operator<<(ostream & os, SampleRate sr) {
 return os << sr.toString();
}