#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{

		try
		{
			Bureaucrat a("dofus", 1);
			Form b("Amakna", 120, 110);
			b.beSigned(a);
			b.beSigned(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
}