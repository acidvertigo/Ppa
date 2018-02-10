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

TEST_F(BitDepthTest, testThrowException) {
  BitDepth* bd;
  ASSERT_ANY_THROW(bd = new BitDepth(19));
}

TEST_F(BitDepthTest, testGetBitDepth) {
  EXPECT_EQ(bd->GetBitDepth(), 16);
}

TEST_F(BitDepthTest, testToString) {
  EXPECT_EQ(bd->toString(), "16");
}

//-----------------------------------
TEST_F(BitDepthTest, testIsEqual) {
  ASSERT_TRUE(*bd == *bd2);
}

TEST_F(BitDepthTest, testNotEqual) {
  BitDepth* bd;
  BitDepth* bd2;

  bd = new BitDepth(16);
  bd2 = new BitDepth(24);

  ASSERT_FALSE(*bd == *bd2);
}

TEST_F(BitDepthTest, testSstream) {
    std::stringstream out;
    BitDepth bd(24);
    out << bd;
    ASSERT_TRUE(out.str() == "24");
}

