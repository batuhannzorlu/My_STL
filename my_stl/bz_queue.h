#pragma once

#include "bz_list.h"

template <typename T>

class bz_queue {



public:
	bz_queue();

	T front();

private:
	bz_list<T> private_list;
};

template<typename T>
bz_queue<T>::bz_queue() {

}


template<typename T>
T bz_queue<T>:: front() {

}