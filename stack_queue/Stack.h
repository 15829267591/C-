#pragma once
#include <stack>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
void test1()
{
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.emplace(6);
	std::cout << s.size() << std::endl;
	std::stack<int> s2;
	s2.swap(s);
	std::cout << s.size() << std::endl;
	std::cout << s2.size() << std::endl;
	//不支持迭代器
	while (!(s.empty())) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
	while (!(s2.empty())) {
		std::cout << s2.top() << " ";
		s2.pop();
	}
}

template<class T, class Contain = std::deque<T>>
class Stack{
public:
	Stack() {};
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_back();
	}
	bool Empty()
	{
		return _con.empty();
	}
	T& Top()
	{
		return _con.back();
	}
	const T& Top() const
	{
		return _con.back();
	}
	size_t Size()
	{
		return _con.size();
	}
private:
	Contain _con;
};

void TestStack()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	std::cout<< s1.Size();
	while (!(s1.Empty())) {
		std::cout << s1.Top() << " ";
		s1.Pop();
	}
	std::cout << std::endl;
}