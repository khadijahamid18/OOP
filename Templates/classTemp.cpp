#include "iostream" 

using namespace std;

// class template
template <class t>
class Algebra
{
	t a, b; // data members

public:
	Algebra() // default constructor
	{
		a = b = 0;
	}

	Algebra(t a, t b) // parameterized constructor
	{
		this->a = a;
		this->b = b;
	}

	void getData() // member function to get input from user for data members
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;
	}

	void print(); // member function to display data members on the screen

	/*
		overloaded stream extraction operator. No need to define a template separately,
		if a friend function is defined within the class
	*/
	friend istream &operator>>(istream &in, Algebra &obj)
	{
		cout << "Enter a = ";
		in >> obj.a;

		cout << "Enter b = ";
		in >> obj.b;

		return in;
	}

	/*
		overloaded stream insertion operator.
		Have to define a template separately,
		if a friend function is defined outside the class
	*/
	template <typename t>
	friend ostream &operator<<(ostream &out, const Algebra<t> &obj);
};

template <typename t> // define template again, when defining member function out side the class
void Algebra<t>::print()
{
	cout << "a = " << a << "\t"
		 << "b = " << b << endl;
}

template <typename t>
ostream &operator<<(ostream &out, const Algebra<t> &obj) // overloaded stream insertion operator
{
	out << "a = " << obj.a << "\t"
		<< "b = " << obj.b << endl;

	return out;
}

int main()
{
	Algebra<int> obji; // template class for int
	obji.getData();
	obji.print();

	Algebra<float> objf(1.1f, 2.2f); // template class for float
	objf.print();

	Algebra<char> objc; // template class for char
	cin >> objc;
	cout << objc;

	return 0;
}