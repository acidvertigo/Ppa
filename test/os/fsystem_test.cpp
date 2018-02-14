#include "gtest/gtest.h"
#include "os/FSystem.h"

using namespace ::Ppa::Os;

//----------------------------------------
class FsystemTest : public ::testing::Test {
 public:
  FsystemTest() {}
  ~FsystemTest() {}

 protected:
  FSystem* fs;
  FSystem* fs2;

  virtual void SetUp() override {
    fs = new FSystem("piano.wav");
    fs2 = new FSystem("piano.wav");
  }

  virtual void TearDown() override {
    delete fs;
    delete fs2;
  }
};

TEST_F(FsystemTest, testGetFileName) {
  EXPECT_EQ(fs->GetFilename(), "piano.wav");
}

//-----------------------------------
TEST_F(FsystemTest, testIsEqual) {
  ASSERT_TRUE(*ch == *ch2);
}

TEST_F(FsystemTest, testNotEqual) {
  FSystem* fs;
  FSystem* fs2;

  fs = new FSystem("piano.wav");
  fs2 = new FSystem("guitar.wav");

  ASSERT_FALSE(*fs == *fs2);
}

TEST_F(FsystemTest, testSstream) {
    std::stringstream out;
    FSystem fsys("piano.wav");
    out << fsys;
    ASSERT_TRUE(out.str() == "piano.wav");
}
