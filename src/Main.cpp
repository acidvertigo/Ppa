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
  cout << "Hello World!" << std::endl;
  cout << "Samplerate value is: " << sm.GetSampleRate(); << endl;
  return 0;
}
