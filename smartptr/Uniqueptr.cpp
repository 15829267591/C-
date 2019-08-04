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
	//C++防拷贝方式
	UniquePtr(UniquePtr<T> const& ) = delete;
	UniquePtr<T> operator=(UniquePtr<T>const & ) = delete;

	//C++98防拷贝方式 （只声明不定义）不能不写，它会用默认的，所以必须写
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