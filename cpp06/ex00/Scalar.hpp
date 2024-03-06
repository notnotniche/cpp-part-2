#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>
# include <sstream>
#include <iomanip>
#include <cstring>  

class Scalar
{
	public:
		static void convert(std::string test);


		static bool detectInt(std::string test);
		static bool detectString(std::string test);
		static bool detectChar(std::string test);
		static bool detectFloat(std::string test);
		static bool detectDouble(std::string test);
		static bool detectSpecialString(std::string test);
		static int onlyNumeral(std::string test);
		

		static void printforString(std::string test);
		static void printforChar(std::string test);
		static void printforDouble(std::string test);
		static void printforFloat(std::string test);
		static void printforInt(std::string test);

		static int numberAfterpoint(std::string test);

		

	private:
		Scalar();



};


#endif