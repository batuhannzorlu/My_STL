#pragma once

#include "bz_list.h"

template <typename T>

class bz_queue {



public:
	bz_queue();

	T front();
	T back();
	void push_back();
	void pop_front();

private:
	bz_list<T> private_q;
};

template<typename T>
bz_queue<T>::bz_queue() {

}


template<typename T>
T bz_queue<T>:: front() {

}

template<typename T>
T bz_queue<T> :: back() {

}

template<typename T>
void bz_queue<T>::push_back() {

}
template<typename T>
void bz_queue<T>::pop_front() {

}