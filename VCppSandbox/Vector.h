#pragma once
#include <thr/xtime>
#include <iterator> // checked iterator for liast ini

namespace myns
{
	template<typename T>
	class Vector
	{
	private:
		T * elements;
		int size;

	public:

		explicit Vector(int size);
		Vector(std::initializer_list<T> list);
		Vector(const Vector& a);  // copy constuct
		Vector(Vector&& a) noexcept; // move consturct
		~Vector();

		const T& operator[](int i) const;
		Vector& operator=(const Vector& a); // copy assign
		Vector& operator=(Vector&& a) noexcept; // move assign

		int get_size() const;
		void set_element(int i, int x);
		void display();

		T* begin();
		T* end();

		template<typename Container,typename Value>
		Value sum(Container& c, Value v);
	}; // class end

	//tempalte class function definition need to be in header file 
	template<typename T>
	Vector<T>::Vector(const int size)
	{
		if (size < 0) throw std::length_error{ "size can't be less than 0" };
		elements = new T[size];
		this->size = size;
		for (int i = 0; i < this->size; i++)
			elements[i] = 0;
		// std::cout << "HI " << std::endl; //counstructor tester
	}

	// list ini eg Vector v ={10,20,30,40};
	template<typename T>
	Vector<T>::Vector(std::initializer_list<T> list) : elements{ new T[list.size()] }, size{ int(list.size()) }
	{
		std::copy(list.begin(), list.end(), stdext::checked_array_iterator<T*>(elements, size));
	}

	template<typename T>
	Vector<T>::Vector(const Vector & a) : elements(new T[a.size]), size(a.size)
	{
		for (int i = 0; i < size; i++)
		{
			elements[i] = a.elements[i];
		}
	}

	template<typename T>
	Vector<T>::Vector(Vector && a) noexcept : elements(a.elements), size(a.size)
	{
		a.elements = nullptr;
		a.size = 0;
	}

	template<typename T>
	Vector<T>::~Vector() // called when flow is out fo scope of the object
	{
		delete[] elements;
		//std::cout << std::endl << "decounstructer called " << std::endl; // decounstructor tester
	}

	template<typename T>
	const T& Vector<T>::operator[](const int i) const
	{
		if (i < 0 || get_size() <= i)
			throw std::out_of_range("Vector::operator[]");
		return elements[i];
	}

	template<typename T>
	Vector<T> & Vector<T>::operator=(const Vector & a)
	{
		T* p = new T[a.size];
		for (int i = 0; i < a.size; i++)
			p[i] = a.elements[i];
		delete[] elements;
		elements = p;
		size = a.size;
		return *this;
	}

	template<typename T>
	Vector<T> & Vector<T>::operator=(Vector && a) noexcept
		// experimental
	{
		delete elements;
		elements = a.elements;
		size = a.size;
		a.elements = nullptr;
		a.size = 0;
		return *this;
	}

	template<typename T>
	int Vector<T>::get_size() const
	{
		return size;
	}

	template<typename T>
	void Vector<T>::set_element(const int i, const int x)
	{
		elements[i] = x;
	}

	template<typename T>
	void Vector<T>::display()
	{
		for (int i = 0; i < get_size(); i++)
			std::cout << elements[i] << " ";
	}

	template<typename T>
	T * Vector<T>::begin()
	{
		return &elements[0];
	}

	template<typename T>
	T * Vector<T>::end()
	{
		return begin() + get_size();
	}

	template<typename T>
	template<typename Container, typename Value>
	Value Vector<T>::sum(Container & c, Value v) 
	{
		for (auto& x : c)
		{
			v += x;
		}
		return v;
	}
}