#include <iostream>
#include <map>
#include <string>
using namespace std;

void testMap()
{
	map<string, string> dict;

	dict.insert(make_pair("sort","排序"));
	dict.insert(make_pair("insert", "插入"));
	dict.insert(make_pair("make", "制造"));
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end()) {
		cout << it->first << " "<< it->second <<endl;
		++it;
	}
	cout << endl;
	cout << dict["make"] << endl;
	dict["make"] = "制作";
	it = dict.begin();
	while (it != dict.end()) {
		cout << it->first << " ：" << it->second << endl;
		++it;
	}
	cout << endl;
	dict["left"] = "左边";  //创建一个
	dict["left"] = "留下";  //修改，含义不同
	it = dict.begin();
	while (it != dict.end()) {
		cout << it->first << " ：" << it->second << endl;
		++it;
	}
	cout << endl;

}


class Person {

public:
	 virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
     virtual ~Student() { cout << "~Student()" << endl; }
};

class Car {
public:
	virtual void Drive() { cout << "Car()" << endl; }
};
// 2.override 修饰派生类虚函数强制完成重写
class Benz :public Car {
public:
	virtual void Drive() override {  }
};

int main()
{
	//Car* c = new Benz;
	//c->Drive();
	getchar();
	return 0;
}
//int main()
//{
//	//testMap();
//	getchar();
//	return 0;
//}