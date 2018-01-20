#include <assert.h>
#include "libRangeTest.h"

     int Test::Common::Utils::containsTest() {
        static_assert(range<int>(1,10)::contains(5), "Unable to find if integer 5 is in range (1,10)");
      }

      int Test::Common::Utils::notContainsTest() {
        static_assert(range<int>(1,10)::notContains(5),  "Unable to find if integer 5 is not in range (1,10)");
      }

      int Test::Common::Utils::iteratorTest() {
      
      }   
