#pragma once
#include <iostream>
using namespace std;
#include <queue>
void test3()
{
	std::priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(6);
	std::cout << pq.size() << std::endl;
	pq.pop();
	std::cout << pq.size() << std::endl;
	while (!pq.empty()) {
		std::cout << pq.top() << ' ';
		pq.pop();
	}
	std::cout << std::endl;
}
//template <class T>
//class Less
//{
//	bool operator()(const T& l, const T& r)
//	{
//		return l < r;
//	}
//};
//template <class T>
//class Greater
//{
//	bool operator()(const T& l, const T& r)
//	{
//		return l > r;
//	}
//};

template <class T, class Contain = vector<T>>
class PriorityQueue {
public:
	//建大堆(升序）
	void AdjustUp(size_t child)
	{
		size_t parent = (child - 1) / 2;
		while (child > 0) {
			if (_con[child] < _con[parent]) {
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else {
				break;
			}
		}
	}

	void AdjustDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		while (child <_con.size()) {
			if (child+1<_con.size() && _con[child + 1] <_con[child]) {
				++child;
			}
			if (_con[parent] > _con[child]) {
				swap(_con[child], _con[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else {
				break;
			}

		}
	}
	void Push(const T& x)
	{
		//插入
		_con.push_back(x);
		//调整
		AdjustUp( _con.size() - 1);

	}
	void Pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		AdjustDown(0);
	}
	const T& Top()
	{
		return _con[0];
	}
	bool Empty()
	{
		return _con.empty();
	}
	size_t Size()
	{
		return _con.size();
	}
private:
	Contain _con;
};

void TestPriorityQueue()
{
	PriorityQueue<int> p;
	//p.Push(3);
	//p.Push(4);
	//p.Push(1);
	//p.Push(9);
	//p.Push(7);
	//p.Push(6);
	p.Push(1);
	p.Push(6);
	p.Push(1);
	p.Push(8);
	p.Push(0);

	while (!p.Empty()) {
		cout << p.Top() << ' ';
		p.Pop();
	}
	cout << endl;
}
