#include <iostream>
using namespace std;

template <typename T>
class Array
{
    T *data;
    int size;

public:
    // Constructors and Destructors

    // Default constructor
    Array()
    {
        size = 5;
        data = new T[size];
        // Initializing elements to zero
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    // Parameterized Constructor
    Array(T *data, int size)
    {
        this->size = size;
        this->data = new T[size];
        for (int i = 0; i < size; i++)
        {
            this->data[i] = 0;
        }
    }

    // Copy Constructors
    Array(const Array &obj)
    {
        this->size = obj.size;
        this->data = new T[size];
        for (int i = 0; i < size; i++)
        {
            this->data[i] = obj.data[i];
        }
    }

    // Destructor
    ~Array()
    {
        delete[] data;
    }

    // MEMBER FUNCTIONS

    int getSize() const
    {
        return size;
    }

    void setElements(int index, T element)
    {
        for (int i = 0; i < size; i++)
        {
            if (index > 0 || index <= size)
            {
                data[index] = element;
            }
        }
        else
        {
            cout << "Wrong Information given!!!" << endl;
        }
    }

    int coutElements(int count, T key)
    {
        count = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == key)
            {
                count++;
            }
            else if (data[i] != key)
            {
                count = -1;
            }
        }
        return count;
    }

    Array &operator=(const Array &obj)
    {
        if (this != &obj)
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
        }
        return *this;
    }

    Array getSubArray(int start, int end)
    {
        Array temp(end - start + 1);                  // new obj jis mn store krwana usko size dena hy eg: start = 2, end = 5; total = 4
        if (start >= 0 && end >= start && end < size) // temp = 2-5+1 = 4
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

    Array<T> operator+(Array<T> &obj)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->size == obj.size)
            {
                data[i] += obj.data[i];
            }
        }
    }

    Array<T> operator==(Array<T> &obj)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == obj.data[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
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

    template <typename T>
    friend istream &operator>>(istream &in, Array<T> &obj);
};

template <typename T>
ostream &operator<<(ostream &out, const Array<T> &obj)
{
    cout << "Displaying the data: \n";
    for (int i = 0; i < obj.size; i++)
    {
        cout << obj.data[i] << "	";
    }
    return out;
}

template <typename T>
istream &operator>>(istream &in, Array<T> &obj)
{
    cout << "Please enter the data for the array: \n";
    for (int i = 0; i < obj.size; i++)
    {
        in >> obj.data[i];
    }
    cout << endl;
    return in;
}

int main()
{
    system("cls");

    // Array<int> o1(5);

    // Array<int> o2(10), o3(7);

    // o2[5] = 10;
    // cout << o2[5] << endl;

    // cout << o2 << endl;

    /*o1 = o2 = o3;
    cout << o1 << endl;*/

    // cout << o2.getSubArray(2, 11) << endl;

    /*print<int>(10);

    print<string>("ABC");
    print<char>('A');*/

    return 0;
}