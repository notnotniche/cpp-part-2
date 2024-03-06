#include "Scalar.hpp"

void Scalar::convert(std::string test)
{
	if (Scalar::detectChar(test) == true)
		Scalar::printforChar(test);
	else if (Scalar::detectDouble(test) == true)
		Scalar::printforDouble(test);
	else if (Scalar::detectFloat(test) == true)
		Scalar::printforFloat(test);
	else if (Scalar::detectInt(test) == true)
		Scalar::printforInt(test);
	else if (Scalar::detectSpecialString(test) == 1)
		Scalar::printforString(test);
	else
		std::cout << "NERDDDDDDDDDDDDDDDDDDDDDD" << std::endl;
}

bool Scalar::detectChar(std::string test)
{
	if  (test.length() == 1)
	{
		return (true);
	}
	else
		return (false);
}

int Scalar::numberAfterpoint(std::string test)
{
	int compteur = 0;
	int i = 0;
	while (test[i] != '.')
		i++;
	
	i++;
	while(test[i])
	{
		i++;
		if (test[i] != 'f')
			compteur++;
	}
	return (compteur);
}
bool Scalar::detectSpecialString(std::string test)
{
	if (test == ("-inf"))
		return (1);
	return (0);
}

void Scalar::printforString(std::string test)
{
	if (test == "-inf" || test == "+inf" || "nan")
	{
		std::cout << "char :   imposssible" << std::endl;
		std::cout << "int  : impossible  " << std::endl;
		std::cout << "float : "<< test << "f" << std::endl;
		std::cout << "double  "<< test << std::endl;
	}
}

void Scalar::printforFloat(std::string test)
{
	std::stringstream ss(test);
	double doubleValue;
	ss >> doubleValue;
	std::cout << "the value in double : "<<  std::fixed << std::setprecision(Scalar::numberAfterpoint(test)) << doubleValue << std::endl;
	std::cout << "the value in float  : " <<  std::fixed << std::setprecision(Scalar::numberAfterpoint(test)) << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "the value in int    : " << static_cast<int>(doubleValue) << std::endl;
	int x = static_cast<int>(doubleValue);
	if (std::isprint(x))
	{
		std::cout << "the value in char    : " << static_cast<char>(doubleValue) << std::endl;
	}
	else
	{
		std::cout << "NON PRINTABLE CHARACTER  BOOHOOO :'(" << std::endl;
	}
}

void Scalar::printforInt(std::string test)
{
	std::stringstream ss(test);
	int doubleValue;
	ss >> doubleValue;
	std::cout << "the value in double : "<<  std::fixed << std::setprecision(Scalar::numberAfterpoint("1.0")) << static_cast<double>(doubleValue) << std::endl;
	std::cout << "the value in float  : " <<  std::fixed << std::setprecision(Scalar::numberAfterpoint(test)) << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "the value in int    : " << static_cast<int>(doubleValue) << std::endl;
	int x = static_cast<int>(doubleValue);
	if (std::isprint(x))
	{
		std::cout << "the value in char    : " << static_cast<char>(doubleValue) << std::endl;
	}
	else
	{
		std::cout << "NON PRINTABLE CHARACTER  BOOHOOO :'(" << std::endl;
	}
}

void Scalar::printforDouble(std::string test)
{
	std::stringstream ss(test);
	double doubleValue;
	ss >> doubleValue;
	std::cout << "the value in double : "<<  std::fixed << std::setprecision(Scalar::numberAfterpoint(test)) << doubleValue << std::endl;
	std::cout << "the value in float  : " <<  std::fixed << std::setprecision(Scalar::numberAfterpoint(test)) << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "the value in int    : " << static_cast<int>(doubleValue) << std::endl;
	int x = static_cast<int>(doubleValue);
	if (std::isprint(x))
	{
		std::cout << "the value in char    : " << static_cast<char>(doubleValue) << std::endl;
	}
	else
	{
		std::cout << "NON PRINTABLE CHARACTER  BOOHOOO :'(" << std::endl;
	}
}
void Scalar::printforChar(std::string test)
{	
	char c = test.at(0);
	if (std::isprint(c))
		std::cout << "Value of the string as char :    " << c << std::endl;
	else
		std::cout << "Character cannot be printed " << std::endl;
	std::cout << "char to int : " << static_cast<int>(c) << std::endl;
	std::cout << "char to float : " <<  std::fixed << std::setprecision(1) << (static_cast<double>(c)) << "f" << std::endl;
	std::cout << "char to double : " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}
int Scalar::onlyNumeral(std::string test)
{
	int compteur = 0;
	if (test[0] == '.')
		return (0);
	size_t i = 0;
	if (test[0] == '-' || test[0] == '+')
		i++;
	while(i < test.length())
	{
		if (test == "-inf" || (std::isdigit(test[i]) == 0 && test[i] != '.' && test[test.length() - 1] != 'f' && test[test.length() - 1] != '.'))
			return (0);
		if (test[i] == '.')
			compteur++;
		i++;
	}
	if (compteur > 1)
		return (0);
	if (compteur == 1)
		return (1);
	return (2);
}

bool Scalar::detectFloat(std::string test)
{
	if (Scalar::onlyNumeral(test) == 1)
	{
		if ((test[test.length() - 1] == 'f') && (std::isdigit(test[test.length() - 2])))
			return(1);
	}
	return (0);
}

bool Scalar::detectDouble(std::string test)
{
	if (Scalar::onlyNumeral(test) == 1)
	{
		if (test[test.length() - 1] == 'f')
			return (0);
		else
			return (1);
			
	}
	return (0);
}

bool Scalar::detectInt(std::string test)
{
	if (Scalar::onlyNumeral(test) == 2)
		return true;
	return (false);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "tuto : ./convert [str]" << std::endl;
		return (1);
	}
	std::string	input = av[1];
	Scalar::convert(input);
	return (0);
}