#include "ShrubberyForm.hpp"


void writeAsciiTree(std::ofstream& outFile, int levels, char symbol) {
    for (int i = 0; i < levels; ++i) {
        for (int j = 0; j < levels - i - 1; ++j) {
            outFile << " ";
        }

        for (int j = 0; j < 2 * i + 1; ++j) {
            outFile << symbol;
        }

        outFile << std::endl;
    }
}

// const std::string ShrubberyForm::getName() const
// {
//     return AForm::getName();
// }

ShrubberyForm::ShrubberyForm() :
	AForm("ShrubberyForm", 145, 137), _target("default"){
}

ShrubberyForm::ShrubberyForm(const std::string target) :
	AForm("ShrubberyForm", 145, 137), _target(target){
}

ShrubberyForm::ShrubberyForm(ShrubberyForm &toCopy) :
	AForm(toCopy.getName(), 145, 137), _target(toCopy._target){
	if (this != &toCopy)
		*this = toCopy;
}

ShrubberyForm::~ShrubberyForm(){
}

ShrubberyForm	&ShrubberyForm::operator = (ShrubberyForm &toCopy){
	(void)toCopy;
	return (*this);
}

void	ShrubberyForm::execute(Bureaucrat &executor){
	try
	{
		checkExec(executor);
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
		return ;
	}
	std::cout<<"Creating "<<_target<<"_shrubbery ..."<<std::endl;

	std::string	outName;
	outName = _target + "_shrubbery";

	std::ofstream	outfile((char *)outName.c_str());
	if (outfile.is_open() == false)
	{
		std::cerr<<"Open/Creation outfile failed"<<std::endl;
		return ;
	}
    writeAsciiTree(outfile, executor.getGrade(), '*');
	std::cout<<_target<<"_shrubbery is done."<<std::endl<<std::endl;

	outfile.close();
}