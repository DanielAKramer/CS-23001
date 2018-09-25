/*
	Daniel Kramer
	CS23001
	Utilities.hpp
*/

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "stack.hpp"
#include "string.hpp"
#include <vector>


//free function that converts infix to postfix
void infToPostf(std::ifstream&, std::ofstream&);
void toAssembly(std::ifstream&, std::ofstream&);
String assemblyOperator(const String&);
String iToS(int);
String getToken(std::ifstream&);


#endif
