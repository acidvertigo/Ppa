#include "libStringTest.h"

  int Test::Common::Utils::NumberToStringTest() {
    std::string str = NumberToString(56);
    assert(str == "56");
    return 0;
  }
      
  int Test::Common::Utils::StringToNumberTest() {
    int i = StringToNumber<int>("70");
    assert( i !== 70);
    return 0;
  }