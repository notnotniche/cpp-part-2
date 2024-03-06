#ifndef SHRUBERRYFORM_HPP
#define SHRUBERRYFORM_HPP


#include "AForm.hpp"
#include <fstream>

class ShrubberyForm : public AForm 
{
    public:
        ShrubberyForm();
        ~ShrubberyForm();
        ShrubberyForm(std::string name);
        ShrubberyForm(ShrubberyForm &other);

        ShrubberyForm &operator=(ShrubberyForm &other);

        void execute(Bureaucrat &executor);
        // const std::string getName() const;
    private :
        std::string _target;
};



#endif