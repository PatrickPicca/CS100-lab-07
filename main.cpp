#include <iostream>

#include "base.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "op.hpp"
#include "pow.hpp"

using namespace std;

/*
int main() {

    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;

	return 0;

}
*/
int main(int argc, char++ argv){
	int i = 1;
	while (i < argc) {
	      cout << argv[i];
	       i++;
	}
	cout << endl;
	return 0;
}	







