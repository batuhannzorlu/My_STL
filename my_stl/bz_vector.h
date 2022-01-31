#pragma once

#include <iostream>
#include <algorithm>
#include "bz_Iterator_forward.h"

using namespace std;

template<typename T>
class bz_vector {

private:
	T* arr;
public:
	int size = 2;
	int capacity = 0;
	int current_pos = 0;
public:

	typedef bz_Iterator_forward<T> iterator;


	//////////////////////CONSTRUCTORS////////////////////////
	bz_vector();
	bz_vector(int _size);
	bz_vector(int _val, int _size);
	bz_vector(bz_vector<T>& vec);

	~bz_vector();

	///////////////////////ITERATORS//////////////////////////
	bz_Iterator_forward<T>begin();
	bz_Iterator_forward<T>end();

	////////////////////////MODIFIERS/////////////////////////
	void push_back(const T& val);
	void pop_back();
	iterator insert(bz_Iterator_forward<T>& iterator, const T& val);
	void insert(bz_Iterator_forward<T> position,const bz_Iterator_forward<T>& first,const bz_Iterator_forward<T>& last);

	void erase(const bz_Iterator_forward<T>& iterator);
	void erase(const bz_Iterator_forward<T>& iterator_start, const bz_Iterator_forward<T>& iterator_end);
	void clear();
	void swap(bz_vector<T>& second_vec);
	void shrink_to_fit();

	///////////////////ELEMENT-ACCESS///////////////////////
	T& operator[](int index);
	T front();
	T back();
	T at(int index);
	//////////////////////CAPACITY//////////////////////////
	inline bool empty();
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
bz_vector<T>::bz_vector(bz_vector<T>& vec) {
	
	this->arr = new T[this->size];
	this->insert(this->begin(), vec.begin(), vec.end());


}
template<typename T>
bz_Iterator_forward<T> bz_vector<T>::begin() {
	return  bz_Iterator_forward<T>(&arr[0]);
}

template<typename T>
bz_Iterator_forward<T> bz_vector<T>::end() {

	return  bz_Iterator_forward<T>(&arr[current_pos]);
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
bool bz_vector<T>::empty() {

	return this->current_pos == 0 ? true : false;
}

template<typename T>
bz_Iterator_forward<T> bz_vector<T>::insert( bz_Iterator_forward<T>& iterator, const T& val) {


	T t_val = val;
	int insert_pos = std::distance(this->begin(), iterator);

	if (insert_pos > this->current_pos)
		throw std::invalid_argument("position is exceeded the vector limit!");

	if (this->current_pos >= this->size - 1) {
		this->size = this->size * 2;
		T* temp_arr = new T[this->size];
		std::copy(arr, arr + current_pos + 1, temp_arr);
		delete[] arr;
		arr = temp_arr;
		iterator = (this->begin() + insert_pos);
	}

	current_pos++;
	for (size_t i = insert_pos; i <= this->current_pos; i++)
		std::swap(arr[i], t_val);

	return (this->begin() + insert_pos);
}

template<typename T>
void bz_vector<T> ::insert(bz_Iterator_forward<T> position, const bz_Iterator_forward<T>& first,const bz_Iterator_forward<T>& last) {

	bz_Iterator_forward<T> it = first;
	while (it != last) {
		insert(position, *(it.m_ptr));
		it++;
	}

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
template<typename T>
void bz_vector<T>::clear() {


}

template<typename T>
void bz_vector<T>::swap(bz_vector<T>& second_vec) {

	int big_one = second_vec.current_pos < this->current_pos ? this->current_pos : second_vec.current_pos;
	T* temp_arr = nullptr;
	if (second_vec.current_pos > this->current_pos) {
		this->size = second_vec.size;
		temp_arr = new T[this->size];
		std::copy(arr, arr + current_pos + 1, temp_arr);
		delete[] arr;
		arr = temp_arr;
	}
	else if (second_vec.current_pos < this->current_pos)
	{
		second_vec.size = this->size;
		temp_arr = new T[this->size];
		std::copy(second_vec.arr, second_vec.arr + second_vec.current_pos + 1, temp_arr);
		delete[] second_vec.arr;
		second_vec.arr = temp_arr;
	}

	for (size_t i = 0; i <= big_one; i++)
		std::swap(this->arr[i], second_vec.arr[i]);

	std::swap(second_vec.current_pos, this->current_pos);
}

template<typename T>
void bz_vector<T>::erase(const bz_Iterator_forward<T>& iterator) {


	int _distance = std::distance(this->begin(), iterator);
	for (size_t i = _distance; i < current_pos; i++)
		std::swap(arr[i], arr[i + 1]);

	this->current_pos--;
}

// This is a temporary solution. better algorithm will be applied.
template<typename T>
void bz_vector<T>::erase(const bz_Iterator_forward<T>& iterator_start, const bz_Iterator_forward<T>& iterator_end) {

	//bz_vector<T>::iterator it = iterator_start;
	//for(;  it!= iterator_end; it++)
	//	this->erase(it); cout << "a" << endl;



}
template<typename T>
void bz_vector<T>::shrink_to_fit() {
	T* t_arr = new T[current_pos];
	std::copy(this->arr, this->arr + current_pos, t_arr);
	this->size = current_pos;
	delete[]arr;
	arr = t_arr;
}

template<typename T>
T bz_vector<T> ::front() { return arr[0]; }
template<typename T>
T bz_vector<T> ::back() { return arr[current_pos]; }
template<typename T>
T bz_vector<T> ::at(int index) { return arr[index]; }