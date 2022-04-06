#pragma once

#include <iostream>
#include <algorithm>
#include "bz_Iterator_forward_list.h"
template<typename T1>
struct Node {
	T1 val = NULL;
	Node<T1>* Next = nullptr;
	Node<T1>* Prev = nullptr;
};

template<typename T>
class bz_list {


public:
	Node<T>* root = nullptr;
	Node<T>* tail = nullptr;
public:
	int size = 0;
public:

	typedef bz_Iterator_forward_list<Node<T>> iterator;

	/*typedef bz_Iterator_forward_list<Node<T>> const_iterator;*/

	//////////////////////CONSTRUCTORS////////////////////////
	bz_list();
	//bz_list(int _size);
	//bz_list(int _val, int _size);
	//bz_list ( const bz_list<T>& vec);


	//////////////////////DESTRUCTOR////////////////////////
	~bz_list();
	///////////////////////ITERATORS//////////////////////////
	bz_Iterator_forward_list<Node<T>>begin();
	bz_Iterator_forward_list<Node<T>>end();

	/*const_iterator const cbegin();
	const_iterator const cend();*/
	////////////////////////MODIFIERS/////////////////////////
	void push_back(const T& val);
	void push_front(const T& val);
	void pop_front();
	void pop_back();
	iterator insert(bz_Iterator_forward_list<Node<T>>& iterator, const T& val);
	void insert(bz_Iterator_forward_list<Node<T>>& position, const bz_Iterator_forward_list<Node<T>>& first, const bz_Iterator_forward_list<Node<T>>& last);

	void erase(const bz_Iterator_forward_list<Node<T>>& iterator);
	void erase(const bz_Iterator_forward_list<Node<T>>& iterator_start, const bz_Iterator_forward_list<Node<T>>& iterator_end);
	void clear();
	//void swap(bz_vector<T>& second_vec);
	//void shrink_to_fit();

	/////////////////////ELEMENT-ACCESS///////////////////////
	//T& operator[](int index);
	inline T front();
	inline T back();
	////////////////////////CAPACITY//////////////////////////
	inline bool empty();
	inline int size_();

private:
	int get_distance(Node<T>* start, Node<T>* end) {
		int distance = 0;

		while (start != end)
		{
			start = start->Next;
			distance++;
		}

		return distance;
	}


};



template<typename T>
bz_list<T>::bz_list() {

}
//
//template<typename T>
// bz_list<T>:: bz_list  ( const bz_list<T>& other) {
//
//	 std::cout<< typeid(other.cbegin()).name();
//	// bz_list<T>::const_iterator it = other.cbegin();
//	//for (bz_list<T>::const_iterator it = other.cbegin(); it != other.cend(); it++) {
//	//	std::cout << "asd";
//	//}
//		/*this->push_back(it->val);*/
//			
//}

	////////////////////////MODIFIERS/////////////////////////
template<typename T>
void bz_list<T>::pop_back() {

	if (root == nullptr)
		return;

	Node<T>* troot = root;
	while (troot->Next->Next != nullptr)
		troot = troot->Next;

	troot->Next = nullptr;
	this->size--;


}

template<typename T>
void bz_list<T> ::pop_front() {

	if (root == nullptr)
		return;



	Node<T>* t_root = root;
	root = root->Next;
	delete t_root;
	this->size--;
}

template<typename T>
void bz_list<T> ::push_front(const T& val) {

	if (root == nullptr) {
		root = new Node<T>;
		root->val = val;
		this->size++;
		return;
	}

	Node<T>* t_root = root;
	Node<T>* new_node = new Node<T>;
	new_node->val = val;
	new_node->Next = root;
	root = new_node;

	this->size++;
}


template<typename T>
void bz_list<T> ::push_back(const T& val) {
	if (this->root == nullptr) {
		this->root = new Node<T>;
		this->root->val = val;
		this->size++;
		/*ROOT AND TAIL ARE THE SAME CUZ ONLY ONE ELEMENT IN THE LIST*/
		this->tail = this->root;
		return;
	}


	Node<T>* t_root = (root);
	while (t_root->Next != nullptr) {
		t_root = t_root->Next;
	}
	(t_root)->Next = new Node<T>;
	(t_root)->Next->val = val;
	
	/*TAIL HAVE CHANGED.*/
	this->tail = t_root->Next;
	this->size++;
}

