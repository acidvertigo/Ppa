#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"

using namespace std;

// Mock class
class MockSampleRate : public ISampleRate {
public:
    virtual ~MockSampleRate() = default;
    MOCK_CONST_METHOD0(getSamplerate, int());
    MOCK_CONST_METHOD0(toString, string());
};

using ::testing::Return;
using ::testing::_;

// Mocked test
TEST(SampleRateTest, SrCheck)
{
    MockSampleRate  sampleRate;
    EXPECT_CALL(sampleRate, getSamplerate())
        .WillOnce(Return(0));
}

//---------------------------
class SROperatorInterface {
  virtual bool operator==(const SampleRate &s1, const SampleRate &s2) = 0;
  virtual bool operator!=(const SampleRate &s1, const SampleRate &s2) = 0;
  virtual std::ostream & operator<<(ostream & os, const SampleRate &sr) = 0;
};

class SRMockOperator : SROperatorInterface {
public:
  virtual bool operator==(const SampleRate &s1, const SampleRate &s2) {
    return s1.samplerate == s2.samplerate;
  }

  virtual bool operator!=(const SampleRate &s1, const SampleRate &s2) {
    return !(s1 == s2);  
  }

  virtual std::ostream & operator<<(ostream & os, const SampleRate &sr) { 
    return os << sr.toString();
  }
};

