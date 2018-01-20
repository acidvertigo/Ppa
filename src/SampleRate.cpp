/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include <string>
#include "SampleRate.h"
#include "libString.h"

SampleRate::SampleRate() {
   SampleRate = 0;
}
SampleRate::SampleRate(int sampleratec) {
   samplerate = sampleratec;
}

int SampleRate::getSamplerate() {
   return samplerate;
}

string SampleRate::toString() {
   return NumberToString(samplerate);
}

bool operator==(SampleRate s1, SampleRate s2) {
   return s1.samplerate == s2.samplerate;
}

bool operator!=(SampleRate s1, SampleRate s2) {
   return !(s1 == s2);
}

ostream & operator<<(ostream & os, SampleRate sr) {
   return os << sr.toString();
}