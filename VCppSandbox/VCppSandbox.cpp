// VCppSandbox.cpp : Defines the entry point for the console application.
// execution starts at the int main(). driver functions can be added there 

#include "stdafx.h"
#include "VCppSandbox.h"
#include <vector>

using namespace std;

int main()
{
	//complex_main();
	//vector_main();
	less_than_main();
    return 0;
}

// driver for the complex.cpp
void complex_main()
{
	double x, y;
	cout << "enter a and b" << endl;
	cin >> x >> y;
	complex z(x,y);
	complex a(2.3);
	complex b(1/a);
	complex c(a + z*complex(1,2.3));
	cout << "z.real = " << z.get_real() << " z.imag = " << z.get_imag() << endl;
	cout << "a.real = " << a.get_real() << " a.imag = " << a.get_imag() << endl;
	cout << "b.real = " << b.get_real() << " b.imag = " << b.get_imag() << endl;
	cout << "c.real = " << c.get_real() << " c.imag = " << c.get_imag() << endl;
}

// driver for Vector.cpp
void vector_main()
{
	myns::Vector<double> v(6);
	myns::Vector<int> d = { 1,2,3,4,5 };
	d.display();
	cout << endl;
	v.display();
	cout << endl;
	for (int i = 0; i < v.get_size(); i++)
	{
		v.set_element(i, i);
	}
	v.display();
	myns::Vector<int> c = d;
	d.set_element(2, 10); // changing d doestn change c therfore copy method used
	cout << endl;
	c.display();
	cout << endl;
	d.display();
	myns::Vector<int> x = move(d);
	cout << endl;
	x.display();
	cout << endl;
	cout << "size = " <<d.get_size(); // size becomes 0 as the move construct defined works 
	cout << endl;
	for(auto& s : x)
	{
		cout << s << '\n';
	}
	const int sm = x.sum(x, 0);
	cout << endl << sm << endl;
}

void less_than_main()
{
	less_than<int> lti{42};
	bool b1 = lti(10);
	bool b2 = lti(100);
	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;
}
