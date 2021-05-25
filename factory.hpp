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
#include <cmath>
#include <string>

using namespace std;

class Factory
{
	public:
		Factory(){};
		~Factory(){};
		Base* parse(char** input, int length)
		{	
			int op_length = length/2;
			double count = 0;
			int num1 = 0;
			int num2 = 0;
			double operand[op_length+1];
			std::string operators[op_length];
				
			for(int i=0;i<length;i++){ 
				//if (input[i] == 0 || atoi(input[i]) < 50000){
				//	count+= atoi(input[i]);
				//	operand[num1]=count;
				//	num1++;
				//	count = 0;
				//}
				if (*input[i] == '+' || *input[i]=='-' || *input[i]=='/' || *input[i]== '*' || input[i] == "**"){
						
					if (*input[i] == '-' && input[i][1] != NULL && isdigit(input[i][1]))
					{	
						std::cout << "Negative sign found in first element of character!!!" << endl;
						bool going = true;
						for (int x = 1; x < strlen(input[i]); x++){
							if (!isdigit(input[i][x])){
								going = false;
								//std::cout << "Here";
							}
						}
						if (going == true){
							//std::cout << "here" << endl;
							count += atof(input[i]);
							operand[num1]=count;
							num1++;
							count = 0;
						}
						else{
							std::cout << "Invalid input!";
							return nullptr;
						}
					}
					else {
						std::cout <<  "Else statement" << endl;
						std::cout << input[i] << endl;
						//std::cout << input[i];
						if (strlen(input[i]) == 1) {
							operators[num2] = input[i];
							num2++;
						}
						else if (input[i] == "**")
						{
							operators[num2] = input[i];
							num2++;
						}
						else{
							std::cout <<"Invalid input!";
							return nullptr;
						}
					}
				}
				else if (atof(input[i]) < 50000){
					//std::cout << atof(input[i]);	
					count += atof(input[i]);
					operand[num1]=count;
					num1++;
					count = 0;
			//return nullptr;	
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

			if (op_length == 1)
				return val3;
				
			
			int counting = 2;
			
			for(int i = 1; i<op_length; i++){	//If there are more than 1 operators in the passed in arguments.	
			
				Base* val4 = new Op(operand[counting]);
				sign=operators[i];
				if (sign=="+"){
			
					result = new Add(val3, val4);
				}
				else if (sign=="-"){
		
					result = new Sub(val3, val4);
				}
				else if (sign=="/"){
					result = new Div(val3, val4);
				}
				else if (sign=="*"){
					result = new Mult(val3, val4);	
				}
				else if (sign=="**"){
					result = new Pow(val3, val4);
				}
				counting++;
			}
			if (result == nullptr){

				return val3;
			}
			else
			{
				return result;
			}	
		}
		
};


#endif
