#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
// 1. 类声明与定义放在类中
// 2. 类的声明.h头文件  类的定义.cpp
// 描述类属性成员---成员变量
// 类的行为--->成员函数
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	int GetAge()
	{
		return _age;
	}
private:
	char _name[20];
	char _gender[3];
	int _age;
};


struct A
{
	int a;
	int b;
	int c;
};

int main()
{
	A a;
	A* pa = &a;
	
	int* pc = (int*)((int)&a + offsetof(A,c));
	*pc = 10;
	Student s1, s2, s3;
	s1.SetStudentInfo("Peter", "男", 17);
	s2.SetStudentInfo("静静", "女", 18);
	s3.SetStudentInfo("熊二", "男", 8);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	s3.PrintStudentInfo();
	s3.GetAge();

	pc = (int*)((int)&s3 + offsetof(Student, _age));
	return 0;
}
*/

/*
class Test
{
public:
	void SetT(int t);

private:
	int _t;
};

void Test::SetT(int t)
{
	_t = t;
}
*/

/*
namespace N
{
	int t = 10;
	void TestFunc()
	{
		cout << "TestFunc()" << endl;
	}
}

// 类中的成员变量在类中具有全局的属性
class Test
{
public:
	void TestFunc(int t)
	{
		_t = t;
	}

	void PrintTest()
	{
		cout << _t << endl;
	}

private:
	int _t;
};

int t = 30;

void TestFunc(int t)
{
	cout << "TestFunc(int)" <<t<< endl;
}

int main()
{
	int t = 40;
	cout << N::t << endl;
	Test tt;
	tt.TestFunc(20);
	tt.PrintTest();
	cout << ::t << endl;
	cout << t << endl;
	return 0;
}
*/

/*
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	int GetAge()
	{
		return _age;
	}

public:
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("Peter", "男", 17);
	s2.SetStudentInfo("静静", "女", 18);
	s3.SetStudentInfo("熊二", "男", 8);
	cout << sizeof(s1) << endl;
	return 0;
}
*/

/*
// 类大小的计算方式：将类中的成员变量相加+内存对齐
class A1
{
public:
	void SetA(int a)
	{
		_a = a;
	}
private:
	int _a;
};

class A2
{
public:
	void TestA()
	{
		cout << "TestA()" << endl;
	}
};


class A3
{};

// 在C++中，空类的大小占1个字节

int main()
{
	A1 a;
	A2 b1, b2;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;
	return 0;
}
*/

/*
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

public:
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("Peter", "男", 17);
	SetStudentInfo(&s1, "Peter", "男", 17);
	s2.SetStudentInfo("静静", "女", 18);
	s3.SetStudentInfo("熊二", "男", 8);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	s3.PrintStudentInfo();
	return 0;
}
*/

/*
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

void SetStudentInfo(Student* this, char* name, char* gender, int age)
{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
}

void PrintStudentInfo(Student* this)
{
	cout << this->_name << " " << this->_gender << " " << this->_age << endl;
}

int main()
{
	Student s;
	SetStudentInfo(&s, "Peter", "男", 18);
	PrintStudentInfo(&s);
	return 0;
}
*/


// 编译器如何编译一个类？ 编译器认识类
// 1. 识别类名
// 2. 识别类中的成员变量
// 3. 识别类中的成员函数&对成员函数进行改写

// 介绍女性朋友
// 名字、性别、年龄、微信号
// 兴趣爱好&影响
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		// this = nullptr;
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	/*
	void SetStudentInfo(Student* const this, char* name, char* gender, int age)
	{
	    strcpy(this->_name, name);
	    strcpy(this->_gender, gender);
	    this->_age = age;
	}
	*/

	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	/*
	void PrintStudentInfo(Student* const this)
	{
	    cout << this->_name << " " << this->_gender << " " << this->_age << endl;
	}
	*/

public:
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s1, s2, s3;
	cout << &s1 << endl;
	s1.SetStudentInfo("Peter", "男", 17);
	/*
	SetStudentInfo(&s1, "Peter", "男", 17);
	*/
	s2.SetStudentInfo("静静", "女", 18);
	s3.SetStudentInfo("熊二", "男", 8);
	return 0;
}

