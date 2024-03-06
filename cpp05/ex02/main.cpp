#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyForm.hpp"


int main()
{

		try
		{
			ShrubberyForm abc("shrurrbby");
			Bureaucrat a("dofus", 137);
			abc.beSigned(a);
			abc.execute(a);
			std::cout << abc << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
}