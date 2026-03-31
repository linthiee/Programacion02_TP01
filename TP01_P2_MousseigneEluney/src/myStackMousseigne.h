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
			Node(const T& value);
		};
		Node* topNode;
		int count;
	public:
		MyStack();
		~MyStack();

		void push(const T& value);

		T pop();
		T top();

		bool isEmpty() const;
		void clear();

		int getCount() const;
	};
}