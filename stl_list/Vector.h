#pragma once
#include <iostream>
#include <assert.h>
//原生态指针：所存储元素类型的指针 例如 vector 
//将原生态指针进行封装
template <class T>
struct ListNode {
	ListNode<T>* _pre;
	ListNode<T>* _next;
	T _data;

	 ListNode(const T& data = T())
		:_pre(nullptr)
		,_next(nullptr)
		,_data(data)
	{}
};

//迭代器
template <class T, class Ref, class Ptr>
struct __ListIterator {
	typedef ListNode<T> Node;
	typedef __ListIterator<T, Ref, Ptr> Self;
	Node* _node;

	__ListIterator(Node* node)
		:_node(node)
	{}
	Ref operator*()
	{
		return _node->_data;
	}
	//_node->->
	Ptr operator ->()
	{
		return &(_node->_data);
	}
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	//后置++
	Self operator++(int)
	{
		__ListIterator<T> tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	Self& operator--()
	{
		_node = _node->_pre;
		return *this;
	}
	Self operator--(int)
	{
		__ListIterator<T>tmp(*this);
		_node = _node->_pre;
		return tmp;
	}

	bool operator!=(const Self& it )
	{
		return _node != it._node;
	}

};

template <class T>
class List {
public:
	typedef ListNode<T>  Node;
	typedef __ListIterator<T, T&, T*> iterator;
	List()
		:_Head(new Node(T()))
	{
		_Head->_next = _Head;
		_Head->_pre = _Head;
	}
	~List()
	{
		Clear();
		delete _Head;
		_Head = nullptr;
	}
	void Clear()
	{
		Node* cur = _Head->_next;
		while (cur != _Head) {
			_Head->_next = cur->_next;
			delete cur;
			cur = _Head->_next;
		}
		_Head->_next = _Head;
		_Head->_pre = _Head;
	}
	List(const List<T>& l)
	{
		//创建头节点
		_Head = new Node;
		_Head->_next = _Head;
		_Head->_pre = _Head;
		//拷贝
		for (auto e : l) {
			pushBack(e);
		}
	}
	List<T>& operator =(const List<T> l)
	{
		swap(_Head, l._Head);
		return *this;
	}
	iterator begin()
	{
		//return _Head->_next;
		return _Head->_next;
	}
	iterator end()
	{
		return _Head;
	}
	//注：修改 const ListNode<T> & x  这是一个结点，这里需要的只是一个数据，创建的过程在函数里面实现
	void pushBack(const T& x)  
	{
		//Node* newNode = new Node(x);
		//Node* tail = _Head->_pre;
		//newNode->_pre = tail;
		//newNode->_next = _Head;
		//tail->_next = newNode;
		//_Head->_pre = newNode;
		Insert(end(), x);
	}
	void popBack()
	{
		Earse(--end()); 
	}
	void pushFront(const T&x)
	{
		Insert(begin(), x);
	}
	void popFront()
	{
		Earse(begin());
	}
	//Insert不会引起迭代器失效
	iterator Insert(iterator pos, const T& x)
	{
		Node* newNode = new Node(x);
		Node* cur = pos._node;
		newNode->_next = cur;
		cur->_pre->_next = newNode;
		newNode->_pre = cur->_pre;
		cur->_pre = newNode;
		return (iterator)newNode;
	}
	iterator Earse(iterator pos)
	{
		assert(pos != _Head);
		Node* cur = pos._node;
		Node* next = cur->_next;
		cur->_pre->_next = next;
		cur->_next->_pre = cur->_pre;
		delete cur;
		return (iterator)next;
	}
	bool Empty()
	{
		return _Head->_next == _Head->_pre;
	}
	size_t Size()
	{
		size_t count = 0;
		Node* cur = _Head->_next;
		while (cur != _Head) {
			++count;
			cur = cur->_next;
		}
		return count;
	}
private:
	Node* _Head;
};

void TestList1()
{
	List<int> l1;
	l1.pushBack(1);
	l1.pushBack(2);
	l1.pushBack(3);
	l1.pushBack(4);
	l1.pushBack(5);

	List<int> ::iterator it = l1.begin();
	while (it != l1.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	l1.Insert(l1.begin(), 20);
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	l1.Earse(l1.begin());
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	l1.pushFront(30);
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	l1.pushBack(40);
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	l1.popFront();
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	l1.popBack();
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;

	l1.Clear();
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
	std::cout << l1.Size() << std::endl;
}