#pragma once
#include <iostream>
template<typename T>
class bz_uniqueptr {

private:
	T* unique_ptr = nullptr;

public:
	bz_uniqueptr(int size);
	~bz_uniqueptr();
public:

	//MODIFIERS 
	//Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer.
	T release();
	void swap(bz_uniqueptr<T>& other_ptr);
	void reset();
	T* get();

	T* operator->() { return this->unique_ptr; }
	T& operator *() { return *(this->unique_ptr); }
	operator bool() const { return this->unique_ptr != nullptr ? true : false; }

};


template<typename T>
bz_uniqueptr<T>::bz_uniqueptr(int size) {

	this->unique_ptr = new T[size];
}

template<typename T>
bz_uniqueptr<T>::~bz_uniqueptr() {

	delete[] this->unique_ptr;

}

template<typename T>
T* bz_uniqueptr<T>::get() {

	return this->unique_ptr;
}

template<typename T>
T bz_uniqueptr<T>::release() {
	T t_val = *(this->unique_ptr);
	this->unique_ptr = nullptr;
	return t_val;
}

template<typename T>
void bz_uniqueptr<T>::reset() {
	delete[] this->unique_ptr;
}

template<typename T>
void bz_uniqueptr<T>::swap(bz_uniqueptr<T>& other_ptr) {

	std::swap(this->unique_ptr, other_ptr.unique_ptr);

}