#include "audio/SampleRate.h"

using namespace ::Ppa::Audio;

class SampleRateTest : public ::testing::Test
{
public:
    SampleRateTest() {}
    virtual ~SampleRateTest() {}

protected:
     Shared * sm;
 
     virtual void SetUp() override
     {      
         sm = new SampleRate(11);
     }

     virtual void TearDown() override
     {
        delete sm;
     }
};

TEST_F(SampleRateTest, smTest)
{
    ASSERT_EQ(sm->getSampleRate(), 11);
}
