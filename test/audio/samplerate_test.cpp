#include "gtest/gmock.h"

#include "audio/SampleRate.h"

using namespace ::Ppa::Audio;

class SampleRateTest : public ::testing::Test
{
public:
     SampleRateTest() {}
     ~SampleRateTest() {}

protected:
     SampleRate * sp;
     SampleRate * sp2;
 
     virtual void SetUp() override
     {      
         sp  = new SampleRate(44100);
         sp2 = new SampleRate(44100);
     }

     virtual void TearDown() override
     {
        delete sp;
        delete sp2;
     }
};

TEST_F(SampleRateTest, testGetSampleRate)
{
    EXPECT_EQ(sp->GetSampleRate(), 44100);
}

TEST_F(SampleRateTest, testToString)
{
    EXPECT_EQ(sp->toString(), "44100");
}

class SrInterface {
 public:
  virtual bool compare(const SampleRate &s1, const SampleRate &s2) = 0;
  MOCK_METHOD2(compare, bool(const SampleRate &s1, const SampleRate &s2));
};

class SrMock : public SrInterface, SampleRateTest { 
 public:
  virtual bool compare(const SampleRate &s1, const SampleRate &s2) override {
    return (s1 == s2);
  }
};

SrMock srMock;


TEST(SampleRateTest, testIsEqual)
{
    EXPECT_CALL(SrMock,compare(s1, s2))
        . WillOnce(Return(TRUE));
}