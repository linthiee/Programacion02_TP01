#pragma once
#include <stdexcept>
#include <iostream>
namespace Mousseigne
{
	template <typename T>
	class MyStack
	{
	private:
		class Node
		{
		public:
			T data;
			Node* next;
			Node(const T& value)
			{
				data = value;
				next = nullptr;
			}
		};
		Node* topNode;
		int count;
	public:
		MyStack()
		{
			topNode = nullptr;
			count = 0;
		}
		~MyStack() { clear(); }
		void push(const T& value)
		{
			Node* newNode = new Node(value);
			newNode->next = topNode;
			topNode = newNode;
			count++;
		}
		T pop()
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
		T top()
		{
			if (isEmpty())
			{
				throw std::runtime_error("The stack is empty.\n");
			}
			return topNode->data;
		}
		bool isEmpty() const { return (count == 0); }
		void clear()
		{
			while (!isEmpty())
			{
				pop();
			}
		}
		int getCount() const { return count; }
	};
}