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
	EXPECT_DOUBLE_EQ(Op->evaluate(), 3);
}

TEST(FactoryTest, Subtracting){
        Factory test;
        char *args[] = {"2", "-", "1"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 1);
}

TEST(FactoryTest, Multiplying){
        Factory test;
        char *args[] = {"4", "*", "3"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 12);
}

TEST(FactoryTest, Dividing){
        Factory test;
        char *args[] = {"8", "/", "2"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 4);
}

TEST(FactoryTest, Pow){
        Factory test;
        char *args[] = {"2", "**", "2"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 4);
}

TEST(FactoryTest, AddSub) {
	Factory test;
	char *args[] = { "7", "+", "2", "-", "3"};
	Base *Op = test.parse(args, 5);
	EXPECT_DOUBLE_EQ(Op->evaluate(), 6);
}

TEST(FactoryTest, SubAdd) {
        Factory test;
        char *args[] = { "10", "-", "4", "+", "2"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 8);
}

TEST(FactoryTest, SubMult) {
        Factory test;
        char *args[] = { "2", "-", "1", "*", "7"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 7);
}


TEST(FactoryTest, MultSub) {
        Factory test;
        char *args[] = { "12", "*", "2", "-", "10"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 14);
}

TEST(FactoryTest, AddMult) {
        Factory test;
        char *args[] = { "4", "+", "3", "*", "5"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 30);
}

TEST(FactoryTest, MultAdd) {
        Factory test;
        char *args[] = { "5", "*", "4", "+", "6"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 26);
}

TEST(FactoryTest, AddDiv) {
        Factory test;
        char *args[] = { "20", "+", "8", "/", "2"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 14);
}

TEST(FactoryTest, SubDiv) {
        Factory test;
        char *args[] = { "11", "-", "1", "/", "5"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 2);
}

TEST(FactoryTest, MultDiv) {
        Factory test;
        char *args[] = { "3", "*", "8", "/", "6"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 4);
}

TEST(FactoryTest, PowDiv) {
        Factory test;
        char *args[] = { "3", "**", "2", "/", "3"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 3);
}

TEST(FactoryTest, MultPow) {
        Factory test;
        char *args[] = { "5", "*", "1", "**", "2"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 25);
}

TEST(FactoryTest, AddingNeg){
        Factory test;
        char *args[] = {"-2", "+", "10"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 8);
}

TEST(FactoryTest, SubtractingNeg){
        Factory test;
        char *args[] = {"-4", "-", "-7"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 3);
}

TEST(FactoryTest, MultiplyingNeg){
        Factory test;
        char *args[] = {"-4", "*", "4"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), -16);
}

TEST(FactoryTest, DividingNeg){
        Factory test;
        char *args[] = {"50", "/", "-5"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), -10);
}



