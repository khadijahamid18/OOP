#include <iostream>
using namespace std;

/*
 *	Function Overloading can be achieved when atleat one of these 3 conditions is fulfilled
 *	1) No. of arguments are diff
 *	2) Data Types of arguments are diff
 *	3) Arrangement of arguments is diff
 */

template <typename T>
void print(T vale)
{
    cout << vale << endl;
}

template <>
void print(string vale)
{
    cout << vale << " is a string!\n";
}

template <typename T>
class Array
{
    T *data;
    int size;

public:
    Array()
    {
        size = 5;
        data = new T[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    Array(int s)
    {
        size = s;
        data = new T[s];

        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    Array(const Array &obj)
    {
        size = obj.size;
        data = new T[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i];
        }
    }

    ~Array()
    {
        delete[] data;
    }

    int getSize() const
    {
        return size;
    }

    Array &operator=(const Array &obj)
    {
        if (this->size != obj.size)
        {
            delete[] data;
            this->size = obj.size;

            data = new T[size];
        }

        for (int i = 0; i < size; i++)
        {
            this->data[i] = obj.data[i];
        }
        return *this;
    }

    Array getSubArray(int start, int end)
    {
        Array temp(end - start + 1);
        if (start >= 0 && end >= start && end < size)
        {
            for (int i = start, j = 0; i <= end; i++)
            {
                temp.data[j++] = data[i];
            }
            return temp;
        }
        for (int i = 0; i < temp.size; i++)
        {
            temp.data[i] = -1;
        }
        return temp;
    }

    int &operator[](int index)
    {
        return this->data[index];
    }

    int operator[](int index) const
    {
        return this->data[index];
    }

    template <typename T>
    friend ostream &operator<<(ostream &out, const Array<T> &obj);
};

template <typename T>
ostream &operator<<(ostream &out, const Array<T> &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        cout << obj.data[i] << "	";
    }
    return out;
}

int main()
{

    // Array<int> o1(5);

    Array<int> o2(10), o3(7);

    o2[5] = 10;
    cout << o2[5] << endl;

    // cout << o2 << endl;

    /*o1 = o2 = o3;
    cout << o1 << endl;*/

    // cout << o2.getSubArray(2, 11) << endl;

    /*print<int>(10);

    print<string>("ABC");
    print<char>('A');*/

    return 0;
}