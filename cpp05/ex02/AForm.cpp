#include "AForm.hpp"

AForm::AForm() :  _name("default"), _signed(false), _grade(150), _requiredgrade(130)
{
	std::cout << "Default constructor Called" << std::endl;
	if (_grade > 150 || _requiredgrade > 150)
		throw GradeTooLowException();
	else if (_grade < 1 || _requiredgrade < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
	std::cout << "Destructor Called" << std::endl;
}

AForm::AForm(std::string name, int grade, int requiredgrade) : _name(name), _signed(false), _grade(grade), _requiredgrade(requiredgrade)
{
	std::cout << "Custom Constructor Called" << std::endl;
	if (_requiredgrade > _grade)
		throw RequiredGradeException();
	if (_grade > 150 || _requiredgrade > 150)
		throw GradeTooLowException();
	else if (_grade < 1 || _requiredgrade < 1)
		throw GradeTooHighException();
}
AForm::AForm(AForm &other) : _name(other._name) , _grade(other._grade) , _requiredgrade(other._requiredgrade)
{
	std::cout << "Copy assignement called" << std::endl;
	*this = other;
	return ;
}

void	AForm::checkExec(Bureaucrat &crat) const
{
	if (_signed == false)
		throw (AForm::NotSignedException());
	if (_requiredgrade < crat.getGrade())
		throw (AForm::GradeTooLowException());
}

const std::string AForm::getName() const
{
    return _name;
}

int AForm::getGrade()
{
	return _grade;
}

int AForm::getRGrade()
{
	return _requiredgrade;
}

bool AForm::getSigned()
{
	return _signed;
}

AForm &AForm::operator=(AForm &other)
{
	this->_signed = other._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, AForm &a)
{
	o << a.getName() << " , Minimum grade : " << a.getGrade() << " , Execution Grade : " << a.getRGrade() << std::endl;
	return o;
}

void AForm::beSigned(Bureaucrat a)
{
    try {
        if (this->_signed == true)
        {
            std::cout << "The AForm was already Signed" << std::endl;
        }
        else if (a.getGrade() <= this->getGrade())
        {
            this->_signed = true;
            std::cout << a.getName() << " signed the AForm " << this->getName() << std::endl;
        }
        else if (a.getGrade() > this->_grade)
        {
            std::cout << a.getName() << " couldn’t sign AForm " << this->getName() << " because ";
            throw GradeTooLowException();
        }
        else if (a.getGrade() < this->_grade)
        {
            std::cout << a.getName() << " couldn’t sign AForm " << this->getName() << " because ";
            throw GradeTooHighException();
        }
    } catch (const GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    } catch (const GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
}