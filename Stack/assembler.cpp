/*
	Daniel Kramer
	CS23001
	assembler.cpp
*/


#include <fstream>
#include "utilities.h"
#include <fstream>
#include <iostream>

int main(int argc, char const* argv[])
{
	// If no input file, display help and leave
	if (argc != 3) 
	{
		std::cout << "input filename is required" << std::endl;
	}

	std::ifstream postfixFile(argv[1]);
	if (!postfixFile)
	{
		std::cout << "Couldn't open input file  " << argv[1] << "\n";
	}

	std::ofstream assemblyFile(argv[2]);

	// If file can't be opened
	if (!assemblyFile) 
	{
		std::cout << "Assembly file can't be opened" << std::endl;
	}

	// Convert input to assembly
	toAssembly(postfixFile, assemblyFile);
	postfixFile.close();
	assemblyFile.close();

	return 0;
}
