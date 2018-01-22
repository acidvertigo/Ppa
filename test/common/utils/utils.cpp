#include "utils.h"
#include "libRangeTest.h"
#include "libStringTest.h"

  int Test::Common::Utils::libStringTest()
  {
    Test::Common::Utils::NumberToStringTest();
    Test::Common::Utils::StringToNumberTest();
    return 0;
  }
      
  int Test::Common::Utils::libRangeTest()
  {
    Test::Common::Utils::containsTest();
    Test::Common::Utils::notContainsTest();
    return 0;
  }