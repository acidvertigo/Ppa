#include "gtest/gtest.h"
#include "audio/SampleRate.h"

using namespace ::Ppa::Audio;

//----------------------------------------
class SampleRateTest : public ::testing::Test {
 public:
  SampleRateTest() {}
  ~SampleRateTest() {}

 protected:
  SampleRate* sp;
  SampleRate* sp2;

  virtual void SetUp() override {
    sp = new SampleRate(44100);
    sp2 = new SampleRate(44100);
  }

  virtual void TearDown() override {
    delete sp;
    delete sp2;
  }
};

TEST_F(SampleRateTest, testThrowException) {
  SampleRate* sr;
  ASSERT_ANY_THROW(sr = new SampleRate(19000));
}

TEST_F(SampleRateTest, testGetSampleRate) {
  EXPECT_EQ(sp->GetSampleRate(), 44100);
}

TEST_F(SampleRateTest, testToString) {
  EXPECT_EQ(sp->toString(), "44100");
}

//-----------------------------------
TEST_F(SampleRateTest, testIsEqual) {
  ASSERT_TRUE(*sp == *sp2);
}

TEST_F(SampleRateTest, testNotEqual) {
  SampleRate* sp;
  SampleRate* sp2;

  sp = new SampleRate(44100);
  sp2 = new SampleRate(88200);

  ASSERT_FALSE(*sp == *sp2);
}

TEST_F(SampleRateTest, testSstream) {
    std::stringstream out;
    SampleRate samp(44100);
    out << samp;
    ASSERT_TRUE(out.str() == "44100");
}

