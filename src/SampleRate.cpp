/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include <string>
#include "SampleRate.h"
#include "libString.h"
using namespace std;

SampleRate::SampleRate(int sampleratec = 0) {
   samplerate = sampleratec;
}

int SampleRate::getSamplerate() {
   return samplerate;
}

std::string SampleRate::toString() {
   return NumberToString(samplerate);
}

bool operator==(SampleRate s1, SampleRate s2) {
   return s1.samplerate == s2.samplerate;
}

bool operator!=(SampleRate s1, SampleRate s2) {
   return !(s1 == s2);
}

std::ostream & operator<<(ostream & os, SampleRate sr) {
   return os << sr.toString();
}