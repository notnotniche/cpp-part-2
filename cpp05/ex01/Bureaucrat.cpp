#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Default") , _grade(150)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Custom constructor Called" << std::endl;
	if (_grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (_grade > 150)
	{
		throw GradeTooLowException();
	}
}

//todo check if _grade initlaize

Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	std::cout << "Copy constructor Called" << std::endl;
	*this = other;
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	this->_grade = other._grade;
	this->_name = other._name;
	std::cout << "Operator = Called" << std::endl;
	return (*this);
}

int		Bureaucrat::getGrade()
{
	return (_grade);
}

std::string Bureaucrat::getName()
{
	return (_name);
}

void Bureaucrat::incrementRank()
{
	if (_grade  == 1)
	{
		throw GradeTooHighException();
	}
	else
		_grade--;
}

void Bureaucrat::decrementRank()
{
	if (_grade == 150)
	{
		throw GradeTooLowException();
	}
	else
		_grade++;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& a)
{
    o << a.getName() << ", Bureaucrat grade " << a.getGrade();
    return o;
}