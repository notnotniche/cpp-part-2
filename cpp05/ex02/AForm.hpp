#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		const std::string _name;
		bool		_signed;
		const int	_grade;
		const int	_requiredgrade;

	public :
		AForm();
		~AForm();
		AForm(std::string name, int grade, int requiredgrade);
		AForm(AForm &other);

		AForm &operator=(AForm &other);


		const std::string getName () const;
		virtual	void	execute(Bureaucrat &crat) = 0;
		void	checkExec(Bureaucrat &crat) const;
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
		class NotSignedException : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return ("The Bureaucrat did not signed signed");
			}
		};
		class RequiredGradeException : public std::exception
		{
			public:
			virtual const char* what() const throw(){
				return ("The AForm execution grade is not logical");
			}
		};
		
};

std::ostream &operator<<(std::ostream &o, AForm &a);


#endif