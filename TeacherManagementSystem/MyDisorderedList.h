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
	if (i == 1) head = s; //����ǵ�һ�����Ͱ�ͷָ��ָ��s
	else prior->next = s; //��ǰ��Ľڵ����s

	length++;

	if (length == i) tail = s; //��������λ��Ϊ��������βָ��

	return true;
}

template<typename T>
inline bool MyDisorderedList<T>::push_back(T element)
{
	LNode<T> *s = new LNode<T>;
	if (!s) return false;
	s->data = element;
	s->next = nullptr;

	if (length) tail->next = s; //�������Ϊ����β����next��ֵΪs
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

