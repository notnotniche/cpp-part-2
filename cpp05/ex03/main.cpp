#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyForm.hpp"
#include "Intern.hpp"
#include "RobotomyForm.hpp"
#include "PresidentialForm.hpp"

int	main()
{
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat Dofus("Dofus", 20);

	{
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
		{
			try
			{
				Dofus.SignForm(*rrf);
				rrf->execute(Dofus);
			}
			catch (std::exception const & e)
			{
				std::cout<<e.what()<<std::endl<<std::endl;
			}
			delete rrf;
		}

	}
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			try
			{
				Dofus.SignForm(*rrf);
				rrf->execute(Dofus);
			}
			catch (std::exception const & e)
			{
				std::cout<<e.what()<<std::endl<<std::endl;
			}
			delete rrf;
		}
	}
	{
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
		{
			try
			{
				Dofus.SignForm(*rrf);
				rrf->execute(Dofus);
			}
			catch (std::exception const & e)
			{
				std::cout<<e.what()<<std::endl<<std::endl;
			}
			delete rrf;
		}
	}

	std::cout<<std::endl;
	Bureaucrat Test("t", 2);

	{
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
		{
			try
			{
				Test.SignForm(*rrf);
				rrf->execute(Test);
			}
			catch (std::exception const & e)
			{
				std::cout<<e.what()<<std::endl<<std::endl;
			}
			delete rrf;
		}

	}
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			try
			{
				Test.SignForm(*rrf);
				rrf->execute(Test);
			}
			catch (std::exception const & e)
			{
				std::cout<<e.what()<<std::endl<<std::endl;
			}
			delete rrf;
		}
	}
	{
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
		{
			try
			{
				Test.SignForm(*rrf);
				rrf->execute(Test);
			}
			catch (std::exception const & e)
			{
				std::cout<<e.what()<<std::endl<<std::endl;
			}
			delete rrf;
		}
	}
	return (0);
}