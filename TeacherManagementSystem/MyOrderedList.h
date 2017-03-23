#pragma once

#include "MyList.h"
#include <iostream>

template <typename T>
class MyOrderedList : public MyList<T> {

public:
	MyOrderedList();
	virtual ~MyOrderedList();

	bool insert(T element);

};


template<typename T>
MyOrderedList<T>::MyOrderedList()
{
}

template<typename T>
MyOrderedList<T>::~MyOrderedList()
{
}

template <typename T>
bool MyOrderedList<T>::insert(T element)
{
	return false;
}

