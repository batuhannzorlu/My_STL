#pragma once

#include "bz_Iterator_forward.h"

namespace bz_std {



	/*################  NON MODIFIYNG SEQUENCE OPERATIONS  #############################*/

	template<typename T>
	bz_Iterator_forward<T> bz_find(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last, const T  value) {


		for (; first != last; first++) {
			if (*(first)==value)
				return first;
		}
		return last;


	}

	template<typename T, typename Func>
	bz_Iterator_forward<T> bz_find_if(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last, Func& predicate) {


		for (; first != last; first++) {
			if (predicate(*(first)))
				return first;
		}
		return last;


	}

	template<typename T, typename Func>
	bz_Iterator_forward<T> bz_find_if_not(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last, Func& predicate) {


		for (; first != last; first++) {
			if (!predicate(*(first)))
				return first;
		}
		return last;


	}

	template<typename T>
	bz_Iterator_forward<T> bz_adjacent_find(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last) {

		if (first == last)
			return last;

		bz_Iterator_forward<T> next = first;
		next++;
		while (next != last) {
			if (*first == *next)
				return first;
			next++;
			first++;
		}
		return last;
	}

	template<typename T, typename Func>
	bz_Iterator_forward<T> bz_adjacent_find(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last,Func& predicate) {

		if (first == last)
			return last;

		bz_Iterator_forward<T> next = first;
		next++;
		while (next != last) {
			if (predicate(*first,*next))
				return first;
			next++;
			first++;
		}
		return last;


	}

	template<typename T, typename Func>
	bool bz_all_of(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last, Func& predicate) {


		for (; first != last; first++) {
			if (!predicate(*(first)))
				return false;
		}
		return true;


	}

	template<typename T, typename Func>
	bool bz_none_of(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last, Func& predicate) {


		for (; first != last; first++) {
			if (predicate(*(first)))
				return false;
		}
		return true;


	}
	
	template<typename T, typename Func>
	bool bz_any_of(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last, Func& predicate) {


		for (; first != last; first++) {
			if (predicate(*(first)))
				return true;
		}
		return false;


	}

	template<typename T, typename Func>
	int bz_count(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last, const T& value) {

		int counter(0);
		for (; first != last; first++) {
			if ((*(first)) == value)
				counter++;
		}
		return counter;


	}

	template<typename T, typename Func>
	int bz_count_if(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last, Func& predicate) {

		int counter(0);
		for (; first != last; first++) {
			if (predicate(*(first)))
				counter++;
		}
		return counter;


	}

	/*The behavior is undefined if the second range is shorter than the first range.*/
	template<typename T, typename Func>
	pair<bz_Iterator_forward<T>, bz_Iterator_forward<T>> bz_mismatch(bz_Iterator_forward<T>& first1, bz_Iterator_forward<T>& last1,
		bz_Iterator_forward<T>& first2, bz_Iterator_forward<T>& last2, Func& predicate) {
		while (first1 != last1 && *first1 != *first2)
		{
			first1++; first2++;
		}
		if (first1 != last1)
			throw std::length_error("Second Range is bigger than first one!");

		return std::make_pair(first1, first2);


	}

	/*Array must be sorted!*/
	template<typename T>
	bool bz_binary_search(bz_Iterator_forward<T>& first, bz_Iterator_forward<T>& last,const T & val) {

		int start(0);
		int end(std::distance(first, last)+1);

		while (start <= end) {
			
			int mid = (end - start) / 2 + start;

			if (*(first + mid) == val)return true;
			if (*(first + mid) < val) start = mid + 1;
			if (*(first + mid) > val) end = mid - 1;	
		}

		return false;
	}

}
