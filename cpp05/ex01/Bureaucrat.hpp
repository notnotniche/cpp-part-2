#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	public : 
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int level);
		Bureaucrat(Bureaucrat &other);

		Bureaucrat &operator=(Bureaucrat &other);


		std::string getName();
		int			getGrade();
		void incrementRank();
		void decrementRank();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("The Grade is too High");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("The Grade is too Low");
				}
		};
	private:
		std::string			_name;
		int 				_grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& a);

#endif