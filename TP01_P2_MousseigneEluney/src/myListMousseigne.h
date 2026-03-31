#pragma once
#include <iostream>
#include <stdexcept>
namespace Mousseigne
{
	template <typename T>
	class Node
	{
	public:
		T data;
		Node* prev;
		Node* next;
		Node(const T& value);
	private:
	};
	template <typename N>
	class MyList
	{
	private:
		Node<N>* head;
		Node<N>* tail;
		int count;
		Node<N>* getNodeAt(int index) const;

	public:
		MyList();
		~MyList();

		void pushFront(const N& value);
		void pushBack(const N& value);

		N popFront();
		N popBack();

		void clear();

		int getCount() const;

		void insertAt(int index, const N& value);
		void removeAt(int index);

		N& operator[](int index);
		const N& operator[](int index) const;
		void print() const
		{
			Node<N>* current = head;
			std::cout << "[ ";
			while (current != nullptr)
			{
				std::cout << current->data << " ";
				current = current->next;
			}
			std::cout << "]\n";
		}
	};
#include "myListMousseigne.tpp"
};