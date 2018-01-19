/*
 * File: SampleRate.cpp
 * ---------------
 * This file implements the SampleRate.h interface.
 */
#include <string>
#include "SampleRate.h"

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
   return "(" + integerToString(x) + "," + integerToString(y) + ")";
}

bool operator==(SampleRate s1, SampleRate s2) {
   return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(SampleRate s1, SampleRate s2) {
   return !(p1 == p2);
}

ostream & operator<<(ostream & os, SampleRate sr) {
   return os << sr.toString();
}