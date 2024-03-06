#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialForm.hpp"
# include "ShrubberyForm.hpp"
# include "RobotomyForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(Intern &toCopy);
		~Intern();

		Intern	&operator = (Intern &toCopy);

		AForm	*newShrubbery(std::string target);
		AForm	*newPresident(std::string target);
		AForm	*newRobot(std::string target);
		AForm	*makeForm(std::string formName, std::string target);

};

#endif