template<typename T>
bz_Iterator_forward_list<Node<T>> bz_list<T>::insert(bz_Iterator_forward_list<Node<T>>& iterator, const T& val) {

	int insert_pos = this->get_distance(this->begin().m_ptr, iterator.m_ptr);
	if (insert_pos > this->size)
		throw std::invalid_argument("position is exceeded the list limit!");

	Node<T>* n_node = new Node<T>;
	n_node->val = val;
	n_node->Next = iterator.m_ptr;

	if (insert_pos >= 1) { (this->begin() + (insert_pos - 1))->Next = n_node; }
	else if (insert_pos == 0) { n_node->Next = root; root = n_node; }

	this->size++;

	return (this->begin() + insert_pos);
}

template<typename T>
void  bz_list<T>::insert(bz_Iterator_forward_list<Node<T>>& position, const bz_Iterator_forward_list<Node<T>>& first, const bz_Iterator_forward_list<Node<T>>& last) {
	
	bz_list<T>::iterator it = first;
	while (it != last) {
		this->insert(position, it->val); it++;
	}
}


template<typename T>
void  bz_list<T>::erase(const bz_Iterator_forward_list<Node<T>>& iterator) {

	int insert_pos = this->get_distance(this->begin().m_ptr, iterator.m_ptr);
	if (insert_pos > this->size)
		throw std::invalid_argument("position is exceeded the list limit!");
	
	Node<T>* t_node = nullptr;
	if(iterator == this->begin())
	{
		if (this->size == 1)
			this->clear();
		else {
			t_node = this->root;
			root = root->Next;
			delete t_node;
			}	
		return;
	}

	Node<T>* t_root = root;
	while (t_root->Next != iterator)
		t_root = t_root->Next;

	 t_node = t_root->Next->Next;
	delete t_root->Next;
	t_root->Next = t_node;

}

template<typename T>
void bz_list<T>::erase(const bz_Iterator_forward_list<Node<T>>& iterator_start, const bz_Iterator_forward_list<Node<T>>& iterator_end) {
	bz_list<T>::iterator it = iterator_start;

	while (it != iterator_end) {
		bz_list<T>::iterator t_it = it;
		it++;
		this->erase(t_it);
	}

	
}
template<typename T>
 bz_Iterator_forward_list<Node<T>> bz_list<T>::begin() {
	return bz_Iterator_forward_list<Node<T>>(root);
}

template<typename T>
bz_Iterator_forward_list<Node<T>>bz_list<T>::end() {
	return bz_Iterator_forward_list<Node<T>>(nullptr);
}
template<typename T>
void bz_list<T>::clear() {
	Node<T>* t_root = this->root;
	while (this->root != nullptr) {
		this->root = this->root->Next;
		delete t_root;
		t_root = this->root;
	}
}

//template<typename T>
//bz_Iterator_forward_list< Node<T>> const bz_list<T>::cbegin() {
//	return bz_Iterator_forward_list<  Node<T>>(root);
//}
//
//template<typename T>
//bz_Iterator_forward_list<  Node<T>> const bz_list<T>::cend()  {
//	return bz_Iterator_forward_list<  Node<T>>(nullptr);
//}


/////////////////////ELEMENT-ACCESS///////////////////////
template<typename T>
T bz_list<T>::front() { return this->root->val; }

template<typename T>
T bz_list<T>::back() { return this->tail->val; }


////////////////////////CAPACITY//////////////////////////
template<typename T>
inline bool bz_list<T>::empty() { return (this->size == 0); }
template<typename T>
int  bz_list<T>::size_() { return this->size; }



//////////////////////DESTRUCTOR////////////////////////
template<typename T>
bz_list<T>::~bz_list() {

	Node<T>* t_root = this->root;

	while (this->root != nullptr) {
		this->root = this->root->Next;
		delete t_root;
		t_root = this->root;
	}

}