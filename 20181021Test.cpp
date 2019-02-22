#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
// 
/*
1. 识别类名
2. 识别类中的成员变量
3. 识别类中的成员函数&进行改写
   给类的成员函数增加一个默认的参数----this指针
   在成员函数中通过this指针去访问"成员变量"
*/
class Date
{
public:
	/*
	void SetDate(Date* const this, int year, int month, int day)
	{
	    this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	*/
	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void TestFunc(...)
	{
		cout << this << endl;
	}

	/*
	void PrintDate(Data& d)
	void PrintDate(Date* cosnt this)
	{
	    cout << this->_year << "-" << this->_month << " " << this->_day << endl;
	}
	*/
	void PrintDate()
	{
		cout << _year << "-" << _month << " " << _day << endl;
	}

//private:
	int _year;
	int _month;
	int _day;
};


// this   类类型*  const === 引用
int main()
{
	Date d1,d2,d3;
	d1.SetDate(2018, 10, 21);
	Date* pd = &d1;
	pd->PrintDate();

	pd = nullptr;
	pd->TestFunc();  // Date::TestFunc(pd)
	pd->SetDate(2018, 10, 22);

	pd->_year = 2019;

	d1.TestFunc();

	
	cout << sizeof(d1) << endl;
	
	/*
	  Date::SetDate(&d1, 2018, 10, 21);
	*/
	d1.PrintDate();

	d2.SetDate(2018, 10, 21);
	return 0;
}
#endif


/*
class Date
{
public:
	// 在类中定义的成员函数，编译器可能会将其当成内联函数来处理
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year);

	Date(int year, int month, int day)
	{
		cout << "Date::Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

Date::Date(int year)
{
	_year = year;
}




void TestFunc()
{
	Date d0;  // Date()
	Date d1(2018, 10, 24);   // call Date::Date()
	d1.PrintDate();
}

int main()
{
	TestFunc();
	return 0;
}
*/

#if 0
// 
class Date
{
public:
	/*
	// 如果用户没有显式定义，编译器合成的默认的构造函数
	Date()
	{}
	*/

	// 缺省构造函数
	Date()
	{}

	// 显式定义了构造函数
	// 只要用户显式定义，默认的构造函数将不会合成
	// 带有全缺省的构造函数---缺省的构造函数
	// 无参的和带有全缺省的构造函数只能存在一个
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d;
	//Date d(2018, 10, 21);
	return 0;
}
#endif


/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		cout << "Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestFunc()
{
	Date d(2018, 10, 21);
}

int main()
{
	TestFunc();
	return 0;
}
*/

/*
#include <assert.h>

typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr == _array)
		{
			assert(0);
		}

		_capacity = capacity;
		_size = 0;
	}

	void PushBack(const DataType& data)
	{
		// _CheckCapacity();
		_array[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};

void TestFunc()
{
	SeqList s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);

	s.PopBack();
}


int main()
{
	TestFunc();
	return 0;
}
*/

/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		cout << "Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		cout << "Date(Date& d):" << this << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018, 10, 21);
	Date d2(d1);
	return 0;
}
*/

#if 0
#include <assert.h>

typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr == _array)
		{
			assert(0);
		}

		_capacity = capacity;
		_size = 0;
	}

	void PushBack(const DataType& data)
	{
		// _CheckCapacity();
		_array[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};

void TestFunc()
{
	SeqList s1;
	SeqList s2(s1);
}

int main()
{
	TestFunc();
	return 0;
}
#endif

int main()
{
	return 0;
}