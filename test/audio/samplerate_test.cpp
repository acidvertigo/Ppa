#include "gmock/gmock.h"

#include "audio/SampleRate.h"

using namespace ::Ppa::Audio;

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

TEST_F(SampleRateTest, testGetSampleRate) {
  EXPECT_EQ(sp->GetSampleRate(), 44100);
}

TEST_F(SampleRateTest, testToString) {
  EXPECT_EQ(sp->toString(), "44100");
}

//————————————————————————————————————-
class SrInterface {
 public:
  virtual ~SrInterface();
  virtual bool Equals(const SampleRate&, const SampleRate&) = 0;
  virtual bool notEquals(const SampleRate&, const SampleRate&) = 0;
};

class RealMock : public SrInterface {
 public:
  virtual ~RealMock() {}
  virtual bool Equals(const SampleRate& s1, const SampleRate& s2) { return s1 == s2; }
  virtual bool notEquals(const SampleRate& s1, const SampleRate& s2) {
    return !(s1 == s2);
  }
};

class SrMock : public SrInterface {
 public:
  MOCK_METHOD2(Equals, bool(const SampleRate& s1, const SampleRate& s2));
  MOCK_METHOD2(notEquals, bool(const SampleRate& s1, const SampleRate& s2));
};

SrMock srMock;
void Equals(const SampleRate& s1, const SampleRate& s2) {
  srMock.Equals(s1, s2);
}

void notEquals(const SampleRate& s1, const SampleRate& s2) {
  srMock.notEquals(s1, s2);
}

using ::testing::Return;

TEST(SampleRateTest, testIsEqual) {
  SampleRate* s1;
  SampleRate* s2;

  s1 = new SampleRate(44100);
  s2 = new SampleRate(44100);

  SrMock srMock;
  EXPECT_CALL(srMock, Equals(s1, s2));
  // . WillOnce(Return(true));
}

TEST(SampleRateTest, testNotEqual) {
  SampleRate* s1;
  SampleRate* s2;

  s1 = new SampleRate(44100);
  s2 = new SampleRate(88200);

  SrMock srMock;
  EXPECT_CALL(srMock, notEquals(s1, s2));
  // . WillOnce(Return(true));
}