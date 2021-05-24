#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"


  TEST(PowTest, PowEvaluateNonZero) {
       Op* op1 = new Op(4);
       Op* op2 = new Op(2);
       Pow* pow = new Pow(op1, op2);
       EXPECT_EQ(pow->evaluate(), 16.0);
       EXPECT_EQ(pow->stringify(), "(4.00 ** 2.00)");
  }

 TEST(PowTest, PowEvaluateOneOp) {
       Op* op1 = new Op(3);
       Pow* pow = new Pow(op1);
       EXPECT_EQ(pow->evaluate(), 3.0);
       EXPECT_EQ(pow->stringify(), "(3.00 ** 1.00)");
  }

TEST(PowTest, PowEvaluateNothingPassed) {
       Pow* pow = new Pow(); 
       EXPECT_EQ(pow->evaluate(), 1.0);
       EXPECT_EQ(pow->stringify(), "(1.00 ** 1.00)");
  }


TEST(PowTest, PowEvaluateNegOps) {
       Op* op1 = new Op(-10);
       Op* op2 = new Op(2);
       Pow* pow = new Pow(op1, op2);
       EXPECT_EQ(pow->evaluate(), 100.0);
       EXPECT_EQ(pow->stringify(), "(-10.0 ** 2.00)");
  }

TEST(PowTest, PowEvaluateNegOps2) {
       Op* op1 = new Op(-10);
       Op* op2 = new Op(-1);
       Pow* pow = new Pow(op1, op2);
       EXPECT_EQ(pow->evaluate(), -0.1);
       EXPECT_EQ(pow->stringify(), "(-10.0 ** -1.00)");
  }




#endif //__POW_TEST_HPP__

