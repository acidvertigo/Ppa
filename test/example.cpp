#include "gtest/gtest.h"
#include "gmock/gmock.h"


// Simple test, does not use gmock
TEST(Dummy, foobar)
{
    EXPECT_EQ(1, 1);
}


// Real class we want to mock
class TeaBreak
{
public:
    virtual ~TeaBreak() {}

    // Return minutes taken to make the drinks
    int morningTea()
    {
        return makeCoffee(true,  1) +
               makeCoffee(false, 0.5) +
               makeHerbalTea();
    }

private:
    virtual int makeCoffee(bool milk, double sugars) = 0;
    virtual int makeHerbalTea() = 0;
};

// Mock class
class MockTeaBreak : public TeaBreak
{
public:
    MOCK_METHOD2(makeCoffee,    int(bool milk, double sugars));
    MOCK_METHOD0(makeHerbalTea, int());
};

class Turtle {
  virtual ~Turtle() {}
  virtual void PenUp() = 0;
  virtual void PenDown() = 0;
  virtual void Forward(int distance) = 0;
  virtual void Turn(int degrees) = 0;
  virtual void GoTo(int x, int y) = 0;
  virtual int GetX() const = 0;
  virtual int GetY() const = 0;
};

class MockTurtle : public Turtle {
 public:
  MOCK_METHOD0(PenUp, void());
  MOCK_METHOD0(PenDown, void());
  MOCK_METHOD1(Forward, void(int distance));
  MOCK_METHOD1(Turn, void(int degrees));
  MOCK_METHOD2(GoTo, void(int x, int y));
  MOCK_CONST_METHOD0(GetX, int());
  MOCK_CONST_METHOD0(GetY, int());
};


using ::testing::Return;
using ::testing::_;
using ::testing::AtLeast;                     // #1

TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;                          // #2
  EXPECT_CALL(turtle, PenDown())              // #3
      .Times(AtLeast(1));

  Painter painter(&turtle);                   // #4

  EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
} 
// Mocked test
TEST(TeaBreakTest, MorningTea)
{
    MockTeaBreak  teaBreak;
    EXPECT_CALL(teaBreak, makeCoffee(_,_))
        .WillOnce(Return(2))
        .WillOnce(Return(1));
    EXPECT_CALL(teaBreak, makeHerbalTea())
        .WillOnce(Return(3));

    EXPECT_LE(teaBreak.morningTea(), 6);
}