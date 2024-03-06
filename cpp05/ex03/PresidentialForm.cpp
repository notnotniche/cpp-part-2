#include "PresidentialForm.hpp"


#include <time.h>

PresidentialForm::PresidentialForm() : AForm("Presidential Form",25, 5), _target("default")
{
    
}

PresidentialForm::PresidentialForm(const std::string name) : AForm("Presidential Form",25, 5), _target(name)
{
    
}

PresidentialForm::PresidentialForm(PresidentialForm &other) :
	AForm(other.getName(), 25  , 5), _target(other._target){
	if (this != &other)
		*this = other;
}

PresidentialForm::~PresidentialForm(){
}

PresidentialForm	&PresidentialForm::operator = (PresidentialForm &toCopy){
	(void)toCopy;
	return (*this);
}

void PresidentialForm::execute(Bureaucrat &executor)
{
    try
    {
        checkExec(executor);
    }
    catch (const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
        return ;
    }
    std::cout << "PARDON BY THE GOD ZAPHOD BEEBLEBROX" << std::endl<< std::endl;
    
    
}