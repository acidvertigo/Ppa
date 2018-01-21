#include "utils.h"

using Test::Common::Utils;

  int libStringTest()
  {
    NumberToStringTest();
    StringToNumberTest();
    return 0;
  }
      
  int libRangeTest()
  {
    containsTest();
    notContainsTest();
    return 0;
  }