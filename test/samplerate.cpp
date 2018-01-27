#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ISampleRate.h"

// Mock class
class MockSampleRate : public ISampleRate {
public:
    MockSampleRate(const int &sampleratec) : ISampleRate(sampleratec) {};
    virtual ~MockSampleRate() = default;

    MOCK_METHOD1(ISampleRate::ISampleRate, int(const int &sampleratec));
    MOCK_STATIC_METHOD0(ISampleRate::getSamplerate, int());
    MOCK_STATIC_METHOD0(ISampleRate::toString, bool());
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
    //    .WillOnce(Return(true));
}