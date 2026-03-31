#pragma once
#include <stdexcept>
#include <iostream>
namespace Mousseigne
{
	template <typename T>
	class MyQueue
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
		Node* frontNode;
		Node* backNode;
		int count;
	public:
		MyQueue()
		{
			frontNode = nullptr;
			backNode = nullptr;
			count = 0;
		}
		~MyQueue() { clear(); }
		void enqueue(const T& value)
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
		T dequeue()
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
		T front()
		{
			if (isEmpty())
			{
				throw std::runtime_error("The queue is empty.\n");
			}

			return frontNode->data;
		}
		T back()
		{
			if (isEmpty())
			{
				throw std::runtime_error("The queue is empty.\n");
			}
			return backNode->data;
		}
		bool isEmpty() const { return (count == 0); }
		void clear()
		{
			while (!isEmpty())
			{
				dequeue();
			}
		}
		int getCount() const { return count; }
	};

#include "MyClass.tpp"
};