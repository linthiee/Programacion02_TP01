#include "myStackMousseigne.h"

template <typename T>
Mousseigne::MyStack<T>::Node::Node(const T& value)
{
	data = value;
	next = nullptr;
}

template <typename T>
Mousseigne::MyStack<T>::MyStack()
{
	topNode = nullptr;
	count = 0;
}

template <typename T>
Mousseigne::MyStack<T>::~MyStack() { clear(); }

template <typename T>
void Mousseigne::MyStack<T>::push(const T& value)
{
	Node* newNode = new Node(value);
	newNode->next = topNode;
	topNode = newNode;
	count++;
}

template <typename T>
T Mousseigne::MyStack<T>::pop()
{
	if (isEmpty())
	{
		throw std::runtime_error("The stack is empty.\n");
	}
	Node* tempNode = topNode;
	T value = tempNode->data;
	topNode = topNode->next;
	count--;
	delete tempNode;
	return value;
}

template <typename T>
T Mousseigne::MyStack<T>::top()
{
	if (isEmpty())
	{
		throw std::runtime_error("The stack is empty.\n");
	}
	return topNode->data;
}

template <typename T>
bool Mousseigne::MyStack<T>::isEmpty() const { return (count == 0); }

template <typename T>
void Mousseigne::MyStack<T>::clear()
{
	while (!isEmpty())
	{
		pop();
	}
}

template <typename T>
int Mousseigne::MyStack<T>::getCount() const { return count; }