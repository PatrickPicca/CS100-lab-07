#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "factory.hpp"

TEST(FactoryTest, Adding){
	Factory test;
	char *args[] = {"2", "+", "1"};
	Base *Op = test.parse(args, 3);
	EXPECT_DOUBLE_EQ(op->evaluate(), 3);
}

TEST(FactoryTest, Subtracting){
        Factory test;
        char *args[] = {"2", "-", "1"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(op->evaluate(), 1);
}

TEST(FactoryTest, Multiplying){
        Factory test;
        char *args[] = {"4", "*", "3"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(op->evaluate(), 12);
}

TEST(FactoryTest, Dividing){
        Factory test;
        char *args[] = {"8", "/", "2"};
        Base *op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(op->evaluate(), 4);
}

TEST(FactoryTest, Pow){
        Factory test;
        char *args[] = {"2", "**", "2"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(op->evaluate(), 4);
}



