#include <iostream>
using namespace std;

#if 0
class Time
{
	friend void TestFunc();
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
	friend void TestFunc();
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

void TestFunc()
{
	Date d;
	d._year = 2018;

	Time t;
	t._hour = 19;
}
#endif


#if 0
class Date
{
	friend class Time;
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << ":" << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

	int GetHour()const
	{
		return _hour;
	}

	int GetMinute()const
	{
		return _minute;
	}

	int GetSecond()const
	{
		Date d;
		return _second;
	}

private:
	int _hour;
	int _minute;
	int _second;
};


int main()
{
	return 0;
}
#endif

#if 0
int _count = 0; // 任何人都可以修改

// 计数
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		++_count;
	}

	Date(const Date& d)
	{
		++_count;
	}

	~Date()
	{
		--_count;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1;
	Date d2;
	Date d3(d2);
}

int main()
{
	Date d1;
	Date d2;
	Date d3(d2);

	_count = 0;
	TestDate();
	return 0;
}
#endif

/*
// static所修饰的类成员，类的静态成员:静态的成员变量+静态的成员函数
// 
// 计数
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		++_count;
	}

	Date(const Date& d)
	{
		++_count;
	}

	~Date()
	{
		--_count;
	}

	// 静态成员函数没有this指针,因此在静态成员函数中不能访问类的非静态的成员变量
	static int GetCount()
	{
		//TestFunc();
		//cout << this << endl;
		//this->_day = 1;
		//
		return _count;
	}

	void TestFunc()
	{
		GetCount();
		this->_day = 1;
		_count = 2;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};


int Date::_count = 0;


void TestDate()
{
	Date d1;
	Date d2;
	Date d3(d2);
}


int main()
{
	//cout << Date::GetCount() << endl;
	Date d1;
	Date d2;
	Date d3(d2);

	d1.TestFunc();
	d1.GetCount();

	//cout << d1.GetCount() << endl;
	//cout << Date::_count << endl;
	return 0;
}
*/


// 显式
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!IsInvalidDate())
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	// 2018 11 1 + 100
	Date operator+(int days)
	{
		if (days < 0)
			return *this - (0 - days);

		Date temp(*this);
		temp._day += days;

		// 2018 11 101
		int daysOfMonth = 0;
		while (temp._day > (daysOfMonth = _GetDaysOfMonth(temp._year, temp._month)))
		{
			temp._day -= daysOfMonth;
			++temp._month;

			if (temp._month > 12)
			{
				temp._year += 1;
				temp._month = 1;
			}
		}

		return temp;
	}

	// 2018 11 4 - 100 = 2018 11 -94
	// 2018 11 4 - （-100） = 2018 11 4 + 100
	Date operator-(int days)
	{
		if (days < 0)
			return *this + (0 - days);

		Date temp(*this);
		temp._day -= days;

		while (temp._day <= 0)
		{
			temp._month -= 1;
			if (0 == temp._month)
			{
				temp._year -= 1;
				temp._month = 12;
			}

			temp._day += _GetDaysOfMonth(temp._year, temp._month);
		}

		return temp;
	}

	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	Date operator++(int)
	{
		Date temp(*this);
		++(*this);
		return temp;
	}

	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		--(*this);
		return temp;
	}

	// 2018 11 4
	// 2019  1 1
	int operator-(const Date& d)
	{
		Date minDate(*this);
		Date maxDate(d);

		if (*this > d)
		{
			minDate = d;
			maxDate = *this;
		}

		int count = 0;
		while (minDate != maxDate)
		{
			++count;
			++minDate;
		}

		return count;
	}

	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	bool operator>(const Date& d)const
	{
		if ((_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
		{
			return true;
		}

		return false;
	}


private:
	bool IsInvalidDate()
	{
		if (((_year > 0) &&
			(_month > 0 && _month < 13) &&
			(_day > 0 && _day <= _GetDaysOfMonth(_year, _month))))
		{
			return true;
		}

		return false;
	}

	int _GetDaysOfMonth(int year, int month)
	{
		int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (2 == month && _IsLeapYear(year))
			days[month] += 1;

		return days[month];
	}

	bool _IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) ||
			(0 == year % 400))
		{
			return true;
		}

		return false;
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month <<"-" << d._day;
		return _cout;
	}

	friend istream& operator>>(istream& _cin, Date& d)
	{
		_cin >> d._year >> d._month >> d._day;

		if (!d.IsInvalidDate())
			cout << "输入的日期非法:" << d << endl;
		return _cin;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2018, 11, 4);

	cout << d1 + (-100) << endl;
	cout << d1 - 999 << endl;

	Date d2(2019, 1, 1);
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;

	return 0;
}