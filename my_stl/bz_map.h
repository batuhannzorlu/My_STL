#pragma once

#include <iostream>
#include <algorithm>
#include "bz_Iterator_forward.h"
#include "bz_vector.h"

template<typename KEY, typename VALUE>
class bz_map {

private:

	bz_vector<pair<KEY, VALUE>> private_map;
	int size = 2;
	pair<KEY, VALUE> _pair;
public:
	KEY first;
	VALUE second;
	/*typedef bz_Iterator_forward<bz_vector<pair<KEY, VALUE>>> iterator;*/
	typedef bz_Iterator_forward<pair<KEY, VALUE>> iterator;

	bz_map();
	~bz_map();
	bool IsGreater(pair<KEY, VALUE>p1, pair<KEY, VALUE>p2);
	iterator begin();
	iterator end();
	bool empty();

	bz_Iterator_forward<pair<KEY, VALUE>> insert(const pair<KEY, VALUE>& _p);

	void erase(const KEY& _p);
	void erase(bz_Iterator_forward<pair<KEY, VALUE>>  position);
	void erase(bz_Iterator_forward<pair<KEY, VALUE>>  first, bz_Iterator_forward<pair<KEY, VALUE>>  last);


};


template<typename KEY, typename VALUE>
bz_map<KEY, VALUE>::bz_map() {

}

template<typename KEY, typename VALUE>
bz_map<KEY, VALUE>::~bz_map() {

}


template<typename KEY, typename VALUE>
bz_Iterator_forward<pair<KEY, VALUE>> bz_map<KEY, VALUE>::begin() {
	return (&private_map[0]);
}


template<typename KEY, typename VALUE>
bz_Iterator_forward<pair<KEY, VALUE>> bz_map<KEY, VALUE>::end() {
	return (&private_map[private_map.current_pos]);
}

template<typename KEY, typename VALUE>
bool bz_map<KEY, VALUE>::empty() {

	return private_map.empty();
}

template<typename KEY, typename VALUE>
bz_Iterator_forward<pair<KEY, VALUE>> bz_map<KEY, VALUE>::insert(const pair<KEY, VALUE>& _p) {

	iterator it = NULL;
	if (std::find(private_map.begin(), private_map.end(), _p) == private_map.end()) {
		it = std::lower_bound(private_map.begin(), private_map.end(), _p, [](const pair<KEY, VALUE>& lhs, const pair<KEY, VALUE>& rhs) { return lhs.first < rhs.first; });
		private_map.insert(it, _p);
	}

	return it;
}

template<typename KEY, typename VALUE>
void bz_map<KEY, VALUE>::erase(const KEY& _p) {

	bz_Iterator_forward<pair<KEY, VALUE>> it = std::find_if(private_map.begin(), private_map.end(), [_p](const pair<KEY, VALUE>& lhs) { return lhs.first==_p; });
	private_map.erase(it);

}
template<typename KEY, typename VALUE>
void bz_map<KEY, VALUE>::erase(bz_Iterator_forward<pair<KEY, VALUE>> position) {
	private_map.erase(position);

}

template<typename KEY, typename VALUE>
void erase(bz_Iterator_forward<pair<KEY, VALUE>>  first, bz_Iterator_forward<pair<KEY, VALUE>>  last) {

}


template<typename KEY, typename VALUE>
bool bz_map<KEY, VALUE>::IsGreater(pair<KEY, VALUE>p1, pair<KEY, VALUE>p2) {

	return p1.first > p2.first;
}

