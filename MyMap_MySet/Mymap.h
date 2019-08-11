#pragma once
#include <string>
#include <iostream>
using namespace std;
template <class K, class V>
class MyMap {
	struct MapKeyOfValue {
		const K& operator()(const pair<K, V>& kv) {
			return kv.first;
		}
	};
public:
	typedef typename RBTree<K, pair<K, V>, MapKeyOfValue>::iterator iterator;
	typedef typename RBTree<K, pair<K, V>, MapKeyOfValue>::const_iterator const_iterator;
	pair<iterator, bool> Insert(const pair<K, V>& kv)
	{
		return _t.Insert(kv);
	}
	iterator begin()
	{
		return _t.Begin();
	}
	iterator end()
	{
		return _t.End();
	}

	//(*((this->insert(make_pair(k,mapped_type()))).first)).second
	V& operator[](const K& k)
	{
		return (*((_t.Insert(make_pair(k, V()))).first)).second;
	}
	iterator Find(const K&k)
	{
		return _t.Find(k);
	}
private:
	RBTree<K, pair<K, V>, MapKeyOfValue> _t;
};

void Testmymap()
{
	MyMap<string, string> map1;
	map1.Insert(make_pair("sort", "ÅÅÐò"));
	map1.Insert(make_pair("left", "×ó±ß"));
	map1.Insert(make_pair("right", "ÓÒ±ß"));
	map1.Insert(make_pair("flower", "»¨"));

	cout << map1["sort"] << endl;
	MyMap<string, string>::iterator it1 = map1.begin();
	while (it1 != map1.end()) {
		cout << it1->first << ":" << it1->second << " ";
		++it1;
	}
	cout << endl;
	map1["left"] = "ÁôÏÂ";
	 it1 = map1.begin();
	while (it1 != map1.end()) {
		cout << it1->first <<":" << it1->second << " ";
		++it1;
	}
	cout << endl;
	map1["troye"] = "´ÁÒ¯";
	it1 = map1.begin();
	while (it1 != map1.end()) {
		cout << it1->first << ":" << it1->second << " ";
		++it1;
	}
	cout << endl;
	it1 = map1.Find("left");
	if (it1 != map1.end()) {
		cout << "ÕÒµ½ÁË:"<<it1->second << endl;
	}

}