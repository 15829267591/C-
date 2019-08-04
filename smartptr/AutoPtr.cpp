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
	//����û����const ��ΪҪ�޸���
	AutoPtr(AutoPtr<T>& s)
	{
		cout << "AutoPtr(T&ptr) : " << _ptr << endl;
		_ptr = s._ptr;
		//��ԭ��������
		s._ptr = nullptr;
	}
	AutoPtr<T> operator=(AutoPtr<T>& s)
	{
		if (*this != s) {
			//�����ǰ����������Դ���ͷ�
			if (_ptr)
				delete _ptr;
			//��s�е���Դת�Ƶ���ǰ������
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
