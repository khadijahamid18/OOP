#include "iostream"

using namespace std;

class Algebra
{
	//data members of the class
	int a, b;
	const int c;	//constant data member, must be initialized in intializer list of Constructors.

public:
	//Default Constructor
	Algebra() : c(0)
	{
		this->a = this->b = 0;

		cout << "Default Constructor" << endl;
	}

	//Parameterized Constructor
	Algebra(int a, int b, int c) : c(c)
	{
		this->a = a;
		this->b = b;

		cout << "Parameterized Constructor" << endl;
	}

	//Copy Constructor
	Algebra(const Algebra& obj) : c(obj.c)
	{
		this->a = obj.a;
		this->b = obj.b;

		cout << "Copy Constructor" << endl;
	}

	//Destructor
	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	//setter for data memeber a
	void setA(int a)
	{
		this->a = a;
	}

	//getter for data memeber a
	int getA()
	{
		return this->a;
	}

	//setter for data memeber b
	void setB(int b)
	{
		this->b = b;
	}

	//getter for data memeber a
	int getB()
	{
		return this->b;
	}

	//getter for constant data memeber c but there can't be setter for c bcz it is constant and must be initialized at creation time
	int getC()
	{
		return this->c;
	}

	//function to set object's data
	void setData(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	//function to take input for object's data
	void getData()
	{
		cout << "Enter a = ";
		cin >> this->a;

		cout << "Enter b = ";
		cin >> this->b;
	}

	//function to display object's data on screen
	void putData()
	{
		cout << "a = " << this->a << "\t";
		cout << "b = " << this->b << "\t";
		cout << "c = " << this->c << endl;
	}

	//function to add two objects (left-hand-side and right-hand-side) and return their result
	Algebra add(const Algebra& obj)
	{
		return Algebra(this->a + obj.a, this->b + obj.b, this->c + obj.c);
	}

	//search the left hand side object in the array passed as argument 
	bool searchArray(const Algebra ar[], const int size)
	{
		for (int i = 0; i < size; i++)
		{
			if ((this->a == ar[i].a) && (this->b == ar[i].b) && (this->c == ar[i].c))
				return true;
		}

		return false;
	}
};

int main()
{
	//-----------------------------------------------//
	//declaring a pointer of Algebra type
	Algebra* po;
	 
	//creating an object of Algebra on Heap
	po = new Algebra(88, 99, 100);

	//two ways to access members through pointer 
	(*po).putData();	//first

	po->putData();		//second

	delete po;			//free memory resources allocated on Heap
	//-----------------------------------------------//

	

	//-----------------------------------------------//
	//creating and intializing an array of Algebra on Heap
	po = new Algebra[3]{ Algebra(44, 55, 99), Algebra(), Algebra(66, 77, 100) };
	

	for (int i = 0; i < 3; i++)
	{
		po[i].putData();		//OR	(po + i)->putData();		
	}

	delete[] po;		//free memory resources allocated on Heap
	//-----------------------------------------------//
	
	return 0;
}