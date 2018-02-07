/* File: Main.cpp
 * --------------
 * Main Application file
 */

#include <iostream>
#include "audio/SampleRate.h"

using namespace std;
using namespace Ppa::Audio;

int main() {
  SampleRate sm(44100);
  SampleRate sm2(44100);
  bool verdict = sm == sm2;
  cout << "Hello World!" << endl;
  cout << "Samplerate value is: " << sm.GetSampleRate() << endl;
  cout << verdict << endl;
  return 0;
}
