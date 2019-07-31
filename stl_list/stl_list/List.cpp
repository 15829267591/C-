#include <iostream>
#include <list>
#include "Vector.h"
void test1()
{
	std::list<int> l1(3, 10);
	std::list<int>::iterator it = l1.begin();
	while (it != l1.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	for (auto e : l1) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
void test2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// ʹ���������������list�е�Ԫ��
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	// ʹ�÷�������������ӡlist�е�Ԫ��
	for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	// cosnt�����������
		auto cit = l.cbegin();
	std::cout << typeid(cit).name() << std::endl;
	//*cit = 10; ���д������ʧ�ܣ���ΪcitΪconst_iterator���͵ĵ�����
}
void test3()
{
	std::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	for (auto e : l1)
		std::cout << e << " ";
	std::cout << std::endl;
	std::list<int>::iterator it = std::find(l1.begin(), l1.end(), 3);
	if (it != l1.end())
		l1.insert(it, 20);
	std::cout << *it << std::endl;
	for (auto e : l1)
		std::cout << e << " ";
	std::cout << std::endl;

}
int main()
{
	//test1();
	//test2();
	//test3();
	TestList1();
	getchar();
	return 0;
}