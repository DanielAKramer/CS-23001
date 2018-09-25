/*
  Daniel Kramer
  CS23001
  add.cpp
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.h"

int main()
{
	std::ifstream in("data1-1.txt");

	if (!in)
	{
		std::cerr << "Could not open data1-1.txt, exiting" << std::endl;
		exit(1);
	}

	bigint left, right;

	while (!in.eof())
	{
		in >> left;

		if (!in.eof())
			in >> right;

		//output
		std::cout << "Left: " << left << std::endl;
		std::cout << "Right: " << right << std::endl;

		//add
		bigint result = left + right;

		//output result
		std::cout << "Result: " << result << std::endl;
	}

	in.close();
	return 0;
}
