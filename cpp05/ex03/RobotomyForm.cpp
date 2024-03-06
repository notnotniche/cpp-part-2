#include "RobotomyForm.hpp"

#include <stdlib.h> 
#include <time.h>

RobotomyForm::RobotomyForm() : AForm("Robotomy Form",72, 45), _target("default")
{
    
}

RobotomyForm::RobotomyForm(const std::string name) : AForm("Robotomy Form",72, 45), _target(name)
{
    
}

RobotomyForm::RobotomyForm(RobotomyForm &other) :
	AForm(other.getName(), 72, 45), _target(other._target){
	if (this != &other)
		*this = other;
}

RobotomyForm::~RobotomyForm(){
}

RobotomyForm	&RobotomyForm::operator = (RobotomyForm &toCopy){
	(void)toCopy;
	return (*this);
}

// const std::string getName() const
// {
//   return "a";
// }

void RobotomyForm::execute(Bureaucrat &executor)
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
    std::cout << "BZZZZZZZZZZZZZZZ" << std::endl;
    srand(time(NULL));
    if (rand() % 2 == 0)
      std::cout << "SUCCESSFULL ROBOTOMY KNEW KNEW KNEW KNEW THE EMPIRE GROW BIGGER" << std::endl<< std::endl;
    else
      std::cout << "DID NOT SUCCEED , WASNT WORTHY OF BECOMING A ROBOT "<< std::endl << std::endl;

    

    
    
}