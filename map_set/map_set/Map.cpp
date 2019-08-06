#include <iostream>
#include <map>
#include <string>
using namespace std;

void testMap()
{
	map<string, string> dict;

	dict.insert(make_pair("sort","����"));
	dict.insert(make_pair("insert", "����"));
	dict.insert(make_pair("make", "����"));
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end()) {
		cout << it->first << " "<< it->second <<endl;
		++it;
	}
	cout << endl;
	cout << dict["make"] << endl;
	dict["make"] = "����";
	it = dict.begin();
	while (it != dict.end()) {
		cout << it->first << " ��" << it->second << endl;
		++it;
	}
	cout << endl;
	dict["left"] = "���";  //����һ��
	dict["left"] = "����";  //�޸ģ����岻ͬ
	it = dict.begin();
	while (it != dict.end()) {
		cout << it->first << " ��" << it->second << endl;
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
// 2.override �����������麯��ǿ�������д
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