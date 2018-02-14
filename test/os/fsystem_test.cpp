#include "gtest/gtest.h"
#include "os/FSystem.h"

using namespace ::Ppa::Os;

//----------------------------------------
class FsystemTest : public ::testing::Test {
 public:
  FsystemTest() {}
  ~FsystemTest() {}

 protected:
  FSystem* fs
  FSystem* fs2;

  virtual void SetUp() override {
    fs = new FSystem("piano.waw");
    fs2 = new FSystem("piano.wav");
  }

  virtual void TearDown() override {
    delete fs;
    delete fs2;
  }
};

TEST_F(ChannelTest, testGetFileName) {
  EXPECT_EQ(ch->GetFilename(), "piano.wav");
}

