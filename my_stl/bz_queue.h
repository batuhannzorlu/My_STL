#pragma once

#include "bz_stack.h"

template <typename T>

class bz_queue {



public:
	bz_queue();

	T front();
	T back();
	void push_back(T value);
	void pop_front();

	bool empty();

private:
	bz_stack<T> private_front;
	bz_stack<T> private_back;

	/*If back stack is empty, will shift all the values from front stack to back stack.*/
	void shifting();
	T back_val=NULL;
};

template<typename T>
bz_queue<T>::bz_queue() {

}


template<typename T>
T bz_queue<T>:: front() {
		
	if (this->private_back.empty() == true && this->private_front.empty() == false)
		this->shifting();

	return this->private_back.top();

}

template<typename T>
T bz_queue<T> :: back() {
	return back_val;
	
		
}

template<typename T>
void bz_queue<T>::push_back(T value) {
		
	this->private_front.push(value);
	back_val = value;
}
template<typename T>
void bz_queue<T>::pop_front() {
	
	if (this->private_back.empty() == true && this->private_front.empty() == false)
		this->shifting();
		
	this->private_back.pop();
	
}


template<typename T>
bool bz_queue<T>::empty() {

	if (this->private_back.empty() == true && this->private_front.empty() == true)
		return true;

	return false;

}

template<typename T>
void bz_queue<T> ::shifting() {

		while (!this->private_front.empty()) {
			this->private_back.push(this->private_front.top());
			this->private_front.pop();
		}
}