#pragma once
#include <iostream>
using namespace std;

template <class K, class V>
struct BSTreeNode {
	pair<K, V>_kv;
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	BSTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V>
class BSTree {
	typedef BSTreeNode<K, V> Node;
public:

	BSTree()
		:_root(nullptr)
	{}
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			parent = cur;
			if (cur->_kv.first < kv.first) {
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) {
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
			parent->_right = cur;
		else
			parent->_left = cur;

		return true;
	}
	bool find(const K& key)
	{
		if (_root == nullptr) {
			return false;
		 }
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first > key)
				cur = cur->_left;
			else if (cur->_kv.first < key)
				cur = cur->_right;
			else
				return  true;
		}
		return  false;
	}
	bool Earse(const K& key)
	{
		if (_root == nullptr)
			return false;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			if (cur->_kv.first > key){
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < key) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				Node* del = cur;
				if (cur->_left = nullptr) {
					if (parent == nullptr) {
						_root = cur->_right;
					}
					else {
						if (cur == parent->_left)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}

				}
				else if (cur->_right == nullptr) {
					if (parent == nullptr) {
						_root = cur->_left;
					}
					else {
						if (cur == parent->_left)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}

				}
				//左右子树都不为空的情况
				else {
					Node* rParent = cur;
					Node* replace = cur->_right;
					//找右子树中最小的节点
					while (replace->_left) {
						rParent = replace;
						replace = replace->_left;
					}
					//把代替节点赋值给要（原）删除的节点
					cur->_kv = replace->_kv;
					del = replace;
					if (rParent->_left == del)
						rParent->_left = del->_right;
					else
						rParent->_right = del->_right;
				}
				break;
			}


		}
		return false;
	}
	void InOrder()
	{
		_InOrder(_root);
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}
	}
private:
	Node* _root;
};

