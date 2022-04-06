#pragma once

#include <iostream>
#include "bz_vector.h"
//#include "bz_list.h"
#include<string>

using namespace std;

template<typename T1>
class bz_Iterator_reverse
{
public:

	//using iterator_category = std::reverse_iterator;
	using difference_type = std::ptrdiff_t;
	using value_type = T1;
	using pointer = T1*;
	using reference = T1&;
	pointer m_ptr;


	bz_Iterator_reverse(pointer ptr = nullptr) : m_ptr(ptr) {}

	reference operator*() const { return *m_ptr; }
	pointer operator->() { return m_ptr; }



	bz_Iterator_reverse& operator++() { m_ptr--; return *this; }
	bz_Iterator_reverse operator++(int) { bz_Iterator_reverse tmp = *this; --(*this); return tmp; }

	bz_Iterator_reverse& operator +(int i) { m_ptr -= i; return *this; }
	bz_Iterator_reverse& operator -(int i) { m_ptr += i; return *this; }

	///???????
	bz_Iterator_reverse& operator =(const T1 other) { std::swap(*m_ptr, other); std::cout << "assignment op" << endl; return *this; }
	friend bool operator== (const bz_Iterator_reverse& a, const bz_Iterator_reverse& b) { return a.m_ptr == b.m_ptr; };
	friend bool operator!= (const bz_Iterator_reverse& a, const bz_Iterator_reverse& b) { return a.m_ptr != b.m_ptr; };


	bz_Iterator_reverse& operator +=(int i) { m_ptr -= i; return *this; }
	bz_Iterator_reverse& operator -=(int i) { m_ptr += i; return *this; }

private:
	bz_Iterator_reverse& operator--() { m_ptr -= 1; return *this; }
};