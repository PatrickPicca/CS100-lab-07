#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "mult.hpp"

TEST(AddTest, addition) {
 Op* op1 = new Op(5);
    Op* op2  = new Op(5);
    Add* add1 = new Add(op1, op2);
    EXPECT_EQ(add1->evaluate(), 10.0);
    EXPECT_EQ(add1->stringify(), "(5.00 + 5.00)");

 Op* op3  = new Op(5.5);
        Add* add2 = new Add(op3);
        EXPECT_EQ(add2->evaluate(), 5.5);
        EXPECT_EQ(add2->stringify(), "(5.50 + 0.00)");
Add* add3 = new Add();
        EXPECT_EQ(add3->evaluate(), 0.0);
        EXPECT_EQ(add3->stringify(), "(0.00 + 0.00)");


 Op* op4  = new Op(-3);
        Add* add4 = new Add(op4);
        EXPECT_EQ(add4->evaluate(), -3.0);
        EXPECT_EQ(add4->stringify(), "(-3.00 + 0.00)");

 Op* op5 = new Op(-3);
    Op* op6 = new Op(-3);
    Add* add5 = new Add(op5, op6);
    EXPECT_EQ(add5->evaluate(), -6.00);
    EXPECT_EQ(add5->stringify(), "(-3.00 + -3.00)");

  Op* op7 = new Op(4);
   Op* op8 = new Op(3);
   Op* op9 = new Op(6);
   Mult* mult1 = new Mult(op7, op8);
   Add* add6 = new Add(op9, mult1);
   EXPECT_EQ(add6->evaluate(), 18.0);        
   EXPECT_EQ(add6->stringify(), "(6.00 + (4.00 * 3.00))");
    
Op* op10 = new Op(5);
   Op* op11 = new Op(-2);
   Op* op12 = new Op(6);
   Mult* mult2 = new Mult(op10, op11);
   Add* add7 = new Add(op12, mult2);
   EXPECT_EQ(add7->evaluate(), -4.00);        
   EXPECT_EQ(add7->stringify(), "(6.00 + (5.00 * -2.00))");           
              
             
              
}




#endif //__ADD_TEST_HPP__







