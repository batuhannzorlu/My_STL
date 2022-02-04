#pragma once

#include <iostream>
#include <algorithm>
#include "bz_Iterator_forward.h"

template<typename T1>
struct Node {
	T1 val = NULL;
	Node<T1>* Next = nullptr;
	Node<T1>* Prev = nullptr;
};



template<typename T>
class bz_list {

	//int size = 0;

public:
	Node<T>* root = nullptr;
	Node<T>* tail = nullptr;
	//T* arr;
public:
	int size =0;
	int current_pos = 0;
public:

	typedef bz_Iterator_forward<Node<T>> iterator;


	//////////////////////CONSTRUCTORS////////////////////////
	bz_list();
	//bz_list(int _size);
	//bz_list(int _val, int _size);
	//bz_list(bz_list<T>& vec);

	~bz_list();
	///////////////////////ITERATORS//////////////////////////
	bz_Iterator_forward<Node<T>>begin();
	bz_Iterator_forward<Node<T>>end();

	////////////////////////MODIFIERS/////////////////////////
	void push_back(const T& val);
	void push_front(const T& val);
	void pop_front();
	void pop_back();
	//iterator insert(bz_Iterator_forward<T>& iterator, const T& val);
	//void insert(bz_Iterator_forward<T> position, const bz_Iterator_forward<T>& first, const bz_Iterator_forward<T>& last);

	//void erase(const bz_Iterator_forward<T>& iterator);
	//void erase(const bz_Iterator_forward<T>& iterator_start, const bz_Iterator_forward<T>& iterator_end);
	//void clear();
	//void swap(bz_vector<T>& second_vec);
	//void shrink_to_fit();

	/////////////////////ELEMENT-ACCESS///////////////////////
	//T& operator[](int index);
	//T front();
	//T back();
	//T at(int index);
	////////////////////////CAPACITY//////////////////////////
	//inline bool empty();



};



template<typename T>
bz_list<T>::bz_list() {

}

template<typename T>
void bz_list<T>::pop_back() {

	if (root == nullptr)
		return;

	Node<T>* troot = root;
	while (troot->Next->Next != nullptr)
		troot = troot->Next;

	troot->Next = nullptr;
	size--;


}

template<typename T>
void bz_list<T> ::pop_front() {

	if (root == nullptr)
		return;



	Node<T>* t_root = root;
	root = root->Next;
	delete t_root;
	size--;
}

template<typename T>
void bz_list<T> ::push_front(const T& val) {

	if (root == nullptr) {
		root = new Node<T>;
		root->val = val;
		return;
	}

	Node<T>* t_root = root;
	Node<T>* new_node = new Node<T>;
	new_node->val = val;
	new_node->Next = root;
	root = new_node;

	size++;
}


template<typename T>
void bz_list<T> ::push_back(const T& val) {
	if (root == nullptr) {
		root = new Node<T>;
		root->val = val;
		return;
	}

	Node<T>* t_root = (root);
	while (t_root->Next != nullptr) {
		t_root = t_root->Next;
	}
	(t_root)->Next = new Node<T>;
	(t_root)->Next->val = val;


	size++;
}



template<typename T>
bz_Iterator_forward<Node<T>> bz_list<T>::begin() {

	return bz_Iterator_forward<Node<T>>(root);
}

template<typename T>
bz_Iterator_forward<Node<T>>bz_list<T>::end() {
	return bz_Iterator_forward<Node<T>>(tail);
}


template<typename T>
bz_list<T>::~bz_list() {

	Node<T>* t_root = *(&this->root);

	while (this->root != nullptr) {
		this->root = this->root->Next;
		delete t_root;
		t_root = this->root;
	}

}