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
	char *args[] = {(char *)"2", (char *)"+", (char *)"1"};
	Base *Op = test.parse(args, 3);
	EXPECT_DOUBLE_EQ(Op->evaluate(), 3);
}

TEST(FactoryTest, Subtracting){
        Factory test;
        char *args[] = {(char *)"2", (char *)"-", (char *)"1"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 1);
}

TEST(FactoryTest, Multiplying){
        Factory test;
        char *args[] = {(char *)"4", (char *)"*", (char *)"3"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 12);
}

TEST(FactoryTest, Dividing){
        Factory test;
        char *args[] = {(char *)"8", (char *)"/", (char *)"2"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 4);
}

TEST(FactoryTest, Pow){
        Factory test;
        char *args[] = {(char *)"2", (char *)"**", (char *)"2"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 4);
}

TEST(FactoryTest, AddSub) {
	Factory test;
	char *args[] = { (char *)"7", (char *)"+", (char *)"2", (char *)"-", (char *)"3"};
	Base *Op = test.parse(args, 5);
	EXPECT_DOUBLE_EQ(Op->evaluate(), 6);
}

TEST(FactoryTest, SubAdd) {
        Factory test;
        char *args[] = { (char *)"10", (char *)"-", (char *)"4", (char *)"+", (char *)"2"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 8);
}

TEST(FactoryTest, SubMult) {
        Factory test;
        char *args[] = { (char *)"2", (char *)"-", (char *)"1", (char *)"*", (char *)"7"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 7);
}


TEST(FactoryTest, MultSub) {
        Factory test;
        char *args[] = { (char *)"12", (char *)"*", (char *)"2", (char *)"-", (char *)"10"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 14);
}

TEST(FactoryTest, AddMult) {
        Factory test;
        char *args[] = { (char *)"4", (char *)"+", (char *)"3", (char *)"*", (char *)"5"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 35);
}

TEST(FactoryTest, MultAdd) {
        Factory test;
        char *args[] = { (char *)"5", (char *)"*", (char *)"4", (char *)"+", (char *)"6"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 26);
}

TEST(FactoryTest, AddDiv) {
        Factory test;
        char *args[] = { (char *)"20", (char *)"+", (char *)"8", (char *)"/", (char *)"2"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 14);
}

TEST(FactoryTest, SubDiv) {
        Factory test;
        char *args[] = { (char *)"11", (char *)"-", (char *)"1", (char *)"/", (char *)"5"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 2);
}

TEST(FactoryTest, MultDiv) {
        Factory test;
        char *args[] = { (char *)"3", (char *)"*", (char *)"8", (char *)"/", (char *)"6"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 4);
}

TEST(FactoryTest, PowDiv) {
        Factory test;
        char *args[] = { (char *)"3", (char *)"**", (char *)"2", (char *)"/", (char *)"3"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 3);
}

TEST(FactoryTest, MultPow) {
        Factory test;
        char *args[] = { (char *)"5", (char *)"*", (char *)"1", (char *)"**", (char *)"2"};
        Base *Op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 25);
}

TEST(FactoryTest, AddingNeg){
        Factory test;
        char *args[] = {(char *)"-2", (char *)"+", (char *)"10"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 8);
}

TEST(FactoryTest, SubtractingNeg){
        Factory test;
        char *args[] = {(char *)"-4", (char *)"-", (char *)"-7"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), 3);
}

TEST(FactoryTest, MultiplyingNeg){
        Factory test;
        char *args[] = {(char *)"-4", (char *)"*", (char *)"4"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), -16);
}

TEST(FactoryTest, DividingNeg){
        Factory test;
        char *args[] = {(char *)"50", (char *)"/", (char *)"-5"};
        Base *Op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(Op->evaluate(), -10);
}

#endif
