#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ISampleRate.h"
#include "SampleRate.h"


using ::testing::Return;
using ::testing::_;

// SampleRate Class test 
TEST(SampleRateTest, getSampleRate)
{
    Ppa::SampleRate sr(44100);
    int value = sr.getSamplerate();
    ASSERT_EQ(value, 44100);
}
