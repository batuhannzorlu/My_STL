// my_stl.cpp : This file contains the 'main' function. Program eintecution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>
#include <list>
#include <set>

#include "bz_vector.h"
#include "bz_uniqueptr.h"
#include "bz_sharedptr.h"
#include "bz_map.h"
#include "bz_list.h"
#include "bz_stack.h"
#include "algorithm.h"



bool predicate_func(int i,int z) {
	if (i == 5)
		return true;
	return false;
}

int main()
{



	vector<int> v = { 9,7,8,6,4,5,3,1,2 };
	std::partial_sort(v.begin(), v.begin()+3, v.end());
//	for_each(v.begin(), v.end(), [](int i) {cout << i << " "; });

	set<int,less<int>> myset;
	myset.insert(5);
	myset.insert(7);
	myset.insert(9);
	myset.insert(10);
	myset.insert(10);

	for_each(myset.begin(), myset.end(), [](int i) {std::cout << i << " "; });
	//list<int> mylist;
	//mylist.push_back(1); mylist.push_back(2); mylist.push_back(3); mylist.push_back(4);

	//for_each(mylist.begin(), mylist.end(), [](int i) {std::cout << i; });
	{
		bz_vector<int> myv;
		//myv.push_back(1); myv.push_back(2); myv.push_back(3); myv.push_back(4); myv.push_back(5); 
	//	std::cout << bz_std::bz_binary_search(myv.begin(), myv.end(),4);
	//	bz_std::bz_adjacent_find(myv.begin(), myv.end());
	//	bz_std::bz_adjacent_find(myv.begin(), myv.end(), [](int i, int j) { return i % 2 == 0 && j % 2 == 0; });
		

		//bz_std::bz_find_if(mylist.begin(), mylist.end(), [](Node<int> i) { return i.val == 4; });

		//for_each(myv.begin(), myv.end(), [](int i) { std::cout << i<<" "; });
		
	//	std::cout<<*bz_std::bz_find_if(myv.begin(), myv.end(), [](int i) { return i == 4; });

	}





	_CrtDumpMemoryLeaks();
	system("pause");
}


