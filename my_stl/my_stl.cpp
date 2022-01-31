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

#include "bz_vector.h"
#include "bz_uniqueptr.h"
#include "bz_sharedptr.h"
#include "bz_map.h"

using namespace std;

int main()
{
	//{
	//	

	//}
	//


	//map<int, char> mc;
	//mc[0] = 'q';
	//cout << mc[0];
	{
		bz_map<int, char> i_c;
		i_c.insert(pair<int,char>(0, 'c'));
		i_c.insert(pair<int, char>(1, 'w'));
		i_c.insert(pair<int, char>(2, 'e'));
		//i_c[1] = 'q';
		bz_map<int, char> i_c2(i_c);
		cout<<(i_c2.begin()+1)->second;
		/*bz_vector<int>a;
		bz_vector<int>b;

		b.push_back(7);
		b.push_back(8);
		b.push_back(9);



		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		a.push_back(5);

		a.insert(a.begin() + 2, b.begin(), b.end());
		bz_vector<int>c(a);

		for (bz_vector<int>::iterator i = c.begin(); i != c.end(); i++)
		{
			cout << *i;
		}*/
	}
	
	//bz_vector<int> a;
	//a.push_back(1);
	//a.push_back(2);
	//a.push_back(3);
	//a.push_back(4);
	//a.erase(a.begin(), (a.begin() + 3));
	//cout<<a.front()<<endl;
	/*std::sort(a.begin(), a.end());*/
	//map<int, char> ic;
	//ic[1] = 'c';
	//map<int, char>::iterator it = ic.begin();

	//for (size_t i = 0; i < 10; i++)
	//{
	//	ic[i] = i + 97;
	//}


	///*for (size_t i = 0; i < 10; i++)
	//{
	//	cout << ic[i];
	//}*/
	//for (; it != ic.end(); it++)
	//{
	//	cout << it->second;
	//}

	/*bz_map<int, char>x ;
	bz_map<int, char>::iterator it;

	x.insert(pair<int, char>(9, 'a'));
	x.insert(pair<int,char>(7, 'b'));
	x.insert(pair<int, char>(3, 'q'));
	cout << x[7] << endl;*/



	//bz_map<char,int>x;
	//x.insert(pair<int, char>('a',6 ));
	//x.insert(pair<int, char>('q', 7));
	//x.insert(pair<int, char>('c', 4));
	//cout << x['q']++;

	//x.erase(x.begin(),x.begin()+1);
	//cout<<x.begin()->second << endl;
	//cout << (x.begin()+1)->second << endl;
	//cout << (x.begin() + 2)->second << endl;
	
	//int.insert(pair<int, char>(3, 'd'));
	//int.insert(pair<int, char>(2, 'q'));


	//shared_ptr<int>s(new int);
	//shared_ptr<int>s1;
	//s1 = s;
	//cout << s.use_count() << endl;

	{

		/*shared_ptr<int>s(new int[1]);
		shared_ptr<int>s1(new int[3]);
		shared_ptr<int>s3(s);
		s1 = s;
		cout << s.use_count() << endl;*/
		//bz_sharedptr<int>q(1);
		//cout << q.use_count() << endl;
		//bz_sharedptr<int>b(q);
		////cout << q.use_count() << endl;
		//bz_sharedptr<int>c;
		//c = q;
		//cout << q.use_count() << endl;

		/*shared_ptr<int> int(new int);*/
		
	/*	bz_vector<int> a;
		bz_vector<int>b;

		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		a.push_back(5);

		a.erase(a.begin());*/


		//cout << a.size << endl;
		//a.shrink_to_fit();
		//cout << a.size<<endl;

		//bz_vector<int>::iterator it2 = a.begin();
		//for (; it2 != a.end(); it2++)
		//{
		//	cout << *it2;
		//}

		//b.push_back(5);
		//b.push_back(6);
		//b.push_back(7);
		//b.push_back(8);
		//b.push_back(9);
		//b.push_back(10);
		///*	cout << b.current_pos;*/
		//b.swap(a);
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

	/*	cout << "" << endl;*/

			/*a.insert(a.begin() + 3, 7);*/
		//bz_vector<int>::iterator it2 = b.begin();
		//for (; it2 != b.end(); it2++)
		//{
		//	cout << *it2;
		//}

		/*bz_uniqueptr<int>r(1);*/

		//*r = 12;
		/*	cout << *r;*/


	/*	bz_sharedptr<int>int(1);
		bz_sharedptr<int>y(1);
		*int = 5;
		*y = 8;*/
	/*	cout << int.get() << endl;
		cout << y.get() << endl;
		int.swap(y);
		cout << int.get();*/


	///*	shared_ptr<int> qs(new int);
	//	qs.reset();*/

	}




	_CrtDumpMemoryLeaks();
}


