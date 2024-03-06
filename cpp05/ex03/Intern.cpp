#include "Intern.hpp"

Intern::Intern(void){
}

Intern::Intern(Intern &toCopy){
	if (this != &toCopy)
		*this = toCopy;
}

Intern::~Intern(void){
}

Intern	&Intern::operator = (Intern &toCopy){
	(void)toCopy;
	return (*this);
}

AForm	*Intern::newShrubbery(std::string target){
	return (new ShrubberyForm(target));
}

AForm	*Intern::newPresident(std::string target){
	return (new PresidentialForm(target));
}

AForm	*Intern::newRobot(std::string target){
	return (new RobotomyForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string target){
	std::string	tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*ptr[3])(std::string) = {&Intern::newShrubbery, &Intern::newRobot, &Intern::newPresident};
	int i = 0;

	while (i < 3) {
		if (formName.compare(tab[i]) == 0)
			break ;
		i++;
	} if (i < 3) {
		std::cout<<"Intern creates "<<formName<<std::endl;
		return ((this->*ptr[i])(target));
	} else
		std::cerr<<formName<<" is not a valid form name !"<<std::endl;
	return (NULL);
}