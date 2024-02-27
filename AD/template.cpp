#include <iostream>
using namespace std;

class Person
{
protected:
	int age;
	string name;

public:
	Person()
	{
		age = 0;
		name = "";
		cout << "Person: Default Constructor\n";
	}

	Person(int a, string n)
	{
		cout << "Person: Parametric Constructor\n";
		age = a;
		name = n;
	}

	Person(Person &obj)
	{
		cout << "Person: Copy Constructor\n";
		age = obj.age;
		name = obj.name;
	}

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Age:  " << age << endl;
	}
};

class Student : public Person
{
	int id;
	int semester;

public:
	Student() : Person()
	{
		cout << "Student: Default Constructor\n";
		id = 0;
		semester = -1;
	}

	Student(int id, string name, int age, int semester) : Person(age, name)
	{
		cout << "Student: Parametric Constructor\n";
		this->id = id;
		this->semester = semester;
	}

	Student(Student &obj) : Person(obj)
	{
		cout << "Student: Copy Constructor\n";
		this->id = obj.id;
		this->semester = obj.semester;
	}
};

//Templates


//void print(int value)
//{
//	cout << value << endl;
//}
//
//void print(string value)
//{
//	cout << value << endl;
//}
//
//void print(double value)
//{
//	cout << value << endl;
//}

//template <typename T1, typename T2>
//void print(T1 value1, T2 value2 )
//{
//	cout << value1 << endl;
//	cout << value2 << endl;
//}


template<typename T>
class Vector
{
	T x, y;

public:
	Vector(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
	void print();

	Vector<T> operator+(Vector<T> &obj)
	{
		return Vector<T>(x + obj.x, y + obj.y);
	}
};

template<typename W>
void Vector<W>::print()
{
	cout << x << "	" << y << endl;
}


int main()
{
	//print<double, string>(10.33, "ABC");

	Vector<int> v1(10, 20);
	Vector<int> v2(20, 30);

	(v1 + v2).print();

	return 0;
}