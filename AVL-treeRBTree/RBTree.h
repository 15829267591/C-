#pragma once
#include <iostream>
using namespace std;
enum Color{
	RED,
	BLACK
};
template<class T>
struct RBNode {

	RBNode<T>* _left;
	RBNode<T>* _right;
	RBNode<T>* _parent;
	T _data;
	Color _col;

	RBNode(const T& data , Color col)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_col(col)
	{}
};

template <class T>
class RBTree {
	typedef RBNode<T> Node;
public:
	bool Insert(const T& data)
	{
		if (_root == nullptr) {
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			if (cur->_data < data) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data > data) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(data);
		cur->_col = RED;
		if (parent->_data < data){
			parent->_right = cur;
			cur->_parent = parent;
		}
		else {
			parent->_left = cur;
			cur->_parent = parent;
		}
		//��ƽ��,���������
		while (parent && parent->_col==RED) {
			Node* gp = parent->_parent;
			if (parent == gp->_left) {
				Node* uncle = gp->_right;
				if (uncle && uncle->_col == RED) {
					parent->_col = BLACK;
					uncle->_col = BLACK;
					gp->_col = RED;
					cur = gp;
					parent = gp->_parent;
				}
				else {
					//��д���������
					if (parent->_right == cur) {
						RotateL(parent);
					}
					RotateR(gp);
					parent->_col = BLACK;
					gp->_col = RED;

					break;
				}
			}
			else {
				Node* uncle = gp->_left;
				if (uncle && uncle->_col == RED) {
					parent->_col = BLACK;
					uncle->_col = BLACK;
					gp->_col = RED;
					cur = gp;
					parent = gp->_parent;
				}
				else {
					if (parent->_left == cur) {
						RotateR(parent);
					}
					RotateL(gp);
					parent->_col = BLACK;
					gp->_col = RED;
					break;
				}
			}
		}
		
		_root->_col = BLACK;
		return true;
	}



	//�ҵ���
	void RotateR(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;
		if (ppNode == nullptr) {
			_root = subL;
			_root->_parent = nullptr;
		}
		else {
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;
			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}
	//����
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;
		if (ppNode == nullptr) {
			_root = subR;
			_root->_parent = nullptr;
		}
		else {
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
			subR->_parent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1) {
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else { subL->_bf = parent->_bf = 0; }
		subLR->_bf = 0;

	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);
		if (bf == 1) {
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1) {
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else {
			subR->_bf = parent->_bf = 0;
		}
		subRL->_bf = 0;
	}


	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount) {
		if (nullptr == pRoot)
			return true;
		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->_color) k++;
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		PNode pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		// ���pRoot�����ӽڵ㣬��⵱ǰ·���к�ɫ�ڵ�ĸ����Ƿ�������
		if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}
	Node& GetRoot()
	{
		return _root;
	}
private:
	Node* _root;
};


void TestRBTree()
{
	RBTree<int> rb_tree;

	Node* pCur = nullptr;
		// �����ڵ��Ƿ��������
		if (BLACK != rb_tree.GetRoot()._col)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
		}
	// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
	size_t blackCount = 0;
	Node* pCur = rb_tree.GetRoot();
	while (pCur)
	{
		if (BLACK == pCur->_color)
			blackCount++;
		pCur = pCur->_pLeft;
	}
	// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
	size_t k = 0;
	return _IsValidRBTree(pRoot, k, blackCount);
}
