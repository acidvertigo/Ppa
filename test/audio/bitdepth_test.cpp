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
    delete bd;
    delete bd2;
  }
};


TEST_F(BitDepthTest, testGetBitDepth) {
  EXPECT_EQ(bd->GetBitDepth(), 44100);
}

TEST_F(BitDepthTest, testToString) {
  EXPECT_EQ(bd->toString(), "44100");
}

//-----------------------------------
TEST_F(BitDepthTest, testIsEqual) {
  ASSERT_TRUE(*bd == *bd2);
}

TEST_F(BitDepthTest, testNotEqual) {
  BitDepth* bd;
  BitDepth* bd2;

  bd = new BitDepth(44100);
  bd2 = new BitDepth(88200);

  ASSERT_FALSE(*bd == *bd2);
}

TEST_F(BitDepthTest, testSstream) {
    std::stringstream out;
    BitDepth bd(44100);
    out << bd;
    ASSERT_TRUE(out.str() == "44100");
}

