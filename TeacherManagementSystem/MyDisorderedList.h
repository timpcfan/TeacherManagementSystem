#pragma once

#include "MyList.h"

template <typename T>
class MyDisorderedList : public MyList<T> {

public:
	MyDisorderedList();
	MyDisorderedList(T arr[], size_t n);
	virtual ~MyDisorderedList();

	bool insert(unsigned pos, T element);
	bool push_back(T element);
	bool push_front(T element);
};


template<typename T>
inline MyDisorderedList<T>::MyDisorderedList()
{
}

template<typename T>
inline MyDisorderedList<T>::MyDisorderedList(T arr[], size_t n)
{
	for (size_t i = 0; i < n; i++) {
		push_back(arr[i]);
	}
}

template<typename T>
MyDisorderedList<T>::~MyDisorderedList()
{
}

template<typename T>
inline bool MyDisorderedList<T>::insert(unsigned pos, T element)
{
	if (pos < 1 || pos > length + 1) return false;

	LNode<T> *p = head , *prior = head;

	unsigned i = 1;
	for (; i < pos; i++) {
		prior = p;
		p = p->next;
	}

	LNode<T> *s = new LNode<T>;
	if (!s) return false;

	s->data = element;
	s->next = p;
	if (i == 1) head = s; //如果是第一个，就把头指针指向s
	else prior->next = s; //把前面的节点接上s

	length++;

	if (length == i) tail = s; //如果插入的位置为最后则更新尾指针

	return true;
}

template<typename T>
inline bool MyDisorderedList<T>::push_back(T element)
{
	LNode<T> *s = new LNode<T>;
	if (!s) return false;
	s->data = element;
	s->next = nullptr;

	if (length) tail->next = s; //如果链表不为空则将尾结点的next赋值为s
	else head = s;
	
	tail = s;

	length++;

	return true;
}

template<typename T>
inline bool MyDisorderedList<T>::push_front(T element)
{
	LNode<T> *s = new LNode<T>;
	if (!s) return false;

	s->data = element;
	s->next = head;
	if (!length) tail = s;
	head = s;

	length++;

	return true;
}

