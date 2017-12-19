#pragma once
template<typename T>
class less_than
{
	T val;
public:
	less_than(const T& v) : val(v) {}
	//~less_than();
	bool operator()(const T& x)const { return x < val; }
};

