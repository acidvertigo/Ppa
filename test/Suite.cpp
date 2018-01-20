/* File: Suite.cpp
 * -------------------
 * This file implements the main test suite
 */
#include "SampleRateTest.h"
#include "common/utils/utils.h"

int main() {
  Test::SampleRateTest();
  Test::Common::Utils::libStringTest();
  Test::Common::Utils::libRangeTest();
  return 0;
}