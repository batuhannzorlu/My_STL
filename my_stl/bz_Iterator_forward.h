#pragma once

#include <iostream>
#include "bz_vector.h"
//#include "bz_list.h"
#include<string>

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
	
	///???????
	bz_Iterator_forward& operator =(const T1 other) { std::swap(*m_ptr, other); std::cout << "assignment op" << endl; return *this; }
	friend bool operator== (const bz_Iterator_forward& a, const bz_Iterator_forward& b) { return a.m_ptr == b.m_ptr; };
	friend bool operator!= (const bz_Iterator_forward& a, const bz_Iterator_forward& b) { return a.m_ptr != b.m_ptr; };


	bz_Iterator_forward& operator +=(int i) { m_ptr += i; return *this; }
	bz_Iterator_forward& operator -=(int i) { m_ptr -= i; return *this; }


};



//template<typename Type>
//class Container<Type>::Iterator : public std::iterator<std::random_access_iterator_tag, Type>
//{
//public:
//    using difference_type = typename std::iterator<std::random_access_iterator_tag, Type>::difference_type;
//
//    Iterator() : _ptr(nullptr) {}
//    Iterator(Type* rhs) : _ptr(rhs) {}
//    Iterator(const Iterator& rhs) : _ptr(rhs._ptr) {}
//    /* inline Iterator& operator=(Type* rhs) {_ptr = rhs; return *this;} */
//    /* inline Iterator& operator=(const Iterator &rhs) {_ptr = rhs._ptr; return *this;} */
//    inline Iterator& operator+=(difference_type rhs) { _ptr += rhs; return *this; }
//    inline Iterator& operator-=(difference_type rhs) { _ptr -= rhs; return *this; }
//    inline Type& operator*() const { return *_ptr; }
//    inline Type* operator->() const { return _ptr; }
//    inline Type& operator[](difference_type rhs) const { return _ptr[rhs]; }
//
//    inline Iterator& operator++() { ++_ptr; return *this; }
//    inline Iterator& operator--() { --_ptr; return *this; }
//    inline Iterator operator++(int) const { Iterator tmp(*this); ++_ptr; return tmp; }
//    inline Iterator operator--(int) const { Iterator tmp(*this); --_ptr; return tmp; }
//    /* inline Iterator operator+(const Iterator& rhs) {return Iterator(_ptr+rhs.ptr);} */
//    inline difference_type operator-(const Iterator& rhs) const { return _ptr - rhs.ptr; }
//    inline Iterator operator+(difference_type rhs) const { return Iterator(_ptr + rhs); }
//    inline Iterator operator-(difference_type rhs) const { return Iterator(_ptr - rhs); }
//    friend inline Iterator operator+(difference_type lhs, const Iterator& rhs) { return Iterator(lhs + rhs._ptr); }
//    friend inline Iterator operator-(difference_type lhs, const Iterator& rhs) { return Iterator(lhs - rhs._ptr); }
//
//    inline bool operator==(const Iterator& rhs) const { return _ptr == rhs._ptr; }
//    inline bool operator!=(const Iterator& rhs) const { return _ptr != rhs._ptr; }
//    inline bool operator>(const Iterator& rhs) const { return _ptr > rhs._ptr; }
//    inline bool operator<(const Iterator& rhs) const { return _ptr < rhs._ptr; }
//    inline bool operator>=(const Iterator& rhs) const { return _ptr >= rhs._ptr; }
//    inline bool operator<=(const Iterator& rhs) const { return _ptr <= rhs._ptr; }
//private:
//    Type* _ptr;
//};


