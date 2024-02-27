#include <iostream>
using namespace std;

class Player
{
    int px, py;

public:
    Player(int x, int y)
    {
        x = px;
        y = py;
    }

    void print()
    {
        cout << px << "	" << py << endl;
    }

    friend ostream &operator<<(ostream &out, const Player &obj)
    {
        out << obj.px << "	" << obj.py << endl;
        return out;
    }

    friend Player operator+(const Player &p1, const Player &p2);
    // friend void operator<<(ostream &out, Player &obj);
};

// void operator<<(ostream &out, Player &obj)
// {
// 	out << obj.px << "	" << obj.py << endl;
// }

Player operator+(const Player &p1, const Player &p2)
{
    Player temp(p1.px + p2.px, p1.py + p2.py);
    return temp;
}

// class Array
// {
// 	int *ptr;
// 	int size;

// public:
// 	Array(int x)
// 	{
// 		size = x;
// 		ptr = new int[size];
// 		for (int i = 0; i < size; i++)
// 		{
// 			ptr[i] = i;
// 		}
// 	}

// 	Array(const Array &obj)
// 	{
// 		size = obj.size;
// 		ptr = new int[size];
// 		for (int i = 0; i < size; i++)
// 		{
// 			ptr[i] = obj.ptr[i];
// 		}
// 	}

// 	~Array()
// 	{
// 		delete[] ptr;
// 	}

// 	void print()
// 	{
// 		for (int i = 0; i < size; i++)
// 		{
// 			cout << ptr[i] << "	";
// 		}
// 		cout << endl;
// 	}

// Array operator+(const Array &o2)		//adding two arrays
// {
// 	Array temp(size);
// 	for (int i = 0; i < size; i++)
// 	{
// 		temp.ptr[i] = this->ptr[i] + o2.ptr[i];
// 	}
// 	return temp;
// }

// 	Array operator+(const Array &o2) // concatenating two arrays
// 	{
// 		Array temp(size + o2.size);

// 		for (int i = 0; i < size; i++)
// 		{
// 			temp.ptr[i] = this->ptr[i];
// 		}
// 		int j = 0;
// 		for (int i = size; i < temp.size; i++)
// 		{
// 			temp.ptr[i] = o2.ptr[j];
// 			j++;
// 		}

// 		return temp;
// 	}
// };

int main()
{
    system("cls");
    // Array o1(5), o2(7);

    // Array res = o1 + o2;

    // res.print();

    Player p1(10, 20), p2(40, 50);
    cout << p1 << p2;

    // Player res = p1 + p2;
    // res.operator<<(cout);
    // res << cout; // res.operator<<(cout)

    // cout << res;
    // res << cout;
}