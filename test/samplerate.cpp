#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "SampleRate.h"

//using namespace ::Ppa;
namespace {

// SampleRate Class test 
TEST(SampleRateTest, getSampleRate)
{
    SampleRate sr(44100);
    int value = sr.getSamplerate();
    ASSERT_EQ(value, 44100);
}
}