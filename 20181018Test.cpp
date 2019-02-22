#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;



/*
#define MAX(a,b) ((a)>(b)? (a):(b))

int main()
{
	int a1 = 10;
	int a2 = 20;

	cout << MAX(a1, ++a2) << endl;
	return 0;
}
*/

/*
inline int Add(int left, int right)
{
	return left + right;
}

int Sub(int left, int right)
{
	return left - right;
}


int main()
{
	int a = 1, b = 2;
	int c = Add(a, b);// 1+2
	cout << c << endl;

	c = Sub(a, b);
	cout << c << endl;
	return 0;
}
*/

/*
inline int Add(int left, int right)
{
	Add(left, right);
	return left + right;
}

int Sub(int left, int right)
{
	return left - right;
}


int main()
{
	int a = 1, b = 2;
	int c = Add(a, b);// 1+2
	cout << c << endl;

	c = Sub(a, b);
	cout << c << endl;
	return 0;
}
*/

/*
// const修饰---常量&具有宏的属性--替换
int main()
{
	const int a = 10;
	int array[a];
	int* pa = (int*)&a;

	*pa = 100;

	cout << a << endl;    //cout<<10<<endl;
	cout << *pa << endl;

	return 0;
}
*/

#if 0
int TestFunc()
{
	return 0;
}
// auto--->C++11
int main()
{
	int a = 10;
	auto/*占位符*/ b = 20;
	auto c = 'c';
	auto d = 12.34;
	auto ret = TestFunc();

	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(ret).name() << endl;
	//auto e;  auto定义的变量必须进行初始化
	return 0;
}
#endif

/*
int main()
{
	int a = 10;
	auto pa1 = &a;
	*pa1 = 20;

	auto* pa2 = &a;
	*pa2 = 30;

	auto& ra = a;
	ra = 40;

	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;
	cout << typeid(ra).name() << endl;

	return 0;
}
*/

/*
int main()
{
	auto a = 1, b = 2;
	auto c = 3, d = 4.0;
	return 0;
}
*/

#if 0
void TestFunc(auto a)
{

}

int main()
{
	TestFunc(1);
	TestFunc("1");
	return 0;
}
#endif

/*
int main()
{
	int a[3];
	auto b[3] = a;
	return 0;
}
*/

/*
namespace N1
{
	int a;
	namespace N2
	{
		typedef int DataType;
		DataType b;
	}
}

int main()
{
	N1::N2::DataType a1 = N1::N2::b;
	auto a2 = N1::N2::b;
	return 0;
}
*/

/*
int main()
{
	const float pi = 3.14;
	double r = 2.0;

	auto c = 2 * pi * r;
	return 0;
}
*/

#if 0
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	/*for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;


	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout<<array[i]<<" ";

	cout << endl;
	*/

	for (auto& e : array)
		e *= 2;

	for (auto& e : array)
		cout << e << " ";
	cout << endl;

	
	return 0;
}
#endif

/*
void TestArray(int array[3])
{
	for (auto& e : array)
		cout << e << endl;
}

int main()
{
	int* p;
	for (auto& e : p)
		cout << e << endl;
	return 0;
}
*/

/*
void TestFunc(int a)
{
	cout << "TestFunc(int)" << endl;
}

void TestFunc(int* pa)
{
	cout << "TestFunc(int*)" << endl;
}

int main()
{
	int*p1 = NULL; 
	TestFunc(0);
	TestFunc(NULL);
	TestFunc(nullptr);

	int* p2 = nullptr;
	double* p3 = nullptr;
	return 0;
}
*/

#if 0
// 学生管理系统---学生
#include <string.h>

class Student
{
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s;
	return 0;
}
#endif


// 类的定义
// 1. 类的声明与定义全部放在类中
// 2. 类的声明-->头文件   类的定义--->源文件
// int main()
// {
// 	return 0;
// }


