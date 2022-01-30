#pragma once

namespace counter {
	struct ref_counter
	{
		int counter;
		ref_counter() :counter(0) {}
	};
}


template <typename T>
class bz_sharedptr {

private:
	T* private_pointer = nullptr;
	counter::ref_counter* counter=nullptr;
public:
	bz_sharedptr();
	bz_sharedptr(int size);
	bz_sharedptr(bz_sharedptr<T>& sp);
	~bz_sharedptr();
public:

	inline T& operator*() { return *private_pointer; }
	inline T* operator->() { return private_pointer; }
	inline bz_sharedptr<T>& operator=( bz_sharedptr<T>& right) {
		private_pointer = right.private_pointer;
		counter = right.counter;
		counter->counter++;
		return *this;
	}
	inline int use_count() { return counter->counter; }
	void swap(bz_sharedptr<T>& other_ptr);
	T* get();
	void reset();

};
template <typename T>
bz_sharedptr<T>::bz_sharedptr() {
	/*counter = new counter::ref_counter;*/
	/*counter->counter++;*/
}
template <typename T>
bz_sharedptr<T>::bz_sharedptr(int size) {

	
	counter = new counter::ref_counter;
	counter->counter++;
	private_pointer = new T[size];
}

template <typename T>
bz_sharedptr<T>::bz_sharedptr(bz_sharedptr<T>& sp)
{
	private_pointer = sp.private_pointer;
	counter = sp.counter;
	counter->counter++;
}

template <typename T>
bz_sharedptr<T>::~bz_sharedptr() {

	counter->counter--;
	if (counter->counter <= 0) {
		delete[] private_pointer;
		delete counter;
	}

}

template<typename T>
void bz_sharedptr<T>::swap(bz_sharedptr<T>& other_ptr) {

	std::swap(this->private_pointer, other_ptr.private_pointer);

}


template<typename T>
T* bz_sharedptr<T>::get() {

	return this->private_pointer;
}


template<typename T>
void bz_sharedptr<T>::reset() {
	this->counter--;
	if (counter->counter <= 0)
		this->~bz_sharedptr();
	else
		delete this->private_pointer;
}