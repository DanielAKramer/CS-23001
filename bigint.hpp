/*
	Daniel Kramer
	CS23001
	bigint.hpp
*/

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

const int MAX_SIZE = 256;

class bigint
{
public:
	//Constructors
	bigint();
	bigint(int);
	bigint(const char[]);

	//Overload operators
	bool operator==(const bigint&) const;
	bigint operator+(bigint) const;
	int& operator[](int);
	int operator[](int) const;

	//friend functions
	friend std::ostream& operator<<(std::ostream&, const bigint&);
	friend std::istream& operator>>(std::istream&, bigint&);

private:
	int number[MAX_SIZE];
};


#endif
