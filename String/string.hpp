/*
	Daniel Kramer
	CS23001
	string.hpp
*/

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

const int DEFAULT_STRING_CAPACITY = 256;

class String 
{
public:
	//Constructors
	String();
	String(char);
	String(const char*);
	String(int, const char*);
	String(int);
	String(const String&);
	~String();

	//Operator Overloads
	String& operator=(String);
	bool operator==(const String&) const;
	bool operator<(const String&) const;
	String operator+(const String&) const;
	char& operator[](int);
	char operator[](int) const;

	int capacity() const;
	int length() const;

	void swap(String&);
	void resetCapacity(int);
	String subStr(int, int) const;
	int findChar(int, char) const;
	int findStr(int, const String) const;
	std::vector<String> split(char) const;

	int stringToInt(const String&);

	//Output
	friend std::ostream& operator<<(std::ostream&, const String&);

private:
	char *s;
	int Capacity;
};

//Input
std::istream& operator >> (std::istream&, String&);

//ENSURES free functions to overload operators
String operator+(const char[], const String&);
String operator+(char, const String&);
bool operator==(const char[], const String&);
bool operator==(char, const String&);
bool operator<(const char[], const String&);
bool operator<(char, const String&);
bool operator<=(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator>=(const String&, const String&);
bool operator>(const String&, const String&);

#endif
