#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

template <class T>
class SharedPtr {
public:
	SharedPtr(T* ptr = NULL)
		:_ptr(ptr)
		,_pCount(new int(1))
		,_pMutex(new mutex)
	{
		if (_ptr == nullptr)
			_pCount = 0;
	}
	~SharedPtr()
	{
		Release();

	}
	//p(p1)
	SharedPtr(const SharedPtr<T> & s)
		: _ptr(s._ptr)
		,_pCount(s._pCount)
		,_pMutex(s._pMutex)
	{
		AddCount();
	}
	//p = p1;
	SharedPtr<T>& operator=(const SharedPtr<T> & s)
	{
		if (this != &s) {
			if(_ptr)
				Release();
			//
			_ptr = s._ptr;
			_pCount = s._pCount;
			//计数加一
			if(_ptr)
				AddCount();
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return  _ptr;
	}
	int AddCount()
	{
		_pMutex->lock();
		++(*_pCount);
		_pMutex->unlock();
		return *_pCount;
	}
	int SubCount()
	{
		_pMutex->lock();
		--(*_pCount);
		_pMutex->unlock();
		return *_pCount;
	}
	int UseCount()
	{
		return *_pCount;
	}
	T* Get()
	{
		return _ptr;
	}
private:
	void Release()
	{
		if (_ptr && --(*_pCount) == 0) {
			delete _ptr;
			delete _pCount;
		}
	}
private:
	T* _ptr;
	int *_pCount;   //引用计数
	mutex* _pMutex;
};

void TestSharedPtr()
{
	SharedPtr<int>sp1(new int(10));
	SharedPtr<int>sp2(sp1);
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;

}
int main()
{
	TestSharedPtr();
	getchar();
	return 0;
}