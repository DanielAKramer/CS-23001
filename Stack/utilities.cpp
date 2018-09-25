/*
	Daniel Kramer
	CS23001
	utilities.cpp
*/

#include "utilities.h"
#include "string.h"


//free function that converts infix to postfix
void infToPostf(std::ifstream& in, std::ofstream& out)
{
	Stack<String> s;
	String lhs, rhs, op, current;
	char token[300];

	//While file has not reached its end
	while (!in.eof()) 
	{
		in >> token;
		current = String(token);

		if (in.eof()) 
		{
			break;
		}

		//If reached ;, end the line
		if (current == ";") 
		{
			out << s;
			out << ";";
			out << std::endl;
			s = Stack<String>();
		}
		//If reached 0, pop x3 and push back onto stack as one string
		else if (current == ")") 
		{
			rhs = s.pop();
			op = s.pop();
			lhs = s.pop();
			s.push(lhs + rhs + op);
		}
		else 
		{
			if (current != "(") 
			{
				s.push(current + ' ');
			}
		}
	}
}

//converts stack to assembly
void toAssembly(std::ifstream& in, std::ofstream& out)
{
	Stack<String> s;
	String lhs, rhs, op, tempVar, currentT;
	int temp = 1;

	//While end of file has not been reached and string is not empty
	while (!in.eof() || !s.isEmpty())
	{
		if (!in.eof())
		{
			currentT = getToken(in);

		}
		else
		{
			break;
		}
		
		//If ;, start new line
		if (currentT == ";") {
			out << "-----------------------------------------" << std::endl;
			temp = 1;
		}

		if (!in.eof() && currentT != "+" && currentT != "-" && currentT != "*" && currentT != "/")
		{
			s.push(currentT);
		}
		else if (!in.eof())
		{
			rhs = s.pop();
			lhs = s.pop();

			out << "LD\t" << lhs << std::endl;

			op = assemblyOperator(currentT);
			out << op << rhs << std::endl;

			//Creates a string "TEMP 1" example
			tempVar = "TEMP" + iToS(temp++);
			s.push(tempVar);

			out << "SB\t" << tempVar << std::endl;
		}
	}
}

//Operators that will be included in the assembly string
String assemblyOperator(String& op)
{
	switch (op[0]) 
	{
	//addition
	case '+':
		return "AD\t";
		break;
	//subtraction
	case '-':
		return "SB\t";
		break;
	//multiplication
	case '*':
		return "MU\t";
		break;
	//division
	case '/':
		return "DV\t";
		break;
	default:
		return "UNDEFINED\t";
	}
}

String iToS(int x)
{
	if (!x)
	{
		return "0";
	}

	String result;

	while (x>0)
	{
		result += (x % 10 + 48);
		x /= 10;
	}

	return result;
}

String getToken(std::ifstream& in)
{
	String result;
	char token = '\0';

	for (int i = 0; token != ' ' && !in.eof(); ++i)
	{
		in.get(token);

		if (token == ';')
		{
			return ";";
		}
		else if (token != ' ')
		{
			result += token;
		}
	}

	return result;
}
