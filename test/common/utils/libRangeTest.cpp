#include <assert.h>
#include "libRangeTest.h"

     int Test::Common::Utils::containsTest() {
        assert(range<int>(1,10).contains(5));
        return 0;
      }

      int Test::Common::Utils::notContainsTest() {
        assert(range<int>(1,10).notContains(5));
        return 0;
      }

      int Test::Common::Utils::iteratorTest() {
        std::vector<int> myvector;
        std::vector<int> testvector = {1,2,3,4,5};
 
        for (auto i; range<int>(1,5))
          myvector.push_back (i);
        
        assert(myvector == testvector);     
        return 0;
      }   
