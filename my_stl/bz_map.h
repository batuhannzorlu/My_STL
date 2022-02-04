#pragma once

#include <iostream>
#include <algorithm>
#include "bz_Iterator_forward.h"
#include "bz_vector.h"
#include "bz_uniqueptr.h"
template<typename KEY, typename VALUE>
class bz_map {

private:
	/*private_map has changed to pointer due to overloaded contructors!*/
	bz_vector<pair<KEY, VALUE>>* private_map;

public:
	typedef bz_Iterator_forward<pair<KEY, VALUE>> iterator;

	//////////////////////CONSTRUCTORS////////////////////////

	/*Constructs an empty container, with no elements.*/
	bz_map();
	/*Constructs a container with a copy of each of the elements in x.*/
	bz_map( bz_map<KEY, VALUE>& map);

	//////////////////////DESTRUCTOR////////////////////////
	~bz_map();


	//////////////////////CAPACITY//////////////////////////
	bool empty();

	///////////////////////ITERATORS//////////////////////////
	iterator begin();
	iterator end();
	


	////////////////////////MODIFIERS/////////////////////////
	bz_Iterator_forward<pair<KEY, VALUE>> insert(const pair<KEY, VALUE>& _p);
	void erase(const KEY& _p);
	void erase(bz_Iterator_forward<pair<KEY, VALUE>>&  position);
	void erase(bz_Iterator_forward<pair<KEY, VALUE>>&  first, bz_Iterator_forward<pair<KEY, VALUE>>&  last);
	void swap(bz_vector<pair<KEY, VALUE>>& map);


	///////////////////ELEMENT-ACCESS///////////////////////
	VALUE& operator [](const KEY& k) { 
		bz_Iterator_forward<pair<KEY, VALUE>> it = std::find_if(private_map->begin(), private_map->end(), [k](const pair<KEY, VALUE>& lhs) { return lhs.first == k; });
		return it->second;
	}

};


template<typename KEY, typename VALUE>
bz_map<KEY, VALUE>::bz_map() {
	private_map = new bz_vector<pair<KEY, VALUE>>();
}
template<typename KEY, typename VALUE>
bz_map<KEY, VALUE>::bz_map( bz_map<KEY, VALUE>& map) {
	private_map = new bz_vector<pair<KEY, VALUE>>(*(map.private_map));
}

template<typename KEY, typename VALUE>
bz_map<KEY, VALUE>::~bz_map() {
	delete this->private_map;
}


template<typename KEY, typename VALUE>
bz_Iterator_forward<pair<KEY, VALUE>> bz_map<KEY, VALUE>::begin() {
	/*return (&private_map[0]);*/
	/*Because private_map has changed to pointer!*/
	return (&((*private_map)[0]));
}


template<typename KEY, typename VALUE>
bz_Iterator_forward<pair<KEY, VALUE>> bz_map<KEY, VALUE>::end() {
	//return (&private_map[private_map.current_pos]);
	/*Because private_map has changed to pointer!*/
	return (&((*private_map)[private_map->current_pos]));
}

template<typename KEY, typename VALUE>
bool bz_map<KEY, VALUE>::empty() {

	return private_map->empty();
}

template<typename KEY, typename VALUE>
bz_Iterator_forward<pair<KEY, VALUE>> bz_map<KEY, VALUE>::insert(const pair<KEY, VALUE>& _p) {

	iterator it = NULL;
	if (std::find(private_map->begin(), private_map->end(), _p) == private_map->end()) {
		it = std::lower_bound(private_map->begin(), private_map->end(), _p, [](const pair<KEY, VALUE>& lhs, const pair<KEY, VALUE>& rhs) { return lhs.first < rhs.first; });
		private_map->insert(it, _p);
	}

	return it;
}

template<typename KEY, typename VALUE>
void bz_map<KEY, VALUE>::erase(const KEY& _p) {

	bz_Iterator_forward<pair<KEY, VALUE>> it = std::find_if(private_map->begin(), private_map->end(), [_p](const pair<KEY, VALUE>& lhs) { return lhs.first==_p; });
	private_map->erase(it);

}
template<typename KEY, typename VALUE>
void bz_map<KEY, VALUE>::erase(bz_Iterator_forward<pair<KEY, VALUE>>& position) {this->private_map->erase(position);}

template<typename KEY, typename VALUE>
void bz_map<KEY, VALUE>::erase(bz_Iterator_forward<pair<KEY, VALUE>>&  first, bz_Iterator_forward<pair<KEY, VALUE>>&  last) {

}

template<typename KEY, typename VALUE>
void bz_map<KEY, VALUE>::swap(bz_vector<pair<KEY, VALUE>>& map) {this->private_map->swap(map);}


