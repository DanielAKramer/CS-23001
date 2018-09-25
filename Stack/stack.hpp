/*
	Daniel Kramer
	CS23001
	stack.hpp
*/
#ifndef STACK_HPP
#define STACK_HPP


# include <iostream>
# include <new> 
#include <cassert>

//Class to keep data of each individual node within the stack
template <typename T>
class node 
{
public:

	//default Ctor
	node() : next(0) {};
	//Fills in data of the one node
	node(const T& x) : data(x), next(0) {};

	T data;
	node <T> * next;
};

template <typename T>
class Stack 
{
public:
	//Constructors
	Stack() : tos(0) {};
	~Stack(); 
	Stack(const Stack<T>&);

	void swap(Stack <T> &);
	Stack<T> & operator = (Stack <T>);
	bool isEmpty() const { return tos == 0; };
	bool isFull() const;
	void push(const T&);
	T top() const; 
	T pop();

private:
	node <T> *tos;
};


//copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& actual) 
{
	node<T> * temp = actual.tos, *bottom = nullptr;
	tos = 0;

	//Loop occurs when tos is pointing to a node
	while (temp != 0) 
	{
		//if tos equals 0, tos is equal to temps data, bottom is equal to tos
		if (tos == 0) 
		{ 
			tos = new node<T>(temp->data); 
			bottom = tos; 
		}
		//bottom gets temps data, points to next node
		else 
		{
			bottom->next = new node<T>(temp->data);
			bottom = bottom->next;
		}

		//temp is pointing to next node in temps stack
		temp = temp->next;
	}
}

//swap constructor
template <typename T>
void Stack<T>::swap(Stack<T>& rhs) 
{
	node <T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}

//Checks stack if it is full
template<typename T>
bool Stack<T>::isFull()const 
{
	node<T> * temp = new(std::nothrow) node<T>;

	//If memory is full and stack is pointing to null pointer, stack is full
	if (temp == nullptr)
		return true;

	delete temp;
	return false;
}

//Assignment operator
template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> rhs) 
{
	swap(rhs);
	return *this;
}

//destructor
template <typename T>
Stack<T>::~Stack() 
{
	node<T> * temp;
	
	while (tos != 0) 
	{
		temp = tos;
		tos = tos->next;

		delete temp;
	}
}

//puts a new node on top of stack
template <typename T>
void Stack<T>::push(const T& x) 
{
	//assures that a new node can put placed on tos
	assert(!isFull());

	node<T> *temp = new node<T>(x);

	temp->next = tos;
	tos = temp;
}

//takes the top node off stack
template<typename T>
T Stack<T>::pop()
{
	//assures stack is not empty and there is a node to delete
	assert(!isEmpty());

	T result = tos->data;

	node<T> * temp = tos;
	tos = tos->next;

	delete temp;
	return result;
}


template<typename T>
T Stack<T>::top() const 
{
	assert(!isEmpty());
	return tos->data;
}

#endif
