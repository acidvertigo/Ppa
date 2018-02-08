#include "gmock/gmock.h"

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
  virtual ~SrInterface();
  virtual bool Equals(const SampleRate&, const SampleRate&) = 0;
};

class SrMock : public SrInterface { 
 public:
   SrMock() {}
   virtual ~SrMock() {}
   MOCK_METHOD2(Equals, bool(const SampleRate &, const SampleRate &));
   virtual bool Equals(const SampleRate &s1, const SampleRate &s2) {
    return s1 == s2;
  }
};

SrMock srMock;

using ::testing::Return;

TEST(SampleRateTest, testIsEqual)
{
    SampleRate * sp;
    SampleRate * sp2;
     
    sp  = new SampleRate(44100);
    sp2 = new SampleRate(44100);
    
    SrMock srMock;
    EXPECT_CALL(srMock, Equals(sp2));
        // . WillOnce(Return(true));
}