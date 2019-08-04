#include <memory>
#include <iostream>
using namespace std;
class Date
{
public:
	Date()
	{
		cout << "Date()" << endl;
	}
	~Date()
	{
		cout << "~Date()" << endl;
	}

	int year;
	int month;
	int days;
};

void  test()
{
	auto_ptr<Date>d1(new Date);
	auto_ptr<Date>d2(d1);
	d1->year = 2019;
}
template <class T>
class AutoPtr {
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{
		cout << "AutoPtr() :" <<_ptr << endl;
	}
	~AutoPtr()
	{
		cout << "~AutoPtr() :"  << _ptr<< endl;
		if (_ptr)
			delete _ptr;
	}
	//这里没有用const 因为要修改它
	AutoPtr(AutoPtr<T>& s)
	{
		cout << "AutoPtr(T&ptr) : " << _ptr << endl;
		_ptr = s._ptr;
		//将原对象悬空
		s._ptr = nullptr;
	}
	AutoPtr<T> operator=(AutoPtr<T>& s)
	{
		if (*this != s) {
			//如果当前对象中有资源，释放
			if (_ptr)
				delete _ptr;
			//将s中的资源转移到当前对象中
			_ptr = s._ptr;
			s._ptr = nullptr;
		}
		return *this;
	}
	T& operator* ()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

void TestAutoPtr()
{
	AutoPtr<Date> p(new Date);
	AutoPtr<Date> p2(p);
}
//int main()
//{
//
//	//test();
//	TestAutoPtr();
//	getchar();
//	return 0;
//}
