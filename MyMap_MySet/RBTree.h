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

	RBNode(const T& data = T())
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_col(RED)
	{}
};
template <class T, class Ref, class Ptr>
struct __RBTreeIterator {
	typedef RBNode<T> Node;
	typedef __RBTreeIterator<T, Ref, Ptr> Self;
	__RBTreeIterator(Node* node)
		:_node(node)
	{}
	T& operator*()
	{
		return _node->_data;
	}
	T* operator->()
	{
		return &(_node->_data);
	}
	bool operator !=(const Self& s)
	{
		return _node != s._node;
	}

	Self operator++()
	{
		if (_node->_right != nullptr) {
			_node = _node->_right;
			while (_node->_left)
				_node = _node->_left;
		}
		else {
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right) {
				cur = parent;
				parent = parent->_parent;
			}
			//cur 是parent的左节点
			_node = parent;
		}
		return *this;//

		Node* _node;
	};

	template <class K, class T, class KeyOfValue>
	class RBTree {
		typedef RBNode<T> Node;
	public:
		typedef __RBTreeIterator<T, T*, T&> iterator;
		typedef __RBTreeIterator<const T, const T*, const T&> const_iterator;
		RBTree() = default;
		//拷贝构造 、析构、赋值

		iterator Begin()
		{
			Node* cur = _root;
			while (cur->_left) {
				cur = cur->_left;
			}
			return (iterator)cur;
		}
		iterator End()
		{
			return (iterator)nullptr;
		}

		pair<iterator, bool> Insert(const T& data)
		{
			if (_root == nullptr) {
				_root = new Node(data);
				_root->_col = BLACK;
				return make_pair((iterator)_root, true);
			}
			KeyOfValue kov;
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur) {
				if (kov(cur->_data) < kov(data)) {
					parent = cur;
					cur = cur->_right;
				}
				else if (kov(cur->_data) > kov(data)) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					return make_pair(iterator(cur), false);
				}
			}
			cur = new Node(data);
			cur->_col = RED;
			if (kov(parent->_data) < kov(data)) {
				parent->_right = cur;
				cur->_parent = parent;
			}
			else {
				parent->_left = cur;
				cur->_parent = parent;
			}
			//调平衡,分情况讨论
			while (parent && parent->_col == RED) {
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
						//先写第三种情况
						if (parent->_right == cur) {
							RotateL(parent);
							swap(parent, cur);
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
							swap(parent, cur);
						}
						RotateL(gp);
						parent->_col = BLACK;
						gp->_col = RED;
						break;
					}
				}
			}

			_root->_col = BLACK;
			return make_pair(iterator(cur), true);
		}


		iterator Find(const K& k)
		{
			KeyOfValue kov;
			Node* cur = _root;
			while (cur) {
				if (kov(cur->_data) > k)
					cur = cur->_left;
				else if (kov(cur->_data) < k)
					cur = cur->_right;
				else
					return (iterator)cur;
			}
			return (iterator)nullptr;
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

		bool IsValidRBTree()
		{
			Node* pRoot = _root;
			// 空树也是红黑树
			if (nullptr == pRoot)
				return true;

			// 检测根节点是否满足情况
			if (BLACK != pRoot->_col)
			{
				cout << "违反红黑树性质二：根节点必须为黑色" << endl;
				return false;
			}
			// 获取任意一条路径中黑色节点的个数
			size_t blackCount = 0;
			Node* pCur = pRoot;
			while (pCur)
			{
				if (BLACK == pCur->_col)
					blackCount++;
				pCur = pCur->_left;
			}
			// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
			size_t k = 0;
			return _IsValidRBTree(pRoot, k, blackCount);
		}
		bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount) {
			if (nullptr == pRoot)
				return true;
			// 统计黑色节点的个数
			if (BLACK == pRoot->_col) k++;
			// 检测当前节点与其双亲是否都为红色
			Node* pParent = pRoot->_parent;
			if (pParent && RED == pParent->_col && RED == pRoot->_col)
			{
				cout << "违反性质三：没有连在一起的红色节点" << endl;
				return false;
			}
			// 如果pRoot是因子节点，检测当前路径中黑色节点的个数是否有问题
			if (nullptr == pRoot->_left && nullptr == pRoot->_right)
			{
				if (k != blackCount)
				{
					cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
					return false;
				}
			}
			return _IsValidRBTree(pRoot->_left, k, blackCount) &&
				_IsValidRBTree(pRoot->_right, k, blackCount);
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

	private:
		Node* _root = nullptr;
	};

	//void TestBSTree()
	//{
	//	RBTree <int> t;
	//	//int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//	int size[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
	//	for (const auto e :size) {
	//		t.Insert(e);
	//	}
	//
	//	t.InOrder();
	//	cout << endl;
	//	cout << t.IsValidRBTree() << endl;
	//}













































	//#pragma once
	//#include <iostream>
	//using namespace std;
	//enum Color{
	//	RED,
	//	BLACK
	//};
	//template<class T>
	//struct RBNode {
	//
	//	RBNode<T>* _left;
	//	RBNode<T>* _right;
	//	RBNode<T>* _parent;
	//	T _data;
	//	Color _col;
	//
	//	RBNode(const T& data = T() , Color col = RED)
	//		:_left(nullptr)
	//		,_right(nullptr)
	//		,_parent(nullptr)
	//		,_data(data)
	//		,_col(col)
	//	{}
	//};
	//
	//template <class T>
	//class RBTree {
	//	typedef RBNode<T> Node;
	//public:
	//	bool Insert( const T& data)
	//	{
	//		if (_root == nullptr) {
	//			_root = new Node(data);
	//			_root->_col = BLACK;
	//			return true;
	//		}
	//		Node* cur = _root;
	//		Node* parent = nullptr;
	//		while (cur) {
	//			if (cur->_data < data) {
	//				parent = cur;
	//				cur = cur->_right;
	//			}
	//			else if (cur->_data > data) {
	//				parent = cur;
	//				cur = cur->_left;
	//			}
	//			else {
	//				return false;
	//			}
	//		}
	//		cur = new Node(data);
	//		cur->_col = RED;
	//		if (parent->_data < data){
	//			parent->_right = cur;
	//			cur->_parent = parent;
	//		}
	//		else {
	//			parent->_left = cur;
	//			cur->_parent = parent;
	//		}
	//		//调平衡,分情况讨论
	//		while (parent && parent->_col==RED) {
	//			Node* gp = parent->_parent;
	//			if (parent == gp->_left) {
	//				Node* uncle = gp->_right;
	//				if (uncle && uncle->_col == RED) {
	//					parent->_col = BLACK;
	//					uncle->_col = BLACK;
	//					gp->_col = RED;
	//					cur = gp;
	//					parent = gp->_parent;
	//				}
	//				else {
	//					//先写第三种情况
	//					if (parent->_right == cur) {
	//						RotateL(parent);
	//						swap(parent, cur);
	//					}
	//					RotateR(gp);
	//					parent->_col = BLACK;
	//					gp->_col = RED;
	//
	//					break;
	//				}
	//			}
	//			else {
	//				Node* uncle = gp->_left;
	//				if (uncle && uncle->_col == RED) {
	//					parent->_col = BLACK;
	//					uncle->_col = BLACK;
	//					gp->_col = RED;
	//					cur = gp;
	//					parent = gp->_parent;
	//				}
	//				else {
	//					if (parent->_left == cur) {
	//						RotateR(parent);
	//						swap(parent, cur);
	//					}
	//					RotateL(gp);
	//					parent->_col = BLACK;
	//					gp->_col = RED;
	//					break;
	//				}
	//			}
	//		}
	//		
	//		_root->_col = BLACK;
	//		return true;
	//	}
	//
	//
	//
	//	//右单旋
	//	void RotateR(Node* parent) {
	//		Node* subL = parent->_left;
	//		Node* subLR = subL->_right;
	//		parent->_left = subLR;
	//		if (subLR)
	//			subLR->_parent = parent;
	//		subL->_right = parent;
	//		Node* ppNode = parent->_parent;
	//		parent->_parent = subL;
	//		if (ppNode == nullptr) {
	//			_root = subL;
	//			_root->_parent = nullptr;
	//		}
	//		else {
	//			if (ppNode->_left == parent)
	//				ppNode->_left = subL;
	//			else
	//				ppNode->_right = subL;
	//			subL->_parent = ppNode;
	//		}
	//
	//	}
	//	//左单旋
	//	void RotateL(Node* parent)
	//	{
	//		Node* subR = parent->_right;
	//		Node* subRL = subR->_left;
	//
	//		parent->_right = subRL;
	//		if (subRL)
	//			subRL->_parent = parent;
	//		subR->_left = parent;
	//		Node* ppNode = parent->_parent;
	//		parent->_parent = subR;
	//		if (ppNode == nullptr) {
	//			_root = subR;
	//			_root->_parent = nullptr;
	//		}
	//		else {
	//			if (ppNode->_left == parent)
	//				ppNode->_left = subR;
	//			else
	//				ppNode->_right = subR;
	//			subR->_parent = ppNode;
	//		}
	//	}
	//	void RotateLR(Node* parent)
	//	{
	//		Node* subL = parent->_left;
	//		Node* subLR = subL->_right;
	//		int bf = subLR->_bf;
	//		RotateL(subL);
	//		RotateR(parent);
	//		if (bf == 1)
	//		{
	//			subL->_bf = -1;
	//			parent->_bf = 0;
	//		}
	//		else if (bf == -1) {
	//			subL->_bf = 0;
	//			parent->_bf = 1;
	//		}
	//		else { subL->_bf = parent->_bf = 0; }
	//		subLR->_bf = 0;
	//
	//	}
	//
	//	void RotateRL(Node* parent)
	//	{
	//		Node* subR = parent->_right;
	//		Node* subRL = subR->_left;
	//		int bf = subRL->_bf;
	//		RotateR(subR);
	//		RotateL(parent);
	//		if (bf == 1) {
	//			subR->_bf = 0;
	//			parent->_bf = -1;
	//		}
	//		else if (bf == -1) {
	//			subR->_bf = 1;
	//			parent->_bf = 0;
	//		}
	//		else {
	//			subR->_bf = parent->_bf = 0;
	//		}
	//		subRL->_bf = 0;
	//	}
	//
	//	bool IsValidRBTree()
	//	{
	//		Node* pRoot = _root;
	//		// 空树也是红黑树
	//		if (nullptr == pRoot)
	//			return true;
	//	
	//			// 检测根节点是否满足情况
	//			if (BLACK != pRoot->_col)
	//			{
	//				cout << "违反红黑树性质二：根节点必须为黑色" << endl;
	//				return false;
	//			}
	//		// 获取任意一条路径中黑色节点的个数
	//		size_t blackCount = 0;
	//		Node* pCur = pRoot;
	//		while (pCur)
	//		{
	//			if (BLACK == pCur->_col)
	//				blackCount++;
	//			pCur = pCur->_left;
	//		}
	//		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
	//		size_t k = 0;
	//		return _IsValidRBTree(pRoot, k, blackCount);
	//	}
	//	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount) {
	//		if (nullptr == pRoot)
	//			return true;
	//		// 统计黑色节点的个数
	//		if (BLACK == pRoot->_col) k++;
	//		// 检测当前节点与其双亲是否都为红色
	//		Node* pParent = pRoot->_parent;
	//		if (pParent && RED == pParent->_col && RED == pRoot->_col)
	//		{
	//			cout << "违反性质三：没有连在一起的红色节点" << endl;
	//			return false;
	//		}
	//		// 如果pRoot是因子节点，检测当前路径中黑色节点的个数是否有问题
	//		if (nullptr == pRoot->_left && nullptr == pRoot->_right)
	//		{
	//			if (k != blackCount)
	//			{
	//				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
	//				return false;
	//			}
	//		}
	//		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
	//			_IsValidRBTree(pRoot->_right, k, blackCount);
	//	}
	//
	//	void InOrder()
	//	{
	//		_InOrder(_root);
	//	}
	//	void _InOrder(Node* root)
	//	{
	//		if (root == nullptr)
	//			return;
	//		if (root) {
	//			_InOrder(root->_left);
	//			cout << root->_data << " ";
	//			_InOrder(root->_right);
	//		}
	//	}
	//	
	//private:
	//	Node* _root = nullptr;
	//};
	//
	//void TestBSTree()
	//{
	//	RBTree <int> t;
	//	//int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//	int size[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
	//	for (const auto e :size) {
	//		t.Insert(e);
	//	}
	//
	//	t.InOrder();
	//	cout << endl;
	//	cout << t.IsValidRBTree() << endl;
	//}
