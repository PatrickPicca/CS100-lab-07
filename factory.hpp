#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__


#include <add.hpp>
#include <base.hpp>
#include <div.hpp>
#include <mult.hpp>
#include <op.hpp>
#include <pow.hpp>
#include <rand.hpp>
#include <sub.hpp>

#include <iostream>

class Factory
{
	public:
		Base* parse(char** input, int length)
		{
			
				
			Base* left_op = nullptr;
			for (int i = 2, i < ; i++){
				if (input[i] == nullptr){
					int num1 = stod(input[i++]);
					left_op = new Op(num1);
				}
				if (input[i] == "+") {
					int num2 = stod(input[++i]);
					left_op = new Add(left_op, new Op(num));
				}
				else if(input[i] == "/") {
					int num2 = stod(input[++i]);
					left_op = new Div(left_op, new Op(num2));
				}
				else if(input[i]=="-") {
					int num2 = stod(input[++i]);
					left_op = new Sub(left_op, new Op(num2));
				}
				else if(input[i]=="*") {
					int testing = i+1;
					if (input[testing] =="*")
					{
						int num2 = stod(input[++testing]);
						left_op = new Pow(left_op, new Op(num2));	
					}
					else {
						int num2 = stod(input[++i]);
						left_of = new Mult(left_op, new Op(num2));	
					}
				}
				else{
					cout << "ERROR!" << endl;
					return nullptr;
				}
				i++;
			}
			return left_op;
		}
		
};


#endif
