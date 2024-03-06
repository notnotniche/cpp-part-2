#include "Bureaucrat.hpp"


int main()
{

		try
		{
			Bureaucrat b("dofus", 139);
			Bureaucrat a(b);
			a.decrementRank();
			std::cout << a << std::endl;
			a.incrementRank();
			std::cout << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Bureaucrat a("dofus", 0);

		}
				catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
}