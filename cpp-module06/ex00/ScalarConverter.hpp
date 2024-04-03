#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>


class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &cpysrc);
		ScalarConverter& operator=(ScalarConverter const &newvalu);

	public:
		static void convertChar(std::string str);
		static void convertInt(std::string str);
		static void convertFloat(std::string str);
		static void convertDouble(std::string str);

		static bool convert(std::string str);
};

#endif
