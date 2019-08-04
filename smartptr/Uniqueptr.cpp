#include <iostream>

using namespace std;
template <class T>
class UniquePtr {
public:
	UniquePtr(T* ptr)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}
	//C++��������ʽ
	UniquePtr(UniquePtr<T> const& ) = delete;
	UniquePtr<T> operator=(UniquePtr<T>const & ) = delete;

	//C++98��������ʽ ��ֻ���������壩���ܲ�д��������Ĭ�ϵģ����Ա���д
	//UniquePtr(UniquePtr<T> const&);
	//UniquePtr<T>operator=(UniquePtr<T> const &);

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