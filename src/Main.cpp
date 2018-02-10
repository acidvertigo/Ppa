/* File: Main.cpp
 * --------------
 * Main Application file
 */
#include <cstdlib>
#include <iostream>

#include "audio/SampleRate.h"

using namespace std;
using namespace Ppa::Audio;

int main() {
  try {
  SampleRate * sm;
  SampleRate * sm2;

  sm  = new SampleRate(44100);
  sm2 = new SampleRate(44100);

  bool verdict = (*sm == *sm2);
  cout << "Hello World!" << endl;
  cout << "Samplerate value is: " << sm->GetSampleRate() << endl;
  cout << boolalpha << verdict << endl;
  } catch (...) { // deal with all other exceptions
    throw;
    exit(EXIT_FAILURE);
  }

  return 0;
}
