// 2014707040 À¯ÁøÇõ

#include "MyDoubleVector.h"

int main()
{
	unsigned int i;
	MyDoubleVector v1;
	cout << "< initialize v1>" << endl << endl; // constructor test
	cout << "initial size of v1 : " << v1.size() << endl;
	cout << "initial capacity of v1 : " << v1.capacity() << endl << endl;

	cout << "< v1.reserve(3) >" << endl; //reserve(size_t n) test
	v1.reserve(3);
	cout << "reserved capacity of v1 : " << v1.capacity() << endl << endl;

	cout << "< v1.push_back [0] to [4] >" << endl; // push_back(double x) test
	double x = 1.1;
	for (i = 0; i < 5; i++)
	{
		v1.push_back(x);
		cout << "v1[" << i << "] : " << v1[i] << endl; // operator[] test
		cout << "size : " << v1.size() << ", capacity : " << v1.capacity() << endl; // size(), capacity() test
		x += 1.1;
	}
	cout << endl;

	cout << "< v2 is a copy of v1 >" << endl; // copy constructor test
	MyDoubleVector v2(v1); 
	cout << "v2 size : " << v2.size() << ", v2 capacity : " << v2.capacity() << endl;
	for (i = 0; i < v2.size(); i++)
		cout << "v2[" << i << "] : " << v2[i] << endl;
	cout << endl;

	if (v1 == v2) // operator== test
		cout << "v1 and v2 are the same!" << endl << endl;

	double scalar = v1 * v2; // operator* test
	cout << "scalar product of v1 and v2 : " << scalar << endl << endl;

	cout << "< v3 = v2 >" << endl; // operator= test
	MyDoubleVector v3 = v2;
	for (i = 0; i< v3.size(); i++)
		cout << "v3[" << i << "] : " << v3[i] << endl;
	cout << endl;

	cout << "< v3 = v1 + (-v2) >" << endl; // operator+, unary operator-, operator= test
	v3 = v1 + (-v2);
	for(i = 0; i< v3.size(); i++)
		cout << "v3[" << i << "] : " << v3[i] << endl;
	cout << endl;

	cout << "< v3(5.5) : makes every element be 5.5 >" << endl; // operator() test
	v3(5.5);
	for (i = 0; i< v3.size(); i++)
		cout << "v3[" << i << "] : " << v3[i] << endl;
	cout << endl;

	cout << "< v2 = v3 - v1 >" << endl; // binary operator- test
	v2 = v3 - v1;
	for (i = 0; i< v2.size(); i++)
		cout << "v2[" << i << "] : " << v2[i] << endl;
	cout << endl;

	cout << "< v1 += v2 >" << endl; // operator+= test
	v1 += v2;
	cout << "size of v1 : " << v1.size() << ", capacity of v1 : " << v1.capacity() << endl;
	for (i = 0; i< v1.size(); i++)
		cout << "v1[" << i << "] : " << v1[i] << endl;
	cout << endl;

	cout << "< swap v1[8] and v1[9] >" << endl; // operator[] test
	double temp = v1[8];
	v1[8] = v1[9];
	v1[9] = temp;
	for (i = 0; i< v1.size(); i++)
		cout << "v1[" << i << "] : " << v1[i] << endl;
	cout << endl;

	cout << "< v1 pop_back 5 times >" << endl; // pop_back() test
	cout << "size before pop_back : " << v1.size() << endl;
	for (i = 0; i < 5; i++)
		v1.pop_back();
	cout << "size after pop_back : " << v1.size() << endl;
	for (i = 0; i< v1.size(); i++)
		cout << "v1[" << i << "] : " << v1[i] << endl;
	cout << endl;

	cout << "< v1 pop_back 5 times again>" << endl; // empty() test
	for (i = 0; i < 5; i++)
		v1.pop_back();
	if (v1.empty())
		cout << "v1 is empty" << endl << endl;

	cout << "< clearing v1 >" << endl; // clear() test
	v1.push_back(10.1);
	v1.push_back(10.2);
	v1.push_back(10.3);
	cout << "v1 contains";
	for (i = 0; i < v1.size(); i++)
		cout << " " << v1[i];
	cout << endl;
	cout << "-- clear & push_back --" << endl;
	v1.clear();
	v1.push_back(20.1);
	v1.push_back(20.2);
	cout << "v1 contains";
	for (i = 0; i < v1.size(); i++)
		cout << " " << v1[i];
	cout << endl;

	return 0;
}