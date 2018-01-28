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
  virtual int print(const SampleRate &sr) = 0;
};

// Mock operator interface class
class SRMockOperator : public SROperatorInterface {
public:
  virtual ~SRMockOperator() = default;
  bool isEqual(const SampleRate &s1, const SampleRate &s2) {
    return s1 == s2;
  }

  bool notEqual(const SampleRate &s1, const SampleRate &s2) {
    return !(s1 == s2);  
  }

  int print(const SampleRate &sr) { 
    cout << sr;
  }
};

// Mocked interface test
TEST(SROperatorTest, SrOperatorCheck)
{
    SRMockOperator opeR;
    SRMockOperator opeR2;
    EXPECT_CALL(opeR, isEqual(opeR, opeR2))
        .WillOnce(Return(true));
}