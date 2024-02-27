#include <iostream>
using namespace std;

class Collection
{
    int *data;
    int size;

public:
    // Constructors AND Destructors

    Collection(int size)
    {
        this->size = size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->data[i] = 0;
        }
    }

    Collection(int *arr, int size)
    {
        this->size = size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = arr[i];
        }
    }

    Collection(const Collection &obj)
    {
        this->size = obj.size;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->data[i] = obj.data[i];
        }
    }

    ~Collection()
    {
        delete[] data;
    }

    // Member Fuction

    int getSize()
    {
        return size;
    }

    void setElement(int i, int k)
    {
        if (i >= 0 && i < size)
        {
            data[i] = k;
        }
        else
        {
            cout << "Sorry the element not found!" << endl;
        }
    }

    int countElement(int key)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == key)
            {
                count++;
            }
        }
        return count;
    }

    Collection operator=(const Collection &obj)
    {
        if (this != &obj) // self assignment check for better practice
        {
            if (this->size != obj.size)
            {
                delete[] data;
                this->size = obj.size; // updating LHS' object's size
                data = new int[size];
            }
            for (int i = 0; i < size; i++)
            {
                this->data[i] = obj.data[i];
            }
        }
        return *this;
    }

    Collection getSubCollection(int start_index, int end_index)
    {
        Collection temp(end_index - start_index + 1);                         // new obj jis mn store krwana usko size dena hy eg: start = 2, end = 5; total = 4
        if (start_index >= 0 && end_index >= start_index && end_index < size) // temp = 5-2+1 = 4
        {
            for (int i = start_index, j = 0; i <= end_index; i++)
            {
                temp.data[j++] = data[i];
            }
            return temp;
        }
        else
        {
            cout << "Sorry not possible" << endl;
            delete[] temp.data;
            temp.data = NULL;
            temp.size = 0;
        }
        return temp;
    }

    Collection operator+(const Collection &obj)
    {
        if (this->size != obj.size)
        {
            cout << "Sorry addition is not possible!" << endl;
            Collection temp(0);
            temp.data = NULL;
            return temp;
        }
        else if (this->size == obj.size)
        {
            Collection temp(size);
            for (int i = 0; i < size; i++)
            {
                temp[i] = this->data[i] + obj.data[i];
            }
            return temp;
        }
    }

    int &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else
        {
            cout << "Sorry, index is out of bound!" << endl;
            static int i = 99; // static ta k life global ho but scope local hi hy
            return i;
        }
    }

    int operator[](int index) const
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else
        {
            cout << "Sorry, index is out of bound!" << endl;
            static int i = 99;
            return i;
        }
    }

    bool operator-(const Collection &obj)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] > 0)
            {
                return false;
            }
        }
        return true;
    }

    friend ostream &operator<<(ostream &out, const Collection &obj);
    friend istream &operator>>(istream &in, const Collection &obj);
};

ostream &operator<<(ostream &out, const Collection &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        out << obj.data[i] << endl;
    }
    cout << endl;
    return out;
}

istream &operator>>(istream &in, const Collection &obj)
{
    cout << "Enter the elements of the array: " << endl;
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
    int arr[7] = {1, 2, 3, 4, 3, 5, 3};
    Collection c2(arr, 7);
    Collection c1[] = {Collection(arr, 7), Collection(c2[0]), Collection(6)};
    //  cin >> c2;
    //  cout < c2;
    //  c2.setElement(2, 6);

    // cout << c2;
    cout << c1->countElement(3);
    // cout << c1->getSubCollection(1, 5);
    //  c2.getSubCollection(1, 5);
    //  cout << c2;

    return 0;
}