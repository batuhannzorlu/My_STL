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
#include "bz_algorithm.h"
#include "bz_iterator_forward.h"


bool predicate_func(int i,int z) {
	if (i == 5)
		return true;
	return false;
}

int main()
{
	int a(1);
	std::cout <<(++a)--;
	
	/*bz_vector<int> myv;
	myv.push_back(2); myv.push_back(3); myv.push_back(4); myv.push_back(5); myv.push_back(6); myv.push_back(7);

	for (bz_vector<int>::reverse_iterator rit = myv.rbegin();rit != myv.rend(); rit++) {
		std::cout << *rit<<std::endl;
	}
	std::cout << endl;
	for (bz_vector<int>::iterator rit = myv.begin(); rit != myv.end(); rit ++) {
		std::cout << *rit << std::endl;
	}*/




	
	{





		//bz_map<int, int> mmap;
		//mmap.insert(std::make_pair(1, 1));
		//mmap.insert(std::make_pair(2, 2));
		//mmap.insert(std::make_pair(3, 3));
		//mmap.insert(std::make_pair(4, 4));
		//mmap.erase(4);




		////mmap.erase(mmap.begin(), mmap.begin() + 2);
		//for (bz_map<int, int>::iterator it = mmap.begin(); it != mmap.end(); it++) {
		//	std::cout << it->first<<" " << it->second<<std::endl;
		//	
		//}

		

		_CrtDumpMemoryLeaks();
		system("pause");
	}




	
}


