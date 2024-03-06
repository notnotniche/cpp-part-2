#ifndef ROBOTOMYFORM_HPP
#define ROBOTOMYFORM_HPP

#include "AForm.hpp"

class RobotomyForm : public AForm
{
    public :
        RobotomyForm();
        ~RobotomyForm();
        RobotomyForm(std::string name);
        RobotomyForm(RobotomyForm &other);

        RobotomyForm &operator=(RobotomyForm &other);

        void execute(Bureaucrat &executor);
        // const std::string getName() const;
    private :
        std::string _target;
};


#endif