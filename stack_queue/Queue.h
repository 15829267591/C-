#pragma once
#include <queue>
#include <iostream>
#include <list>
#include <deque>
void test2()
{
	std::queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	q1.emplace(6);
	std::cout << q1.size() << std::endl;
	while (!(q1.empty())) {
		std::cout << q1.front() << " ";
		q1.pop();
	}
	std::cout << std::endl;
}
template<class T,class Contain =std::deque<T>>
class Queue {
public:
	Queue(){}
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_front();
	}
	size_t Size()
	{
		return _con.size();
	}
	bool Empty()
	{
		return _con.empty();
	}
	T& Front()
	{
		return _con.front();
	}
	const T& Front()const
	{
		return _con.front();
	}
	T& Back()
	{
		return _con.back();
	}
	const T& Back()const
	{
		return _con.back();
	}
private:
	Contain _con;
};
 
void TestQueue()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Push(6);
	std::cout << q.Size() << std::endl;
	q.Pop();
	std::cout << q.Size() << std::endl;
	while (!(q.Empty())) {
		std::cout << q.Front() << " ";
		q.Pop();
	}
	std::cout << std::endl;
}
