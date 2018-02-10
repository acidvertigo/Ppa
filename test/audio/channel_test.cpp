#include "gtest/gtest.h"
#include "audio/Channel.h"

using namespace ::Ppa::Audio;

//----------------------------------------
class ChannelTest : public ::testing::Test {
 public:
  ChannelTest() {}
  ~ChannelTest() {}

 protected:
  Channel* ch;
  Channel* ch2;

  virtual void SetUp() override {
    ch = new Channel("piano", 1);
    ch2 = new Channel("piano", 1);
  }

  virtual void TearDown() override {
    delete ch;
    delete ch2;
  }
};

TEST_F(ChannelTest, testGetName) {
  EXPECT_EQ(ch->GetName(), "piano");
}

TEST_F(ChannelTest, testGetNumber) {
  EXPECT_EQ(ch->GetNumber(), 1);
}

TEST_F(ChannelTest, testToString) {
  EXPECT_EQ(ch->toString(), "piano1");
}

//-----------------------------------
TEST_F(ChannelTest, testIsEqual) {
  ASSERT_TRUE(*ch == *ch2);
}

TEST_F(ChannelTest, testNotEqual) {
  SampleRate* ch;
  SampleRate* ch2;

  ch = new Channel("piano", 1);
  ch2 = new Channel("guitar", 2);

  ASSERT_FALSE(*ch == *ch2);
}

TEST_F(ChannelTest, testSstream) {
    std::stringstream out;
    Channel chl("piano", 1);
    out << chl;
    ASSERT_TRUE(out.str() == "piano1");
}

