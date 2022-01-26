// my_stl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

//#include "bz_vector.h"
//
//using namespace bz_std;
using namespace std;

template<typename T1>
class bz_Iterator
{
public:

	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T1;
	using pointer = T1*;
	using reference = T1&;
	pointer m_ptr;

	bz_Iterator(pointer ptr = nullptr) : m_ptr(ptr) {}

	reference operator*() const { return *m_ptr; }
	pointer operator->() { return m_ptr; }
	bz_Iterator& operator++() { m_ptr++; return *this; }
	bz_Iterator operator++(int) { bz_Iterator tmp = *this; ++(*this); return tmp; }
	bz_Iterator& operator +(int i) { m_ptr += i; return *this; }
	bz_Iterator& operator -(int i) { m_ptr -= i; return *this; }
	bz_Iterator& operator =(const T1 other) { std::swap(*m_ptr, other); std::cout << "assignment op" << endl; return *this; }
	friend bool operator== (const bz_Iterator& a, const bz_Iterator& b) { return a.m_ptr == b.m_ptr; };
	friend bool operator!= (const bz_Iterator& a, const bz_Iterator& b) { return a.m_ptr != b.m_ptr; };


};

template<typename T>
class bz_vector {

private:
	T* arr;
public:
	int size = 2;
	int capacity = 0;
	int current_pos = 0;
public:

	typedef bz_Iterator<T> iterator;


	//#########CONSTRUCTOR###################################
	bz_vector();
	bz_vector(int _size);
	bz_vector(int _val, int _size);
	~bz_vector();


	bz_Iterator<T>begin();
	bz_Iterator<T>end();

	//#########MODIFIERS###################################
	void push_back(const T& val);
	void pop_back();
	void insert(bz_Iterator<T>iterator, const T& val);
	void erase(bz_Iterator<T>iterator);


	//#########ELEMENT-ACCESS###################################
	T& operator[](int index);

	//########CAPACITY###################################
	inline bool IsEmpty();
};

//
template<typename T>
bz_vector<T>::bz_vector() { this->arr = new T[this->size]; }

template<typename T>
bz_vector<T>::bz_vector(int _size) { this->arr = new T[_size]; this->size = _size; }

template<typename T>
bz_vector<T>::bz_vector(int _val, int _size) {
	this->arr = new T[_size];
	this->size = _size;
	current_pos = _size;
	std::fill(this->begin(), this->end(), _val);

}
template<typename T>
bz_Iterator<T> bz_vector<T>::begin() {
	return  bz_Iterator<T>(&arr[0]);
}

template<typename T>
bz_Iterator<T> bz_vector<T>::end() {

	return  bz_Iterator<T>(&arr[current_pos]);
}


template<typename T>
void bz_vector<T>::push_back(const T& val) {

	if (this->current_pos >= this->size - 1) {
		arr[current_pos] = val;
		this->size = this->size * 2;
		T* temp_arr = new T[this->size];
		std::copy(arr, arr + current_pos + 1, temp_arr);
		delete[] arr;
		arr = temp_arr;
	}
	else
		arr[current_pos] = val;

	current_pos++;

}

template<typename T>
void  bz_vector<T>::pop_back() {
	if (!(this->IsEmpty()))
		this->current_pos--;

}
template<typename T>
bool bz_vector<T>::IsEmpty() {

	return this->current_pos == 0 ? true : false;
}

template<typename T>
void bz_vector<T>::insert(bz_Iterator<T>iterator, const T& val) {


	T t_val = val;
	int insert_pos = std::distance(this->begin(), iterator);

	if (insert_pos > this->current_pos)
		throw std::invalid_argument("position is exceeded the vector limit!");

	if (this->current_pos >= this->size-1) {
		this->size = this->size * 2;
		T* temp_arr = new T[this->size];
		std::copy(arr, arr + current_pos+1, temp_arr);
		delete[] arr;
		arr = temp_arr;	
	}

	current_pos++;
	for (size_t i = insert_pos; i <= this->current_pos; i++)
		std::swap(arr[i], t_val);

}

template<typename T>
bz_vector<T>::~bz_vector() { delete[] arr; }

template<typename T>
T& bz_vector<T>::operator[](int index) 
{
	if (index > this->current_pos)
		throw std::invalid_argument("position is exceeded the vector limit!");

	return arr[index];

}

int main()
{

	{

		bz_vector<int> a;
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		/*a[2] = 5;*/
		//a.push_back(5);
		//a.push_back(5);
		//a.push_back(5);
		//cout << a.size;
		//cout << a.current_pos;
		//a.push_back(6);
		/*cout << *(a.begin() + 1);*/
		/*a.pop_back();*/
		/*a.push_back(7);*/
		//cout << *it;
		//cout << *(it++);

		//bz_vector<int>::iterator it = a.begin();
		//for (; it != a.end(); it++)
		//{
		//	cout << *it;
		//}

		cout << "" << endl;

	/*	a.insert(a.begin() + 3, 7);*/
		bz_vector<int>::iterator it2 = a.begin();
		for (; it2 != a.end(); it2++)
		{
			cout << *it2;
		}

	}




	_CrtDumpMemoryLeaks();
}


