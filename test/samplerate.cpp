#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"

// Mock class
class MockSampleRate : public ISampleRate
{
public:
    MOCK_METHOD1(SampleRate, int(const int &sampleratec));
    MOCK_METHOD0(getSamplerate, int());
    MOCK_METHOD1(equalTo, bool(const ISampleRate &other));
};

using ::testing::Return;
using ::testing::_;

// Mocked test
TEST(ISampleRateTest, SrCheck)
{
    SampleRate  sampleRate(44100);
    EXPECT_CALL(sampleRate, getSamplerate())
        .WillOnce(Return(44100));
    EXPECT_CALL(sampleRate, equalTo(_))
        .WillOnce(Return(true));
}