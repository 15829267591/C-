#pragma once

template <class T>
struct AVLTreeNode{
	AVLTreeNode(const T& data)
		:_data(data)
		,_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}

	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	T _data;
	int _bf;
};

template <class T>
class AVLTree {
	typedef AVLTreeNode<T> Node;
public:
	bool Insert(const T& data)
	{
		if (_root == nullptr) {
			_root = new Node(data);
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
		if (parent->_data < data) {
			parent->_right = cur;
			cur->_parent = parent;
		}
		else {
			parent->_left = cur;
			cur->_parent = parent;
		}
		//调平衡
		//1、调节平衡因子  2、旋转
		while (parent) {
			//调节父节点的平衡因子
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;
			//如果为0，说明原本的平衡因子为1或-1，可以理解为加的这个节点
			//刚好把空缺补上了，树整体的高度没有变化，所以到此为止，不需要
			//再向上调节
			if (parent->_bf == 0) {
				break;
			}
			// 如果父节点的平衡因子为1或者-1说明高度已经，发生变化，所以我们要继续向上调节
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else {
				if (parent->_bf == 2) {
					if (cur->_bf == 1)
						RotateL(parent);
					else
						RotateRL(parent);
				}
				else {
					if (cur->_bf == -1) 
						RotateR(parent);
					else
						RotateLR(parent);
				}
				break;
			}
		}
		return true;
	}
	//右单旋
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
	//左单旋
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
		{ subL->_bf = -1;		
		parent->_bf = 0; }
		else if (bf == -1) { subL->_bf = 0;		
		parent->_bf = 1; }
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

	void InOrder()
	{
		_InOrder(_root);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		if (root) {
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	int _Height(Node* pRoot)
	{
		if (nullptr == pRoot)
			return 0;
		// 计算pRoot左右子树的高度
		int leftHeight = _Height(pRoot->_left);
		int rightHeight = _Height(pRoot->_right);
		// 返回左右子树中较高的子树高度+1
		return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
	}
	bool IsBalanceTree()
	{
		return  _IsBalanceTree(_root);
	}
	bool _IsBalanceTree(Node* root) {
		if (root == NULL) {
			return true; 
		}		
		int bf = _Height(root->_right) - _Height(root->_left);
		if (abs(bf) > 1 || bf != root->_bf) { cout << "平衡因子有问题：" << root->_data<< endl;
		return false; 
		}		
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);

	}
private:
	Node* _root = nullptr;
};


void TestAVL()
{
	//AVLTree < int> t;
	//int size[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14};
	//for (const auto e : size) {
	//	t.Insert(e);
	//}

	//t.InOrder();

	int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int> alt1;	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); ++i)
	{ 
		alt1.Insert(arr1[i]); 
	}	
	alt1.InOrder();
	cout << "isBlance? " << alt1.IsBalanceTree() << endl;
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };	
	AVLTree<int> alt2;	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{ 
		alt2.Insert(arr[i]);
	}	
	alt2.InOrder();
	cout << "isBlance? " << alt2.IsBalanceTree() << endl;
}

	
