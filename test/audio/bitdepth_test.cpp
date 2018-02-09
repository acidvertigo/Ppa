#include <sstream>      // std::stringstream

#include "gtest/gtest.h"

#include "audio/BitDepth.h"

using namespace ::Ppa::Audio;

//----------------------------------------
class BitDepthTest : public ::testing::Test {
 public:
  BitDepthTest() {}
  ~BitDepthTest() {}

 protected:
  BitDepth* bd;
  BitDepth* bd2;

  virtual void SetUp() override {
    bd = new BitDepth(16);
    bd2 = new BitDepth(16);
  }

  virtual void TearDown() override {
    delete sp;
    delete sp2;
  }
};


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

