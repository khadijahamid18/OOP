#include "iostream"
using namespace std;

class Integer
{
	int* ptrNum;	//holds address of memory allocated on heap
	
public:
	//default constructor
	Integer()
	{
		ptrNum = new int(0);	//memory created on heap and initialized with 0
	}

	//parameterized constructor
	Integer(int number)
	{
		this->ptrNum = new int(number);		//memory created on heap and initialized with number
	}

	//deep copy constructor
	Integer(const Integer& obj)
	{
		ptrNum = new int(*(obj.ptrNum));	//memory created on heap and initialized with data of right-hand-side object
	}

	//destructor
	~Integer()
	{
		delete ptrNum;		//free the memory resources allocated on heap by an object
	}
	
	//overloaded assignment operator
	Integer operator= (const Integer& obj)
	{
		if (this != &obj)
		{
			*ptrNum = *(obj.ptrNum);
		}

		return *this;
	}

	//setter to set the data-value of memory allocated to ptrNum
	void setNumber(int number)
	{
		*(this->ptrNum) = number;
	}

	//getter to get the data-value of memory allocated to ptrNum
	int getNumber()
	{
		return *ptrNum;
	}

	//take input from user for the memory allocated to ptrNum
	void input()
	{
		cout << "Enter Number = ";
		cin >> *ptrNum;
	}

	//display the data-value of memory allocated to ptrNum
	void print()
	{
		cout << "Number = " << *ptrNum << endl;
	}
};

int main()
{
	Integer obj1, obj2(99);
	Integer obj3 = obj2;

	obj1.input();	//100

	obj2 = obj1;

	obj1.print();	//100
	obj2.print();	//100
	obj3.print();	//99
	
	return 0;
}
