#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"

using namespace std;

// Mock interface class
class MockISampleRate : public ISampleRate {
public:
    virtual ~MockISampleRate() = default;
    MOCK_CONST_METHOD0(getSamplerate, int());
    MOCK_CONST_METHOD0(toString, string());
};

using ::testing::Return;
using ::testing::_;

// Mocked interface test
TEST(SampleRateTest, SrCheck)
{
    MockISampleRate  sampleRate;
    EXPECT_CALL(sampleRate, getSamplerate())
        .WillOnce(Return(0));
}

//---------------------------
// Operator interface
class SROperatorInterface {
  virtual bool isEqual(const SampleRate &s1, const SampleRate &s2) = 0;
  virtual bool notEqual!=(const SampleRate &s1, const SampleRate &s2) = 0;
  virtual std::ostream print(ostream & os, const SampleRate &sr) = 0;
};

// Mock operator interface class
class SRMockOperator : SROperatorInterface {
public:
  virtual bool isEqual(const SampleRate &s1, const SampleRate &s2) {
    return s1 == s2;
  }

  virtual bool notEqual(const Sam0leRate &s1, const SampleRate &S2) {
    return !(s1 == s2);  
  }

  virtual std::ostream (ostream & os, const SampleRate &sr) { 
    return os << sr;
  }
};

