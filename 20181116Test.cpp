#include <iostream>
using namespace std;

#include <string>
using namespace std;


#if 0
int main()
{
	string s1;
	string s2("hello");
	string s3(10, 'a');
	string s4(s3);
	string s5(s2, 3);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello bit!");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(5);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << (int)(s.c_str()) << endl;

	s.resize(8, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << (int)(s.c_str()) << endl;

	s.resize(30, '$');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << (int)(s.c_str()) << endl;

	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << (int)(s.c_str()) << endl;

	return 0;
}
#endif

#if 0
int main()
{
	string s1("hello");
	s1[0] = 'H';
	cout << s1 << endl;

	const string s2("world");
	cout << s2[0] << endl;
	cout << s2.at(0) << endl;
	//s2[0] = 'W';

	return 0;
}
#endif

#if 0
int main()
{
	// main.cpp
	// C:\File\main.cpp

	/*
	string s1("main.cpp.cpp");
	cout<<s1.substr(s1.rfind('.')+1)<<endl;

	string s2("C:\\File\\main.cpp");
	size_t start = s2.rfind('\\') + 1;
	size_t end = s2.rfind('.');
	cout << s2.substr(start, end-start) << endl;
	*/

	string url("http://www.cplusplus.com/reference/string/string/find/");

	size_t start = url.find("://")+3;
	size_t end = url.rfind('.')+4;
	cout << url.substr(start, end - start) << endl;

	start = url.find(".com") + 5;
	end = url.find('/', start);
	cout << url.substr(start, end - start) << endl;
	return 0;
}
#endif

#if 0
void TestPushBack()
{
	string s;
	s.reserve(100);

	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

int main()
{
	TestPushBack();
	return 0;
}
#endif


int main()
{
	string str;
	//cin >> str;
	while (getline(cin, str).eof() != ios_base::eofbit)
	{
		cout << str.substr(str.rfind(' ') + 1).size() << endl;
	}
	
	cout << str << endl;
	return 0;
}