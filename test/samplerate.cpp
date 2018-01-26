#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"

// Mock class
class MockSampleRate : public ISampleRate
{
public:
    MOCK_METHOD0(construct, int(44100));
    MOCK_CONST_METHOD0(getSamplerate, int());
    MOCK_CONST_METHOD1(equalTo, bool(const ISampleRate &other));
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