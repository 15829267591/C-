#pragma once
#include <iostream>
//�ڵ�Ľṹ
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
	//����һ���ڵ�
	bool Insert(const T& x)
	{
		//�ж����Ƿ�Ϊ��
		if (_root == nullptr) {
			_root = new Node(x);
			return true;
		}
		//����Ϊ�գ�Ҫ�Һ��ʵ�λ�ò���,�Ӹ��ڵ㿪ʼƥ��
		Node* cur = _root;
		//Ҫ��¼ÿһ���ߵ�ǰһ��λ��
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
		//����Ԫ��
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
	//ɾ��һ���ڵ� ������ 
	//��һ�� ���ҵ�����ڵ��λ��
	//�ڶ�����ɾ��  ɾ���ַ�Ϊ������� 
	bool Erase(const T& x)
	{
		//���Ϊ������ֱ�ӷ���
		if (_root == nullptr)
			return false;
		//�����ҵ�Ҫɾ���Ľڵ�
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
				//�ҵ���
				//ִ�еڶ������ж����������
				//������Ϊ�յ����
				if (cur->_left == nullptr) {
					if (cur == parent->_right)
						parent->_right = cur->_right;
					else
						parent->_right = cur->_right;
				}
				//������Ϊ�յ����
				else if (cur->_right = nullptr) {
					if (cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
				//������������Ϊ��
				//����ֱ��ɾ������һ���ڵ�������������������������С
				else {
					Node* del = nullptr;
					Node* reParent = cur;
					Node* replace = cur->_right;
					while (replace->_left) {
						reParent = replace;
						replace = replace->_left;
					}
					//�ҵ���������С��Ԫ��
					//�����Ԫ��ֱ�Ӹ�ֵ��Ҫɾ����Ԫ��
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
	//�ݹ���ã��ṩ�ӿ�
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
