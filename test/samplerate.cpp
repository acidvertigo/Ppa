#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"
#include "SampleRate.h"
#include "libString.h"
  
// Mock class
class MockSampleRate : public SampleRate {
public:
    MockSampleRate(const int &sampleratec) : SampleRate::SampleRate(sampleratec) {};
    virtual ~MockSampleRate() {};
    MOCK_METHOD1(SampleRate, int(const int &sampleratec));
    MOCK_METHOD0(getSamplerate, int());
//    MOCK_METHOD1(equalTo, bool(const MockSampleRate &other));
    MOCK_METHOD0(toString, bool());
};

using ::testing::Return;
using ::testing::_;

// Mocked test
TEST(SampleRateTest, SrCheck)
{
    MockSampleRate  sampleRate(44100);
    EXPECT_CALL(sampleRate, getSamplerate())
        .WillOnce(Return(44100));
   // EXPECT_CALL(sampleRate, equalTo(_))
        .WillOnce(Return(true));
}