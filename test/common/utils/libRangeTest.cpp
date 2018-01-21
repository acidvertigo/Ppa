#include <assert.h>
#include "libRangeTest.h"

     int Test::Common::Utils::containsTest() {
        assert(range<int>(1,10));
        return 0;
      }

      int Test::Common::Utils::notContainsTest() {
        assert(range<int>(1,10).notContains(5));
        return 0;
      }

      int Test::Common::Utils::iteratorTest() {
      
      }   
