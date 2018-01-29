#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ISampleRate.h"
#include "SampleRate.h"

using namespace std;
using namespace Paa;

namespace Test {
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
  /*
class SROperatorInterface {
public:
  virtual ~SROperatorInterface() = default;
  virtual bool operator==(const SROperatorInterface &) = 0;

  virtual bool isEqual(const SampleRate &s2) = 0;
  virtual bool notEqual(const SampleRate &s1, const SampleRate &s2) = 0;
  virtual int print(const SampleRate &sr) = 0;

};

// Mock operator interface class
class SRMockOperator : public SROperatorInterface {
public:
  virtual ~SRMockOperator() = default;
  MOCK_METHOD1(Equals, bool(const SROperatorInterface &));
  virtual bool operator==(const SROperatorInterface & rhs) { return SROperatorInterface(rhs); }
  
   MOCK_METHOD2(isEqual, bool(const SampleRate &s1, const SampleRate &s2));
  MOCK_METHOD2(notEqual, bool(const SampleRate &s1, const SampleRate &s2));
  MOCK_METHOD1(print, int(const SampleRate &sr));
  bool isEqual(const Paa::SampleRate &s2) {
    return this == &s2;
  }
 
}; 

// Mocked interface test
TEST(SROperatorTest, SrOperatorCheck)
{
    SRMockOperator opeR;
    SRMockOperator opeR2;

    EXPECT_CALL(opeR, Equals(opeR2))
        .WillOnce(Return(true));
}
}
*/