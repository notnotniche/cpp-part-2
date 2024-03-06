#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cmath>

Base * generate(void){
	srand(time(0));
	int randomNbr = rand() % 3;

	if (randomNbr == 0) {
		std::cout<<"make A class"<< std::endl;
		return new A;
	}
	else if (randomNbr == 1) {
		std::cout<<"make B class"<< std::endl;
		return new B;
	}
	else {
		std::cout<<"make C class"<< std::endl;
		return new C;
	}
}

void identify(Base* p){
	if (dynamic_cast<A *>(p))
		std::cout<<"type is A"<<std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout<<"type is B"<<std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout<<"type is C"<<std::endl;
	else
		std::cout<<"Error"<<std::endl;
}

void identify(Base& p){
	try
	{
		p = dynamic_cast<A &>(p);
		std::cout<<"type is A"<<std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		p = dynamic_cast<B &>(p);
		std::cout<<"type is B"<<std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		p = dynamic_cast<C &>(p);
		std::cout<<"type is C"<<std::endl;
	}
	catch(const std::exception& e) {}
}

int	main()
{
	Base	*newBase = generate();
	identify(newBase);
	identify(*newBase);
	delete newBase;
}