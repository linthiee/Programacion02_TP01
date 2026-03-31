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
		Node(const T& value)
		{
			this->data = value;
			this->prev = nullptr;
			this->next = nullptr;
		}
	private:
	};
	template <typename N>
	class MyList
	{
	private:
		Node<N>* head;
		Node<N>* tail;
		int count;
		Node<N>* getNodeAt(int index) const
		{
			if (index < 0 || index >= count)
			{
				throw std::out_of_range("Index out of range");
			}
			Node<N>* current;
			if (index < count / 2)
			{
				current = head;
				for (int i = 0; i < index; i++)
				{
					current = current->next;
				}
			}
			else
			{
				current = tail;
				for (int i = count - 1; i > index; i--)
				{
					current = current->prev;
				}
			}
			return current;
		}
	public:
		MyList()
		{
			this->head = nullptr;
			this->tail = nullptr;
			this->count = 0;
		}
		~MyList() { clear(); }
		void pushFront(const N& value)
		{
			Node<N>* newNode = new Node<N>(value);
			if (head == nullptr)
			{
				tail = newNode;
				head = tail;
			}
			else
			{
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			count++;
		}
		void pushBack(const N& value)
		{
			Node<N>* newNode = new Node<N>(value);
			if (tail == nullptr)
			{
				tail = newNode;
				head = tail;
			}
			else
			{
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			count++;
		}
		N popFront()
		{
			if (head == nullptr)
			{
				throw std::out_of_range("List is empty");
			}
			N value = head->data;
			Node<N>* temp = head;
			head = head->next;
			if (head != nullptr)
			{
				head->prev = nullptr;
			}
			else
			{
				tail = nullptr;
			}
			delete temp;
			count--;
			return value;
		}
		N popBack()
		{
			if (tail == nullptr)
			{
				throw std::out_of_range("List is empty");
			}
			N value = tail->data;
			Node<N>* temp = tail;
			tail = tail->prev;
			if (tail != nullptr)
			{
				tail->next = nullptr;
			}
			else
			{
				head = nullptr;
			}
			delete temp;
			count--;
			return value;
		}
		void clear()
		{
			Node<N>* current = head;
			while (current != nullptr)
			{
				Node<N>* next = current->next;
				delete current;
				current = next;
			}
			tail = nullptr;
			head = nullptr;
			count = 0;
		}
		int getCount() const { return count; }
		void insertAt(int index, const N& value)
		{
			if (index < 0 || index > count)
			{
				throw std::out_of_range("Index out of range");
			}
			if (index == 0)
			{
				pushFront(value);
			}
			else if (index == count)
			{
				pushBack(value);
			}
			else
			{
				Node<N>* nextNode = getNodeAt(index);
				Node<N>* prevNode = nextNode->prev;
				Node<N>* newNode = new Node<N>(value);
				prevNode->next = newNode;
				newNode->prev = prevNode;
				newNode->next = nextNode;
				nextNode->prev = newNode;
				count++;
			}
		}
		void removeAt(int index)
		{
			if (index < 0 || index >= count)
			{
				throw std::out_of_range("Index out of range");
			}
			if (index == 0)
			{
				popFront();
			}
			else if (index == count - 1)
			{
				popBack();
			}
			else
			{
				Node<N>* nodeToRemove = getNodeAt(index);
				Node<N>* prevNode = nodeToRemove->prev;
				Node<N>* nextNode = nodeToRemove->next;
				prevNode->next = nextNode;
				nextNode->prev = prevNode;
				delete nodeToRemove;
				count--;
			}
		}
		N& operator[](int index) { return getNodeAt(index)->data; }
		const N& operator[](int index) const { return getNodeAt(index)->data; }
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
};