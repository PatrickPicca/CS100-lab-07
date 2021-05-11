#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include "iostream"
#include "sstream"
#include <iomanip>
#include <string>

using namespace std;

class Base {
    public:
        /* Constructors */
        Base() { }

        virtual ~Base() {}
    
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() 
	{
		ostringstream ss;
		ss << setprecision(3)<< showpoint << 0.00;
		return ss.str(); 
	}
};

#endif //__BASE_HPP__
