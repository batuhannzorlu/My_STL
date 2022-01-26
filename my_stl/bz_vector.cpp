
#include <algorithm>
#include <iostream>
#include "bz_vector.h"

using namespace bz_std;
using namespace std;

template<typename T>
bz_vector<T>::bz_vector() { this->arr = new T[this->size]; }

template<typename T>
bz_vector<T>::bz_vector(int _size) { this->arr = new T[_size]; }

template<typename T>
bz_vector<T>::bz_vector(int _val, int _size) {
	this->arr = new T[_size];
	
	/*std::fill(_val, _size);*/

}

template<typename T>
T* bz_vector<T>::begin() { return this->arr+(this->size - 1); }

template<typename T>
T* bz_vector<T>::end() { return this->arr; }