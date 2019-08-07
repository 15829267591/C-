#pragma once
#include <iostream>
//节点的结构
template <class T>
struct BSTreeNodePlus {
	BSTreeNodePlus<T>* _left;
	BSTreeNodePlus<T>* _right;
	T _data;

	BSTreeNodePlus(const T& data = T())
		:_data(data)
		,_left(nullptr)
		,_right(nullptr)
	{ }
};

template <class T>
class BSTreePlus {
	typedef BSTreeNodePlus<T> Node;
public:
	BSTreePlus()
		:_root(nullptr)
	{}
	//插入一个节点
	bool Insert(const T& x)
	{
		//判断树是否为空
		if (_root == nullptr) {
			_root = new Node(x);
			return true;
		}
		//树不为空，要找合适的位置插入,从根节点开始匹配
		Node* cur = _root;
		//要记录每一步走的前一个位置
		Node* parent = nullptr;
		while (cur) {
			parent = cur;
			if (cur->_data > x) {
				cur = cur->_left;
			}
			else if (cur->_data < x) {
				cur = cur->_right;
			}
			else {
				return false;
			}
		}
		cur = new Node(x);
		//插入元素
		if (parent->_data < x)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}
	bool Find(const T& x)
	{
		if (_root == nullptr)
			return false;
		Node* cur = _root;
		while (cur) {
			if (cur->_data > x)
				cur = cur->_left;
			else if (cur->_data < x)
				cur = cur->_right;
			else {
				return true;
			}
		}
		return false;
	}
	//删除一个节点 分两步 
	//第一步 ：找到这个节点的位置
	//第二步：删除  删除又分为三种情况 
	bool Erase(const T& x)
	{
		//如果为空树，直接返回
		if (_root == nullptr)
			return false;
		//首先找到要删除的节点
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {

			if (cur->_data > x) {
				parent = cur;
				cur = cur->_left;
			}

			else if (cur->_data < x) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				//找到了
				//执行第二步：判断是那种情况
				//左子树为空的情况
				if (cur->_left == nullptr) {
					if (cur == parent->_right)
						parent->_right = cur->_right;
					else
						parent->_right = cur->_right;
				}
				//右子树为空的情况
				else if (cur->_right = nullptr) {
					if (cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
				//左右子树都不为空
				//不能直接删除，找一个节点替代它，左子树最大，右子树最小
				else {
					Node* del = nullptr;
					Node* reParent = cur;
					Node* replace = cur->_right;
					while (replace->_left) {
						reParent = replace;
						replace = replace->_left;
					}
					//找到右子树最小的元素
					//将这个元素直接赋值给要删除的元素
					cur->_data = replace->_data;
					del = replace;
					if (reParent->_left == replace)
						reParent->_left = replace->_right;
					else
						reParent->_right = replace->_right;
				}
				break;
			}
			
		}
		return false;
	}
	//递归调用，提供接口
	void InOrder()
	{
		_InOrder(_root);
	}
	void _InOrder(Node* root)
	{
		if (root) {
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

private:


	Node* _root;
};

void TestBS2()
{
	BSTreePlus<int> tree;
	tree.Insert(1);
	tree.Insert(4);
	tree.Insert(3);
	tree.Insert(5);
	tree.Insert(7);
	tree.Insert(9);
	tree.Insert(1);
	tree.InOrder();
	cout << endl;
	cout << tree.Find(4) << endl;
	cout << tree.Find(0) << endl;
	tree.Erase(7);
	tree.InOrder();
}
