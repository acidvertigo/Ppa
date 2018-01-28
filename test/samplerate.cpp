#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ISampleRate.h"
#include "SampleRate.h"

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
public:
  virtual ~SROperatorInterface() = default;
  virtual bool isEqual(const SampleRate &s1, const SampleRate &s2) = 0;
  virtual bool notEqual(const SampleRate &s1, const SampleRate &s2) = 0;
  virtual std::ostream print(ostream &, const SampleRate &sr) = 0;
};

// Mock operator interface class
class SRMockOperator : SROperatorInterface {
public:
  virtual ~SRMockOperator() = default;
  virtual bool isEqual(const SampleRate &s1, const SampleRate &s2) {
    return s1 == s2;
  }

  virtual bool notEqual(const SampleRate &s1, const SampleRate &s2) {
    return !(s1 == s2);  
  }

  virtual std::ostream (ostream &, const SampleRate &sr) { 
    return os << sr;
  }
};

// Mocked interface test
TEST(SROperatorTest, SrOperatorCheck)
{
    SRMockOperator opeRator;
    SRMockOperator opeRator2;
    EXPECT_CALL(opeRator, isEqual(opeRator, opeRator2))
        .WillOnce(Return(true));
}