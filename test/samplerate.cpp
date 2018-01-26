#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.php"

// Mock class
class MockSampleRate : public ISampleRate
{
public:
    MockSamplerate() : SampleRate(44100) {};
    MOCK_CONST_METHOD0(getSamplerate, int());
    MOCK_CONST_METHOD0(equalTo, bool(const SampleRate &other));
};


using ::testing::Return;
using ::testing::_;

// Mocked test
TEST(ISampleRateTest, SrCheck)
{
    MockSampleRate  sampleRate;
    EXPECT_CALL(sampleRate, getSamplerate())
        .WillOnce(Return(44100))
    EXPECT_CALL(sampleRate, equalTo(_,_))
        .WillOnce(Return(true))
}