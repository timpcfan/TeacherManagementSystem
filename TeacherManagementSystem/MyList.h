#pragma once

#include <cassert>
#include "MyIterator.h"



template <typename T>
class MyList {
	
protected:
	LNode<T> *head;
	LNode<T> *tail;
	size_t length;

	//无头结点，只有头指针
public:
	MyList();
	virtual ~MyList();

	bool isExist(T element);
	bool empty();
	size_t size();
	bool erase(T element);	//删除第一个与element相等的结点
	void clear();
	T getFirst();
	T getLast();
	T get(unsigned pos);	//[1:length]
	MyIterator<T> begin();
	MyIterator<T> end();
};


template<typename T>
MyList<T>::MyList()
	:head(nullptr), tail(nullptr), length(0)
{
}

template<typename T>
MyList<T>::~MyList()
{
	clear();
}


template<typename T>
bool MyList<T>::isExist(T element)
{
	LNode<T> *p = head;
	while (p) {
		if (p->data == element) return true;
		p = p->next;
	}
	return false;
}

template<typename T>
bool MyList<T>::empty()
{
	return !length;
}

template<typename T>
size_t MyList<T>::size()
{
	return length;
}

template<typename T>
bool MyList<T>::erase(T element)
{
	LNode<T> *p = head, *prior = nullptr;
	while (p && p->data != element) {
		prior = p;
		p = p->next;
	}
	if (!p) return false;
	if (p->data != element) return false;

	if (p == head) head = p->next; //当要删除的元素为第一个的时候，将头指针指向p的下一个
	else prior->next = p->next;

	if (p == tail) tail = prior;

	delete p;

	length--;

	return true;
}

template<typename T>
void MyList<T>::clear()
{
	LNode<T> *p = head, *q;
	while (p) {
		q = p;
		p = p->next;
		delete q;
	}
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline T MyList<T>::getFirst()
{
	return head->data;
}

template<typename T>
T MyList<T>::getLast()
{
	return tail->data;
}

template<typename T>
inline T MyList<T>::get(unsigned pos)
{
	assert(pos >= 1 && pos <= length);

	LNode<T> *p = head;
	unsigned i = 1;
	for (; i < pos; i++) {
		p = p->next;
	}
	return p->data;
}

template<typename T>
inline MyIterator<T> MyList<T>::begin()
{
	return MyIterator<T>(head);
}

template<typename T>
inline MyIterator<T> MyList<T>::end()
{
	return MyIterator<T>(nullptr);
}
