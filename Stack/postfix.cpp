/*
  Daniel Kramer
  CS23001
  postfix.cpp
*/

#include <fstream>
#include "stack.hpp"
#include "string.hpp"

// Converts infix to postfix
void to_postfix(std::ifstream&, std::ofstream&);

// ./postfix.out input.txt output.txt
int main(int argc, char const* argv[])
{
	// If input file isn't present, display help and leave
	if (argc < 2) 
	{
		std::cerr << "No input file present!" << std::endl;
		return 1;
	}

	// Open the infix file
	std::ifstream infix_file(argv[1]);

	// If no infix file, show help and exit
	if (!infix_file) 
	{
		std::cerr << "Infix file could not be opened!" << std::endl;
		return 1;
	}

	std::ofstream postfix_file(argv[2]);

	// If file can't be opened, display help and exit
	if (!postfix_file) 
	{
		std::cerr << "Output file can't be opened! Please try again!" << std::endl;
		return 1;
	}

	to_postfix(infix_file, postfix_file);

	infix_file.close();
	postfix_file.close();

	return 0;
}

//converts the stack to a postfix expression
void to_postfix(std::ifstream& in, std::ofstream& out)
{
	Stack<std::string> s;
	std::string lhs,
		rhs,
		op,
		currentToken;
	char token[300];

	while (!in.eof()) 
	{
		in >> token;
		currentToken = std::string(token);

		if (in.eof()) 
		{
			break;
		}

		if (currentToken == ";") 
		{
			out << s;
			out << ";";
			out << std::endl;
			s = Stack<std::string>();
		}
		else if (currentToken == ")") 
		{
			rhs = s.pop();
			op = s.pop();
			lhs = s.pop();
			s.push(lhs + rhs + op);
		}
		else 
		{
			if (currentToken != "(") 
			{
				s.push(currentToken + ' ');
			}
		}
	}
}
