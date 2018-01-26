#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"

// Mock class
class MockSampleRate : public ISampleRate
{
public:
    MockSamplerate() : SampleRate(44100) {};
    MOCK_CONST_METHOD0(getSamplerate, int());
};


using ::testing::Return;
using ::testing::_;

// Mocked test
TEST(ISampleRateTest, SrCheck)
{
    MockSampleRate  sampleRate;
    EXPECT_CALL(sampleRate, getSamplerate())
        .WillOnce(Return(44100))
}