#include "myQueueMousseigne.h"

template <typename T>
Mousseigne::MyQueue<T>::Node::Node(const T& value)
{
	data = value;
	next = nullptr;
}

template <typename T>
Mousseigne::MyQueue<T>::MyQueue()
{
	frontNode = nullptr;
	backNode = nullptr;
	count = 0;
}

template <typename T>
Mousseigne::MyQueue<T>::~MyQueue() { clear(); }

template <typename T>
void Mousseigne::MyQueue<T>::enqueue(const T& value)
{
	Node* newNode = new Node(value);
	if (isEmpty())
	{
		backNode = newNode;
		frontNode = backNode;
	}
	else
	{
		backNode->next = newNode;
		backNode = newNode;
	}
	count++;
}

template <typename T>
T Mousseigne::MyQueue<T>::dequeue()
{
	if (isEmpty())
	{
		throw std::runtime_error("The queue is empty.\n");
	}
	Node* tempNode = frontNode;
	T value = tempNode->data;
	frontNode = frontNode->next;
	count--;
	if (count == 0)
	{
		backNode = nullptr;
		frontNode = nullptr;
	}
	delete tempNode;
	return value;
}

template <typename T>
T Mousseigne::MyQueue<T>::front()
{
	if (isEmpty())
	{
		throw std::runtime_error("The queue is empty.\n");
	}

	return frontNode->data;
}

template <typename T>
T Mousseigne::MyQueue<T>::back()
{
	if (isEmpty())
	{
		throw std::runtime_error("The queue is empty.\n");
	}
	return backNode->data;
}

template <typename T>
bool Mousseigne::MyQueue<T>::isEmpty() const { return (count == 0); }

template <typename T>
void Mousseigne::MyQueue<T>::clear()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template <typename T>
int Mousseigne::MyQueue<T>::getCount() const { return count; }