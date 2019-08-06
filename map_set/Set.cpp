#include <iostream>
#include <set>
#include<algorithm>
using namespace std;
void testSet()
{
	set<int, greater<int>, allocator<int>> s1;
	s1.insert(3);
	s1.insert(2);
	s1.insert(8);
	s1.insert(5);
	s1.insert(4);
	s1.insert(0);

	for (auto &e : s1) {
		cout << e << " ";
	}
	cout << endl;
	set<int>::iterator it = find(s1.begin(), s1.end(), 9);
	if (it != s1.end())
		s1.erase(it);
	for (auto &e : s1) {
		cout << e << " ";
	}
	cout << endl;
	s1.erase(0);
	for (auto &e : s1) {
		cout << e << " ";
	}
	cout << endl;
	size_t a= s1.erase(7);
	cout << a << endl;
	for (auto &e : s1) {
		cout << e << " ";
	}
	cout << endl;
}
//multiset()

void testMultiset()
{
	multiset<int> m1;

	m1.insert(4);
	m1.insert(1);
	m1.insert(4);
	m1.insert(7);
	m1.insert(2);
	m1.insert(6);
	m1.insert(1);
	m1.insert(0);

	set<int>::iterator it = m1.begin();
	while (it!=m1.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto& e : m1) {
		cout << e  << " ";
	}
	cout << endl;
}
//
//int main()
//{
//	testSet();
//	//testMultiset();
//	getchar();
//	return 0;
//}