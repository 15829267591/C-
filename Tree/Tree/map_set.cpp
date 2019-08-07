#include "BSTree.h"
#include "BSTree2.h"
#include <iostream>
using namespace std;
void test()
{
	BSTree<int, int> bs;
	bs.Insert(make_pair(1, 2));
	bs.Insert(make_pair(9, 2));
	bs.Insert(make_pair(5, 2));
	bs.Insert(make_pair(7, 2));
	bs.Insert(make_pair(6, 2));
	bs.InOrder();
	cout << endl;
	bool p = bs.find(4);
	cout << p << endl;
	bs.Earse(6);
	bs.InOrder();

}
int main()
{
	//test();
	TestBS2();
	getchar();
	return 0;
}
