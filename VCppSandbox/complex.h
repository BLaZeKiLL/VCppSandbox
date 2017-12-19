#pragma once
class complex
{
	double re, im;
public:
	complex(double r, double i);
	complex(double r);
	complex();
	~complex();

	//Setter and Getter
	double get_real() const;
	void set_real(double r);
	double get_imag() const;
	void set_imag(double i);

	//Urinary operators
	complex& operator+=(complex z);
	complex& operator-=(complex z);
	complex& operator*=(complex z);
	complex& operator/=(complex z);
};

//These do not require direct access to complex so defined seprately from class defination
//they are stadard operations

//Urinary Minus -10
complex operator-(complex a);

//Binary operators
complex operator+(complex a, complex b);
complex operator-(complex a, complex b);
complex operator*(complex a, complex b);
complex operator/(complex a, complex b);

//Logical operators
bool operator==(complex a, complex b);
bool operator!=(complex a, complex b);