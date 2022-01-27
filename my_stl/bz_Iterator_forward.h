#pragma once

#include <iostream>
using namespace std;

template<typename T1>
class bz_Iterator_forward
{
public:

	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T1;
	using pointer = T1*;
	using reference = T1&;
	pointer m_ptr;

	bz_Iterator_forward(pointer ptr = nullptr) : m_ptr(ptr) {}

	reference operator*() const { return *m_ptr; }
	pointer operator->() { return m_ptr; }
	bz_Iterator_forward& operator++() { m_ptr++; return *this; }
	bz_Iterator_forward operator++(int) { bz_Iterator_forward tmp = *this; ++(*this); return tmp; }
	bz_Iterator_forward& operator +(int i) { m_ptr += i; return *this; }
	bz_Iterator_forward& operator -(int i) { m_ptr -= i; return *this; }
	bz_Iterator_forward& operator =(const T1 other) { std::swap(*m_ptr, other); std::cout << "assignment op" << endl; return *this; }
	friend bool operator== (const bz_Iterator_forward& a, const bz_Iterator_forward& b) { return a.m_ptr == b.m_ptr; };
	friend bool operator!= (const bz_Iterator_forward& a, const bz_Iterator_forward& b) { return a.m_ptr != b.m_ptr; };


};