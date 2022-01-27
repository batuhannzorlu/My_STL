// my_stl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

#include "bz_vector.h"
#include "bz_uniqueptr.h"

using namespace std;

int main()
{

	{

		bz_vector<int> a;
		bz_vector<int>b;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);

		b.push_back(5);
		b.push_back(6);
		b.push_back(7);
		b.push_back(8);
		b.push_back(9);
		b.push_back(10);
	/*	cout << b.current_pos;*/
		b.swap(a);
		/*a[2] = 5;*/
		//a.push_back(5);
		//a.push_back(5);
		//a.push_back(5);
		//cout << a.size;
		//cout << a.current_pos;
		//a.push_back(6);
		/*cout << *(a.begin() + 1);*/
		/*a.pop_back();*/
		/*a.push_back(7);*/
		//cout << *it;
		//cout << *(it++);

		//bz_vector<int>::iterator it = a.begin();
		//for (; it != a.end(); it++)
		//{
		//	cout << *it;
		//}

		cout << "" << endl;

		/*	a.insert(a.begin() + 3, 7);*/
		bz_vector<int>::iterator it2 = b.begin();
		for (; it2 != b.end(); it2++)
		{
			cout << *it2;
		}

		bz_uniqueptr<int>r(1);
		*r = 12;
		cout << *r;

	}




	_CrtDumpMemoryLeaks();
}


