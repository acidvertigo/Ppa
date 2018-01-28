#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"

using ::std;

// Mock class
class MockSampleRate : public ISampleRate {
public:
    virtual ~MockSampleRate() = default;
    MOCK_CONST_METHOD0(getSamplerate, int());
    MOCK_CONST_METHOD0(toString, string());
};

using ::testing::Return;
using ::testing::_;

// Mocked test
TEST(SampleRateTest, SrCheck)
{
    MockSampleRate  sampleRate;
    EXPECT_CALL(sampleRate, getSamplerate())
        .WillOnce(Return(44100));
}

