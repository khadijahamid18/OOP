#include<iostream>
using namespace std;

class Item
{
	int x;
public:
	Item(): x(0)  // Default Constructors
	{}

	Item(int x)  // Parameterized Constructor
	{
		this->x = x;
	}

	int getX() const  // Getter (const is liye kiya ta k hr const ki call isko a saky)
	{
		return x;
	}
	

	Item(const Item& obj) // Copy Constructors
	{
		this->x = obj.x;
	}

	friend void print1(const Item& obj)
	{
		cout << obj.x << endl;
	}

	void print()
	{
		cout << x << endl;
	}

	Item add(const Item& obj) const
	{
		return Item(x + obj.x);
	}

	Item multiply(const Item& obj) const
	{
		return Item(x * obj.x);
	}

	friend Item operator+(const Item& o1, const Item& o2);

	Item operator*(const Item& obj)
	{
		return Item(this->x * obj.x);
	}
};

Item operator+(const Item& o1, const Item& o2)
{
	cout << o1.x << endl;
	return Item(o1.x + o2.x);
}

Item add(float x, float y)
{
	return x + y;	//3.7   ---> Item(3.7) ----> Item(3) // jo return type hoti return bhi usi type ka hota hy 
}


int main()
{

	Item o1(20), o2(10), o3(o2);

	Item res = operator+(o1, o2);		// o1 + o2
	Item res1 = o1.operator*(o2);		// this, o2

	add(3.3, 3.4);

	res.print();
	
}