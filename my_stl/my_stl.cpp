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



bool predicate_func(int i,int z) {
	if (i == 5)
		return true;
	return false;
}

int main()
{





	
	{

		bz_map<int, int> mmap;
		mmap.insert(std::make_pair(1, 1));
		mmap.insert(std::make_pair(2, 2));
		mmap.insert(std::make_pair(3, 3));
		mmap.insert(std::make_pair(4, 4));
		mmap.erase(4);
		//mmap.erase(mmap.begin(), mmap.begin() + 2);
		for (bz_map<int, int>::iterator it = mmap.begin(); it != mmap.end(); it++) {
			std::cout << it->first<<" " << it->second<<std::endl;
			
		}

		

		_CrtDumpMemoryLeaks();
		system("pause");
	}




	
}


