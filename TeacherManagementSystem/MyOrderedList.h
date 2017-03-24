#pragma once

#include "MyList.h"
#include "MyIterator.h"


template <typename T>
class MyOrderedList : public MyList<T> {

public:
	MyOrderedList();
	MyOrderedList(T arr[], size_t n);
	virtual ~MyOrderedList();

	bool insert(T element);

};


template<typename T>
MyOrderedList<T>::MyOrderedList()
{
}

template<typename T>
inline MyOrderedList<T>::MyOrderedList(T arr[], size_t n)
{
	for (size_t i = 0; i < n; i++) {
		insert(arr[i]);
	}
}

template<typename T>
MyOrderedList<T>::~MyOrderedList()
{
}

template <typename T>
bool MyOrderedList<T>::insert(T element)
{
	LNode<T> *p = head, *prior = nullptr;
	LNode<T> *s = new LNode<T>;
	if (!s) return false;
	s->data = element;
	s->next = nullptr;



	if (!length) {
		head = s;
		tail = s;
		length++;
		return true;
	}

	if (!(s->data < tail->data)) {
		tail->next = s;
		tail = s;
		length++; 
		return true;
	}

	while (p && p->data < s->data) { //插入的位置为prior之后p之前
		prior = p;
		p = p->next;
	}

	//链表不为空且插在第一个位置
	if (!prior) {
		head = s;
		s->next = p;
		length++;
		return true;
	}

	//链表不为空且不在第一个位置
	prior->next = s;
	s->next = p;
	length++;
	return true;
}

