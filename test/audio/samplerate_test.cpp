#include "gtest/gtest.h"

#include "audio/SampleRate.h"

using namespace ::Ppa::Audio;

class SampleRateTest : public ::testing::Test
{
public:
     SampleRateTest() {}
     ~SampleRateTest() {}
     
protected:
     SampleRate * sm;
     SampleRate * sm2;
 
     virtual void SetUp() override
     {      
         sm  = new SampleRate(44100);
         sm2 = new SampleRate(44100);
     }

     virtual void TearDown() override
     {
        delete sm;
        delete sm2;
     }
};

TEST_F(SampleRateTest, GetSampleRate)
{
    ASSERT_EQ(sm->GetSampleRate(), 44100);
}

TEST_F(SampleRateTest, toString)
{
    ASSERT_EQ(sm->toString(), "44100");
}

// Test comprison operator
TEST_F(SampleRateTest, isEqual)
{
    ASSERT_EQ(sm, sm2);
}
