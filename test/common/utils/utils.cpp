#include "utils.h"

using Test::Common::Utils;

  int libStringTest()
  {
    NumberToStringTest();
    StringToNumberTest();
  }
      
  int libRangeTest()
  {
    containsTest();
    notContainsTest();
  }