#ifndef PRESIDENTIALFORM_HPP
#define PRESIDENTIALFORM_HPP

#include "AForm.hpp"

class PresidentialForm : public AForm
{
    public :
        PresidentialForm();
        ~PresidentialForm();
        PresidentialForm(std::string name);
        PresidentialForm(PresidentialForm &other);

        PresidentialForm &operator=(PresidentialForm &other);

        void execute(Bureaucrat &executor);
        // const std::string getName() const;
    private :
        std::string _target;
};


#endif