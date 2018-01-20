#include "libStringTest.h"

namespace Test {
  namespace Common {   
    namespace Utils {
      
      int NumberToStringTest() {
       std::string str = NumberToString(56);
       if (str == "56")
         return 0;
       else
         return -1;
      }
      
      int StringToNumberTest() {
       int i = StringToNumber<std::string> ( "70" );
       if( i == 70)
         return 0;
       else
         return -1;
      }
    
    }   
  } 
}