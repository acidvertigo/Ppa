/* File: Main.cpp
 * --------------
 * Main Application file
 */

#include <iostream>

#include "audio/SampleRate.h"

using namespace std;
using namespace Ppa::Audio;

int main() {
  SampleRate * sm
  SampleRate * sm2;

  sm  = new SampleRate(44100);
  sm2 = new SampleRate(44100);

  bool verdict = (*sm == *sm2);
  cout << "Hello World!" << endl;
  cout << "Samplerate value is: " << sm->GetSampleRate() << endl;
  cout << verdict << endl;
  return 0;
}
