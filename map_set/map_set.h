template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight; T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		: _pRoot(nullptr)
	{}
	~BSTree()
	{
		_Destroy(_pRoot);
	}
	PNode Find(const T& data)
	{
		PNode pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_pLeft)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return nullptr;
	}
	bool Insert(const T& data)
	{
		// �����Ϊ�գ�ֱ�Ӳ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// ���ն��������������ʲ���data�����еĲ���λ��
		PNode pCur = _pRoot;
		// ��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight; // Ԫ���Ѿ������д���
			else
				
				return false;
		}
		// ����Ԫ��
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}
	bool Erase(const T& data)
	{
		// �����Ϊ�գ�ɾ��ʧ��
		if (nullptr == _pRoot)
			return false;
		// ������data�����е�λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		// data���ڶ��������������޷�ɾ��
		if (nullptr == pCur)
			return false;
		// �������������ɾ����ͬѧ���Լ���ͼ�������
		if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ�����ӻ�������Ϊ��---��ֱ��ɾ��
		}
		else if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ���Һ���---��ֱ��ɾ��
		}
		else
		{
		
				// ��ǰ�ڵ����Һ��Ӷ����ڣ�ֱ��ɾ������ɾ��������������������һ�������㣬���磺
				// �����������е����ڵ㣬�������������Ҳ�Ľڵ㣬������������������С�Ľڵ㣬������
				//������С�Ľڵ�
				// ����ڵ��ҵ��󣬽�����ڵ��е�ֵ������ɾ���ڵ㣬ת����ɾ������ڵ�
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_pRoot);
	}
private:
	void _InOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
	void _Destroy(PNode& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			pRoot = nullptr;
		}
	}
private:
	PNode _pRoot;
};