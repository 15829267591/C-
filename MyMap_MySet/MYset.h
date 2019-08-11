#pragma once
#include <iostream>
using namespace std;
template <class K>
//class k, class k
class MySet {
	struct SetKeyofValue {
		const K& operator()(const K& k) {
			return k;
		}
	};
public:
	typedef typename RBTree<K, K, SetKeyofValue>::iterator iterator;

	pair<iterator, bool> Insert(const K& k)
	{
		return _t.Insert(k);
	}
	iterator begin()
	{
		return _t.Begin();
	}
	iterator end()
	{
		return _t.End();
	}
	iterator Find(const K&k)
	{
		return _t.Find(k);
	}
private:
	RBTree<K, K, SetKeyofValue> _t;
};

void TestSet()
{
	MySet<int> my1;
	my1.Insert(2);
	my1.Insert(1);
	my1.Insert(5);
	my1.Insert(4);
	my1.Insert(7);

	MySet<int>::iterator it = my1.begin();
	while (it != my1.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto& e : my1) {
		cout << e << " ";
	}
	cout << endl;
}