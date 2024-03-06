#include "Form.hpp"

Form::Form() :  _name("default"), _signed(false), _grade(150), _requiredgrade(130)
{
	std::cout << "Default constructor Called" << std::endl;
	if (_grade > 150 || _requiredgrade > 150)
		throw GradeTooLowException();
	else if (_grade < 1 || _requiredgrade < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
	std::cout << "Destructor Called" << std::endl;
}

Form::Form(std::string name, int grade, int requiredgrade) : _name(name), _signed(false), _grade(grade), _requiredgrade(requiredgrade)
{
	std::cout << "Custom Constructor Called" << std::endl;
	if (_requiredgrade > _grade)
		throw RequiredGradeException();
	if (_grade > 150 || _requiredgrade > 150)
		throw GradeTooLowException();
	else if (_grade < 1 || _requiredgrade < 1)
		throw GradeTooHighException();
}
Form::Form(Form &other) : _name(other._name) , _grade(other._grade) , _requiredgrade(other._requiredgrade)
{
	std::cout << "Copy assignement called" << std::endl;
	*this = other;
	return ;
}

const std::string Form::getName()
{
    return _name;
}

int Form::getGrade()
{
	return _grade;
}

int Form::getRGrade()
{
	return _requiredgrade;
}

bool Form::getSigned()
{
	return _signed;
}

Form &Form::operator=(Form &other)
{
	this->_signed = other._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Form &a)
{
	o << a.getName() << " , Minimum grade : " << a.getGrade() << " , Execution Grade : " << a.getRGrade() << std::endl;
	return o;
}

void Form::beSigned(Bureaucrat a)
{
	if (this->_signed == true)
	{
		std::cout << "The Form was already Signed" << std::endl;
	}
	else if (a.getGrade() < this->getGrade())
	{
		this->_signed = true;
		std::cout << a.getName() << " signed the form " << this->getName() << std::endl;
	}
	else if (a.getGrade() > this->_grade)
	{
		std::cout << a.getName() << " couldn’t sign form " << this->getName() << " because ";
		throw GradeTooLowException();
	}
	else if (a.getGrade() < this->_grade)
	{
		std::cout << a.getName() << " couldn’t sign form " << this->getName() << " because ";
		throw GradeTooHighException();
	}
}