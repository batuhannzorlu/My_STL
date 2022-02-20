#pragma once

#include <iostream>
#include <algorithm>
//#include "bz_Iterator_forward.h"

template<typename T1>
struct Node {
	T1 val = NULL;
	Node<T1>* Next = nullptr;
	Node<T1>* Prev = nullptr;
};

template<typename T1>
class bz_Iterator_forward_list
{
public:

	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T1;
	using pointer = T1*;
	using reference = T1&;
	pointer m_ptr;


	bz_Iterator_forward_list(pointer ptr = nullptr) : m_ptr(ptr) {}

	reference operator*() const { return *m_ptr; }
	pointer operator->() { return m_ptr; }
	bz_Iterator_forward_list& operator++() { this->m_ptr = this->m_ptr->Next; return *this; }
	bz_Iterator_forward_list operator++(int) { bz_Iterator_forward_list tmp = *this; this->m_ptr = this->m_ptr->Next; return tmp; }

	bz_Iterator_forward_list& operator +(int i) {
		while (i >= 1) { this->m_ptr = this->m_ptr->Next; i--; } return *this;
	}
	bz_Iterator_forward_list& operator -(int i) {
		while (i >= 1) { this->m_ptr = this->m_ptr->Prev; i--; } return *this;
	}

	/////???????
	////bz_Iterator_forward_list& operator =(const T1 other) { std::swap(*m_ptr, other); std::cout << "assignment op" << endl; return *this; }
	friend bool operator== (const bz_Iterator_forward_list& a, const bz_Iterator_forward_list& b) { return a.m_ptr == b.m_ptr; };
	friend bool operator!= (const bz_Iterator_forward_list& a, const bz_Iterator_forward_list& b) { return a.m_ptr != b.m_ptr; };


	bz_Iterator_forward_list& operator +=(int i) {
		while (i >= 1) { this->m_ptr = this->m_ptr->Next; i--; } return *this;
	}
	bz_Iterator_forward_list& operator -=(int i) {
		while (i >= 1) { this->m_ptr = this->m_ptr->Prev; i--; } return *this;
	}





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


	//////////////////////CONSTRUCTORS////////////////////////
	bz_list();
	//bz_list(int _size);
	//bz_list(int _val, int _size);
	//bz_list(bz_list<T>& vec);

	~bz_list();
	///////////////////////ITERATORS//////////////////////////
	bz_Iterator_forward_list<Node<T>>begin();
	bz_Iterator_forward_list<Node<T>>end();

	////////////////////////MODIFIERS/////////////////////////
	void push_back(const T& val);
	void push_front(const T& val);
	void pop_front();
	void pop_back();
	iterator insert(bz_Iterator_forward_list<Node<T>>& iterator, const T& val);
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
	if (root == nullptr) {
		root = new Node<T>;
		root->val = val;
		this->size++;
		return;
	}


	Node<T>* t_root = (root);
	while (t_root->Next != nullptr) {
		t_root = t_root->Next;
	}
	(t_root)->Next = new Node<T>;
	(t_root)->Next->val = val;

	this->size++;
}

template<typename T>
bz_Iterator_forward_list<Node<T>> bz_list<T>::insert(bz_Iterator_forward_list<Node<T>>& iterator, const T& val) {

	int insert_pos = this->get_distance(this->begin().m_ptr, iterator.m_ptr);
	cout << this->size << endl;
	if (insert_pos > this->size)
		throw std::invalid_argument("position is exceeded the vector limit!");

	Node<T>* n_node = new Node<T>;
	n_node->val = val;
	n_node->Next = iterator.m_ptr;

	if (insert_pos >= 1) { (this->begin() + (insert_pos - 1))->Next = n_node; }
	else if (insert_pos == 0) { n_node->Next = root; root = n_node; }

	this->size++;

	return (this->begin() + insert_pos);
}


template<typename T>
 bz_Iterator_forward_list<Node<T>> bz_list<T>::begin() {
	return bz_Iterator_forward_list<Node<T>>(root);
}

template<typename T>
bz_Iterator_forward_list<Node<T>>bz_list<T>::end() {
	return bz_Iterator_forward_list<Node<T>>(tail);
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