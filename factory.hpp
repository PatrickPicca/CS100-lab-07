#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__


#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

#include <iostream>
#include <cstring>


class Factory
{
	public:
		Factory(){};
		~Factory(){};
		Base* parse(char** input, int length)
		{
			int op_length = length/2;
			int count = 0;
			int num1 = 0;
			int num2 = 0;
			int operand[op_length+1];
			std::string operators[op_length];
				
			for(int i=1;i<length;i++){ 
			if (isdigit(input[i][0])){
				for(int k=0;k<strlen(input[i]);k++){
					count+= ((int)input[i][k]-48)*pow(10,(strlen(input[i]) - 1 - k));
					}
					operand[num1]=count;
					num1++;
					count = 0;
				}
				else if (input[i] == "+" ||input[i]=="-" || input[i]=="/" || input[i]== "*" ||input[i]=="**"){
					operators[num2]=input[i];
					num2++;
				}
				else{
					std::cout<< "invalid input!";
					return nullptr;
				}
			}
			std:: string sign;
			Base* val1;
			Base* val2;
			Base* val3;
			Base* result;
			val1 = new Op(operand[0]);
			val2 = new Op(operand[1]);
			sign = operators[0];
		
			if (sign=="+"){
				val3 = new Add(val1, val2);		
			}
			else if (sign=="-"){
				val3= new Sub(val1, val2);
			}
			else if (sign=="/"){
				val3= new Div(val1, val2);
			}
			else if (sign=="*"){
				val3= new Mult(val1, val2);
			}
			else if (sign=="**"){
				val3= new Pow(val1, val2);
			}
			delete val1;
			int counting = 2;
			for(int i = 1; i<op_length; i++){		
				delete val2;
				val2 = new Op(operand[counting]);
				sign=operators[i];
				if (sign=="+"){
					result = new Add(val3, val2);
				}
				else if (sign=="-"){
					result = new Sub(val3, val2);
				}
				else if (sign=="/"){
					result = new Div(val3, val2);
				}
				else if (sign=="*"){
					result = new Mult(val3, val2);	
				}
				else if (sign=="**"){
					result = new Pow(val3, val2);
				}
				counting++;
			}
			delete val2;
			delete val3;
			return result;	
		}
		
};


#endif
