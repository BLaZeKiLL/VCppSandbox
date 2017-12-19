#pragma once
#include "Container.h"

template<typename T>
class vector_container :public Container
{
	myns::Vector<T> v;
public:
	vector_container(int s);
	~vector_container();

	double& operator[](const int i) override { return v[i]; }
	int size() const override { return v.getSize(); }
};


