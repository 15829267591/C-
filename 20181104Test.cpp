 #include <iostream>
 using namespace std;
 
 /*
 int main()
 {
 	int* p = (int*)malloc(sizeof(int)* 10);
 	p[0] = 0;
 	p[1] = 1;
 	p[8] = 8;
 	p[9] = 9;
 	return 0;
 }
 */
 
 
 /*
 // new/delete--->操作符
 // new+类型
 // new/delete--->单个元素空间的申请与释放
 // new[]/delete[]--->连续空间的申请与释放
 // 成对来使用
 int main()
 {
 	int* p1 = new int;
 	int* p2 = new int(10);
 	int* p3 = new int[10];
 
 	delete p1;
 	delete p2;
 	delete[] p3;
 	return 0;
 }
 */
 
 // malloc/free
 // new/delete
 // new[] / delete[]
 
 // 没有匹配使用后果：1. 代码存在内存泄漏
 //                2. 立马崩溃
 
 /*
 int main()
 {
 	int* p1 = (int*)malloc(sizeof(int));
 	int* p2 = (int*)malloc(sizeof(int));
 
 
 	int* p3 = new int;
 	int* p4 = new int;
 
 	int* p5 = new int[10];
 	int* p6 = new int[10];
 
 	delete p1;
 	delete[] p2;
 
 	free(p3);
 	delete[] p4;
 
 	free(p5);
 	delete[] p6;
 
 	return 0;
 }
 */
 
 #if 0
 class Test
 {
 public:
 	Test()
 		: _pa(new int)
 	{
 		cout << "Test():" << this << endl;
 	}
 
 	~Test()
 	{
 		if (_pa)
 			delete _pa;
 
 		cout << "~Test():" << this << endl;
 	}
 
 	int _data;
 	int* _pa;
 };
 
 
 int main()
 {
 	// malloc不会调用构造函数
 	// free: 不会调用析构函数
 	//Test* p = (Test*)malloc(sizeof(Test));
 	
 	// new: 会调用类型的构造函数 
 	Test* p = new Test;
 
 	// 释放堆内存时，会调用析构函数
 	delete p;
 	return 0;
 }
 #endif
 
 #if 0
 class Test
 {
 public:
 	Test()
 	{
 		cout << "Test():" << this << endl;
 	}
 
 	~Test()
 	{
 		cout << "~Test():" << this << endl;
 	}
 
 	int _data;
 };
 
 int main()
 {
 	//Test* p = (Test*)malloc(sizeof(Test));
 	Test* p = new Test[10];
 	delete[] p;
 	return 0;
 }
 #endif
 
 /*
 class Test
 {
 public:
 	Test()
 	{
 		cout << "Test():" << this << endl;
 	}
 
 	~Test()
 	{
 		cout << "~Test():" << this << endl;
 	}
 
 	int _data;
 };
 
 
 int main()
 {
 	//Test* p = new Test;
 	//delete[] p;
 
 	Test* p = new Test[10];
 	delete p;
 
 	return 0;
 }
 */
 
 /*
 class Test
 {
 public:
 	Test()
 	{
 		cout << "Test():" << this << endl;
 	}
 
 	~Test()
 	{
 		cout << "~Test():" << this << endl;
 	}
 
 	int _data;
 };
 
 int main()
 {
 	Test* p = new Test;
 
 	delete p;
 	return 0;
 }
 */

 
 





