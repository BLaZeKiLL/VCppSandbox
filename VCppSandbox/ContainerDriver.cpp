#include"stdafx.h"

using namespace std;

void use(Container& c)
{
	const int size = c.size();
	for (int i = 0; i < size; i++)
	{
		cout << c[i] << '\n';
	}
}