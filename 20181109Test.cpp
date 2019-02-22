#include <iostream>
using namespace std;

#if 0
class Test
{
public:
	Test(int data)
	{
		cout << "Test():" << this << endl;
		_data = data;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

void* operator new(size_t size, char* funcName, int lineNo)
{
	cout << funcName << ":" << lineNo << endl;
	return malloc(size);
}

#define  new new(__FUNCDNAME__, __LINE__)

int main()
{
	Test* pt =  new Test(10);
	delete pt;

	return 0;
}
#endif

#if 0
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}

		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};

void TestList()
{
	List l;
}

int main()
{
	TestList();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int data)
	{
		cout << "Test():" << this << endl;
		_data = data;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

int main()
{
	int array[10];
	array[0] = 0;

	new(array + 3) int(3);

	Test* pt = (Test*)malloc(sizeof(Test));

	new(pt) Test(10);
	/*
	void* operator new(size_t size, void* p)
	{
	    return p;
	}

	call Test();
	*/

	Test* pt1 = new Test(10);
	/*
	void* operator new(size_t size)
	{
	    申请空间并返回
	}

	call Test()
	*/

	//delete pt;
	pt->~Test();
	free(pt);
	return 0;
}
#endif

/*
class Test
{
public:
	Test(int data)
	{
		cout << "Test():" << this << endl;
		_data = data;
	}

	~Test()
	{
		//delete this;
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

int main()
{
	Test* pt = new Test(10);
	delete pt;
	return 0;
}
*/

#if 0
class Solution {
public:
	class Sum
	{
	public:
		Sum()
		{
			_count++;
			_sum += _count;
		}

		static int GetSum()
		{
			return _sum;
		}

		static void ReSetSum()
		{
			_count = 0;
			_sum = 0;
		}
	private:
		static int _count;
		static int _sum;
	};

	int Sum_Solution(int n)
	{
		Sum::ReSetSum();
		Sum* ps = new Sum[n];
		delete[] ps;
		return Sum::GetSum();
	}
};

int Solution::Sum::_count = 0;
int Solution::Sum::_sum = 0;

int main()
{
	Solution s;
	cout << s.Sum_Solution(10) << endl;
	return 0;
}
#endif

#if 0
class Test
{
public:
	static Test* CreateInstrance(int data)
	{
		return new Test(data);
	}

	~Test()
	{
		cout << "~Test()" << endl;
	}

private:
	Test(int data)
	{
		cout << "Test():" << this << endl;
	}

	/*
	Test(const Test& t)
	{}
	*/

	/* C++98*/
	Test(const Test& t);

	// C++11
	//Test(const Test& t) = delete;

	


private:
	int _data;
};


int main()
{
	Test* pt = Test::CreateInstrance(10);
	delete pt;

	//Test t(*pt);
	return 0;
}
#endif

/*
class StackOnly
{
public:
	StackOnly()
	{}

private:
	void* operator new(size_t size);
	void* operator new(size_t size, void* p);
};
*/


/*
class StackOnly
{
public:
	static StackOnly CreateInstrance()
	{
		//StackOnly t;
		//return t;

		return StackOnly();
	}

	StackOnly(const StackOnly&)
	{
		cout << "StackOnly(const StackOnly&):"<<this << endl;
	}
private:
	StackOnly()
	{}
};


class Test
{
public:
	Test()
	{
		StackOnly::CreateInstrance();
	}
};


int main()
{
	StackOnly s(StackOnly::CreateInstrance());
	return 0;
}
*/

/*
class Singleton
{
public:
	Singleton& GetInstrance()
	{
		return _ps;
	}

private:
	Singleton()
	{}

private:
	
	// C++
	//Singleton(Singleton& s);

	Singleton(Singleton& s) = delete;

private:
	static Singleton _ps;
};

Singleton Singleton::_ps;
*/

#if 0
#include <thread>
#include <mutex>

// 懒汉
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (nullptr == _ps)
		{
			_mutex.lock();
			if (nullptr == _ps)
			{
				_ps = new Singleton();
				cout << "Create New Object." << endl;
			}
			_mutex.unlock();
		}
		
		return _ps;
	}

	class GC
	{
	public:
		~GC()
		{
			if (nullptr != _ps)
			{
				delete _ps;
				_ps = nullptr;
			}
		}
	};

private:
	Singleton()
	{}

	Singleton(const Singleton&);

private:
	static Singleton* volatile _ps;
	static mutex _mutex;
	static GC _gc;
};



Singleton* volatile Singleton::_ps = nullptr;
mutex Singleton::_mutex;
Singleton::GC _gc;

void func(int a)
{
	Singleton::GetInstance();
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;

	return 0;
}
#endif

