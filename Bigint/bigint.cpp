/*
	Daniel Kramer
	CS23001
	Bigint.cpp
*/

#include "bigint.h"



//////////////////////////Constructors//////////////////////////
//Default constructor
bigint::bigint()
{
	//initializing Bigint as 0 across the board
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		number[i] = 0;
	}
}

//Constructor to initalize an int value
bigint::bigint(int intValue) : bigint()
{
	//Initialize to zero using default constructor
	bigint();

	//assigning the int to each location within the array
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		number[i] = intValue % 10;
		intValue = intValue / 10;
	}
}

//Constructor to initialize an char[]
bigint::bigint(const char x[]) : bigint()
{
	int length = 0;
	int location = 0;

	//Sets bigint to zero using default constructor
	//Bigint();

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		number[i] = 0;
	}

	//Loops and adds a counter to "length" until null is found
	while (x[length] != '\0')
	{
		++length;
	}

	for (int i = length - 1; i >= 0; --i, ++location)
	{
		number[location] = int(x[i]) - int('0');
	}
}



///////////////////////Overload operators/////////////////////////
//Compares two bigint numbers and returns true of both are equal to eachother
bool bigint::operator==(const bigint& bigVariable) const
{
	//for loop to go through each element and return a boolean
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		if (number[i] != bigVariable.number[i])
			return false;
	}
	
	return true;
}

//Adds two bigint numbers and returns the new sum value
bigint bigint::operator+(bigint rhs) const
{
	int temp = 0, rmdr = 0;

	//for loop to add the new bigints and include the remainder as well
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		rmdr = number[i] + rhs.number[i] + rmdr;
		temp = rmdr % 10;
		rmdr = rmdr / 10;
		rhs.number[i] = temp;
	}

	return rhs;
}

//Overload subscript operator for non const and const
int& bigint::operator[](int i)
{
	return number[i];
}
int bigint::operator[](int i) const
{
	return number[i];
}

///////////////////friend functions///////////////////////////////
//output operator
std::ostream& operator<<(std::ostream& out, bigint& rhs)
{
	//initialize a variable for max size because max size cannot be manipulated
	int loop = MAX_SIZE;

	//Loop to find a number starting from max size
	while (rhs.number[loop] == 0)
		--loop;

	//Loop to ensure only 50 digits are printed per a line
	for (int i = loop; i >= 0; --i)
	{
		if (i % 50 == 0)
			out << rhs.number[i] << std::endl;
		else
			out << rhs.number[i];
	}

	return out;
}

//input operator
std::istream& operator>>(std::istream& in, bigint& rhs) 
{
	char ch = '0';
	char tmpArray[MAX_SIZE];

	//set tmpArray to 0 throughout the array
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		tmpArray[i] = 0;
	}

	in >> ch;

	//Create a loop that takes the input until MAX_SIZE or semi colon is input
	for (int j = 0; j < MAX_SIZE && ch != ';'; ++j)
	{
		tmpArray[j] = ch;
		in >> ch;
	}

	rhs = bigint(tmpArray);

	return in;
}
