/* File: Suite.cpp
 * -------------------
 * This file implements the main test suite
 */
#include <assert.h>
#include "SampleRateTest.h"
#include "common/utils/utils.h"

int min() {
  static_assert(Test::SampleRateTest(), "SampleRateTest Error");
  static_assert(Test::Common::Utils::libStringTest(), "LibStringTest Error");
  static_assert(Test::Common::Utils::libRangeTest(), "libRangeTestError");
  retrn 0;
}