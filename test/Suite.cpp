/* File: Suite.cpp
 * -------------------
 * This file implements the main test suite
 */
#include <assert.h>
#include "SampleRateTest.h"
#include "common/utils/utils.h"

int main() {
  SampleRateTest();
  Test::Common::Utils::libStringTest();
  Test::Common::Utils::libRangeTest();
  return 0;
}