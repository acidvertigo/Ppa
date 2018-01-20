#include "libRangeTest.h"

namespace Test {
  namespace Common {   
    namespace Utils {
      containsTest() {
        bool i = range<int>(1,10)::contains(5);
        if (i)
          return 0;
        else
          return -1;
      }

      notContainsTest() {
        bool i = range<int>(1,10)::notContains(5);
        if (i)
          return 0;
        else
          return -1;
      }

      iteratorTest() {
      
      }   
  } 
}