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

	bool isExist(T element) const;
	bool empty() const;
	size_t size() const;
	bool erase(T element);	//删除第一个与element相等的结点
	void clear();
	T getFirst() const;
	T getLast() const;
	T get(unsigned pos) const;	//[1:length]
	MyIterator<T> begin() const;
	MyIterator<T> end() const;
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
bool MyList<T>::isExist(T element) const
{
	LNode<T> *p = head;
	while (p) {
		if (p->data == element) return true;
		p = p->next;
	}
	return false;
}

template<typename T>
bool MyList<T>::empty() const
{
	return !length;
}

template<typename T>
size_t MyList<T>::size() const
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
	length = 0;
}

template<typename T>
inline T MyList<T>::getFirst() const
{
	return head->data;
}

template<typename T>
T MyList<T>::getLast() const
{
	return tail->data;
}

template<typename T>
inline T MyList<T>::get(unsigned pos) const
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
inline MyIterator<T> MyList<T>::begin() const
{
	return MyIterator<T>(head);
}

template<typename T>
inline MyIterator<T> MyList<T>::end() const
{
	return MyIterator<T>(nullptr);
}