#if 0
int main()
{
	char* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif

/*
int main()
{
	cout << sizeof(char*) << endl;
	return 0;
}
*/

/*
// 内存泄漏
int main()
{
	int* p1 = new int[10];
	int* p2 = new int[10];

	p1 = p2;

	delete[] p1;
	delete[] p2;

	return 0;
}
*/

// malloc---> 钩子

#if 0
#include <crtdbg.h>

int main()
{
	int* p = new int[10];
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif

/*
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	temp = right;
}

void Swap(double& left, double& right)
{
	int temp = left;
	left = right;
	temp = right;
}

void Swap(char& left, char& right)
{
	int temp = left;
	left = right;
	temp = right;
}

void Swap(float& left, float& right)
{
	int temp = left;
	left = right;
	temp = right;
}
*/


/*
template<class T1,class T2>      // 模板参数列表
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	cout<<Add(1, 2)<<endl;
	cout<<Add(1.0, 2.0)<<endl;

	Add(1, 1.0);
	return 0;
}
*/

/*
template<class T>
void PrintArray(T* array, int size)
{

}

int main()
{
	return 0;
}
*/

#if 0
template<class T>
T Add(T left, T right)
{
	return Add(left, right);
}

/*
int Add(int left, int right)
{
   return left + right;
}
*/

int main()
{
	Add(1, 2); // 实例化
	Add(1.0, 2.0);
	Add((double)1, 1.0);

	int a = 10;
	double d = 12.23;
	a = d;
	return 0;
}
#endif

// 函数模板不是一个真正的函数，是编译器来根据实例化来生成代码的规则
// template<class T>
// T Add(T left, T right)
// {
// 	return left + right;
// }

/*
int Add<int>(int left, int right)
{
   return left + right;
}
*/

/*
template<class T>
void PrintArray(T array, int size)
{
	cout << typeid(array).name() << endl;
	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";
	cout << endl;
}

void f1()
{
	cout << "f1()" << endl;
}

void f2()
{
	cout << "f2()" << endl;
}

template<class T>
void TestFun(T f)
{
	cout << typeid(T).name() << endl;
	f();
}

int main()
{
	TestFun(f1);
	TestFun(f2);

	int array[] = { 1, 2, 3, 4 };
	char str[] = "hello";

	PrintArray(array, sizeof(array) / sizeof(array[0]));
	PrintArray(str, strlen(str));

	// 隐式实例化--不会进行隐式的类型转化，需要用户自己强制转化
	Add(1, 2);
	Add(1.0, 2.0); // 实参来进行类型推演，生成处理具体类型的函数

	Add(1, (int)2.0); //1--->int 2.0--->double

	// 显式实例化
	Add<int>(1, 2.0);  // 隐式的类型转换
	return 0;
}
*/

#if 0
template<class T>
T Add(T left, T right)
{
	return left + right;
}

int Add(int left, int right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1, 2.0);
	Add<int>(1, 2);
	Add<>(1, 2);   // 隐式实例化
	return 0;
}
#endif

#if 0
template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int Add(int left, int right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add<>(1, 2);
	Add<int,int>(1, 2);
	Add(1, 2.0);
	return 0;
}
#endif

#if 0
#include <assert.h>

// 
// 类模板
template<class T>
class SeqList
{
public:
	SeqList(int capacity = 3)
		: _pData(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}


	// SeqList(const SeqList<T>& s);
	// SeqList<T>& operator=(const SeqList<T>& s)

	void PushBack(const T& data)
	{
		_CheckCapacity();
		_pData[_size++] = data;
	}

	void PopBack()
	{
		if (_size)
			--_size;
	}

	// void Insert(size_t pos, const T& data);
	// void Erase(size_t pos);

	T& Front()
	{
		return _pData[0];
	}

	const T& Front()const
	{
		return _pData[0];
	}

	T& Back()
	{
		return _pData[_size - 1];
	}

	const T& Back()const
	{
		return _pData[_size - 1];
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _pData[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _pData[index];
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	// 将顺序表中的有效元素清空
	void Clear()
	{
		_size = 0;
	}

	~SeqList();

private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			size_t newCapacity = (_capacity << 1);
			
			// 申请空间
			T* pTemp = new T[newCapacity];

			// 拷贝元素
			memcpy(pTemp, _pData, _size*sizeof(T));

			// 释放旧空间
			delete[] _pData;
			_pData = pTemp;
			_capacity = newCapacity;
		}
	}
private:
	T* _pData;
	size_t _capacity;
	size_t _size;
};

template<class T>
SeqList<T>::~SeqList()
{
	if (_pData)
	{
		delete[] _pData;
		_pData = nullptr;
		_capacity = 0;
		_size = 0;
	}
}


void TestSeqList()
{
	SeqList<int> s1;   // class SeqList<int>
	const SeqList<double> s2;  // class SeqList<double>
	//SeqList<char> s3;    // class SeqList<char>

	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1[0] = 10;
	cout << s1.Size() << endl;
	cout << s1.Front() << endl;
	cout << s1.Back() << endl;
	s1.Clear();
	cout << s1.Size() << endl;

	//s2.PushBack(1.0);
	cout << s2[0] << endl;
	//s2[0] = 2.0;
}

#include <string>
void TestSeqList2()
{
	SeqList<string> s;
	s.PushBack("1111");
	s.PushBack("2222");
	s.PushBack("3333");
	s.PushBack("4444");
	s.PushBack("5555");
	s.PushBack("6666");
	s.PushBack("7777");
	s.PushBack("8888");
	s.PushBack("9999");
	s.PushBack("0000");
	s.PushBack("1111");
	s.PushBack("2222");
	s.PushBack("3333");
}

int main()
{
	//TestSeqList();
	TestSeqList2();
	return 0;
}
#endif

#if 0
#include <string>

int main()
{
	std::string s1;
	string s2("hello");
	string s3(10, 's');
	string s4(s2, 2, 2);

	char* str = "hello";
	string s5(str, str + strlen(str));
	string s6(s5);

	cout << s2 << endl;
	cout << s3 << endl;

// 	cin >> s1;
// 	cout << s1 << endl;
// 	cin >> s1;
// 	cout << s1 << endl;
	getline(cin, s1);
	return 0;
}
#endif

#if 0
#include <string>

int main()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(8);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	return 0;
}
#endif

#include <string>

int main()
{
	string s;
	s.reserve(50);

	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	return 0;
}







