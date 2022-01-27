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


	//#########CONSTRUCTOR###################################
	bz_vector();
	bz_vector(int _size);
	bz_vector(int _val, int _size);
	~bz_vector();


	bz_Iterator_forward<T>begin();
	bz_Iterator_forward<T>end();

	//#########MODIFIERS###################################
	void push_back(const T& val);
	void pop_back();
	void insert(bz_Iterator_forward<T>iterator, const T& val);
	void erase(bz_Iterator_forward<T>iterator);
	void clear();
	void swap(bz_vector<T>& second_vec);


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
bool bz_vector<T>::IsEmpty() {

	return this->current_pos == 0 ? true : false;
}

template<typename T>
void bz_vector<T>::insert(bz_Iterator_forward<T>iterator, const T& val) {


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
template<typename T>
void bz_vector<T>::clear() {


}

template<typename T>
void bz_vector<T>::swap(bz_vector<T>& second_vec) {

	int big_one = second_vec.current_pos < this->current_pos ? this->current_pos : second_vec.current_pos;
	if (second_vec.current_pos > this->current_pos) {
		this->size = second_vec.size;
		T* temp_arr = new T[this->size];
		std::copy(arr, arr + current_pos + 1, temp_arr);
		delete[] arr;
		arr = temp_arr;
	}
	else if (second_vec.current_pos < this->current_pos)
	{
		second_vec.size = this->size;
		T* temp_arr = new T[second_vec.size];
		std::copy(second_vec.arr, second_vec.arr + second_vec.current_pos + 1, temp_arr);
		delete[] second_vec.arr;
		second_vec.arr = temp_arr;
	}

	for (size_t i = 0; i <= big_one; i++)
		std::swap(this->arr[i], second_vec.arr[i]);

	std::swap(second_vec.current_pos, this->current_pos);
}

template<typename T>
void bz_vector<T>::erase(bz_Iterator_forward<T>iterator) {


}