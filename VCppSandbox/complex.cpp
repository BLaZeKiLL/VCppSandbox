#include "stdafx.h"
#include "complex.h"


// can be done in any way earlier and by using ':' and arg list

complex::complex(const double r, const double i) : re{r},im{i} {}

complex::complex(const double r) : re{ r }, im{ 0 } {}

complex::complex()
{
	re = 0;
	im = 0;
}

// decounstructor
complex::~complex()
{
	std::cout << "decounstructor called"<<std::endl;
}

double complex::get_real() const
{
	return re;
}

void complex::set_real(const double r)
{
	re = r;
}

double complex::get_imag() const
{
	return im;
}

void complex::set_imag(const double i)
{
	im = i;
}

complex & complex::operator+=(const complex z)
{
	re += z.re;
	im += z.im;
	return *this;
}

complex & complex::operator-=(const complex z)
{
	re -= z.re;
	im -= z.im;
	return *this;
}

complex & complex::operator*=(const complex z)
{
	re *= z.re;
	im *= z.im;
	return *this;
}

complex & complex::operator/=(const complex z)
{
	re /= z.re;
	im /= z.im;
	return *this;
}

complex operator-(complex a)
{
	return { -a.get_real(),-a.get_imag() };
}

complex operator+(complex a, const complex b)
{
	return a+=b;
}

complex operator-(complex a, const complex b)
{
	return a-=b;
}

complex operator*(complex a, const complex b)
{
	return a*=b;
}

complex operator/(complex a, const complex b)
{
	return a/=b;
}

bool operator==(complex a, complex b)
{
	return (a.get_real() == b.get_real() && a.get_imag() == b.get_imag());
}

bool operator!=(const complex a, const complex b)
{
	return !(a==b);
}