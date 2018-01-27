#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"
#include "libString.h"
  
// Mock class
class MockSampleRate : public SampleRate
{
public:
    MOCK_METHOD1(SampleRate, int(const int &sampleratec));
    MOCK_METHOD0(getSamplerate, int());
    MOCK_METHOD1(equalTo, bool(const SampleRate &other));
};

using ::testing::Return;
using ::testing::_;

// Mocked test
TEST(SampleRateTest, SrCheck)
{
    SampleRate  sampleRate(44100);
    EXPECT_CALL(sampleRate, getSamplerate())
        .WillOnce(Return(44100));
    EXPECT_CALL(sampleRate, equalTo(_))
        .WillOnce(Return(true));
}