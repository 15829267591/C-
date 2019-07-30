#include <vector>
#include <iostream>
using namespace std;

# if 0
int main() 
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector <int> ::iterator it = v.begin();
	while (it != v.end())
	{
		cout <<*it << " ";
		++it;
	}
	cout << endl;

	it = v.begin();
	while (it != v.end()) {
		*it *= 2;
		++it;
	}
	cout << endl;
	//�������
	vector<int> ::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit;
		++rit;
	}
	cout << endl;
	getchar();
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day;
};



template<class T>
void PrintVector(const vector<T>& v)
{
	for (auto e : v)
		cout << e << " ";

	/*
	for(auto e = v.begin(); e != v.end(); ++it)
	   cout<< *e << " ";
	*/
	cout << endl;
}

void TestVector()
{
	std::vector<int> v1;
	std::vector<int> v2(10, 5);
	std::vector<int> v3(10);  // int() �������ͣ�ȱʡֵ��0
	std::vector<Date> v4(10); // Date()�Զ������ͣ�����T()ȱʡ�Ĺ��캯��

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v5(array, array + sizeof(array) / sizeof(array[0]));

	string str("hello");
	vector<char> v6(str.begin(), str.end());
	vector<char> v7(v6);

	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
	PrintVector(v5);
	PrintVector(v6);
	PrintVector(v7);
}

int main()
{
	TestVector();
	getchar();
	return 0;
}