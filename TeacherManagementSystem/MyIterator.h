#pragma once

#include <cassert>
#include "MyList.h"
template <typename T>
struct LNode {
	T data;
	LNode *next;
};


template <typename T>
class MyIterator {

private:
	LNode<T> *ptr;
public:
	MyIterator();
	MyIterator(LNode<T> *p);
	T & operator*() const;
	void operator++(int);
	bool operator==(const MyIterator & other) const;
	bool operator!=(const MyIterator & other) const;
};

template<typename T>
inline MyIterator<T>::MyIterator()
	:ptr(nullptr)
{
}

template<typename T>
inline MyIterator<T>::MyIterator(LNode<T>* p)
	:ptr(p)
{
}

template<typename T>
inline T & MyIterator<T>::operator*() const
{
	assert(ptr);
	return ptr->data;
}

template<typename T>
inline void MyIterator<T>::operator++(int)
{
	assert(ptr);
	ptr = ptr->next;
}


template<typename T>
inline bool MyIterator<T>::operator==(const MyIterator & other) const
{
	return this->ptr == other.ptr;
}

template<typename T>
inline bool MyIterator<T>::operator!=(const MyIterator & other) const
{
	return !(this->ptr == other.ptr);
}


