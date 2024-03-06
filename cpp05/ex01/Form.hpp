#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string _name;
		bool		_signed;
		const int	_grade;
		const int	_requiredgrade;

	public :
		Form();
		~Form();
		Form(std::string name, int grade, int requiredgrade);
		Form(Form &other);

		Form &operator=(Form &other);


		const std::string getName () ;
		bool	getSigned();
		int getGrade();
		int getRGrade();

		void beSigned(Bureaucrat a);

		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return ("The grade set is too high");
			}
		};
		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return ("The grade set is too low");
			}
		};
		class AlreadySignedException : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return ("The Bureaucrat already signed");
			}
		};
		class RequiredGradeException : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return ("The Form execution grade is not logical");
			}
		};
		
};

std::ostream &operator<<(std::ostream &o, Form &a);


#endif