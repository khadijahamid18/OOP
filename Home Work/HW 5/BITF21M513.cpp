#include <iostream>
using namespace std;

class IntegerSet
{
    int *pointer;
    const int size;

public:
    // Constructors and Destructors

    IntegerSet(int s) : size(s)
    {
        this->pointer = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->pointer[i] = 0;
        }
    }

    IntegerSet(const IntegerSet &obj) : size(obj.size)
    {
        this->pointer = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->pointer[i] = obj.pointer[i];
        }
    }

    ~IntegerSet()
    {
        delete[] pointer;
    }

    // Operators

    IntegerSet operator=(const IntegerSet &obj)
    {
        if (this != &obj)
        {
            if (this->size == obj.size)
            {
                for (int i = 0; i < size; i++)
                {
                    this->pointer[i] = obj.pointer[i];
                }
            }
        }
        return *this;
    }

    bool operator==(const IntegerSet &obj)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->pointer[i] != obj.pointer[i])
            {
                return false;
            }
        }

        return true;
    }

    IntegerSet operator!()
    {
        IntegerSet newSet(size);
        for (int i = 0; i < size; i++)
        {
            newSet.pointer[i] = (pointer[i] == 1) ? 0 : 1; //! pointer[i]
        }
        return newSet;
    }

    // Member Functions

    void insertElement(int k)
    {
        if (k >= 0 && k < size)
        {
            pointer[k] = 1;
        }
        else
            cout << k << " Cannot be inserted in this set!\n";
    }

    void deleteElement(int k)
    {
        if (k >= 0 && k < size)
        {
            pointer[k] = 0;
        }
        else
            cout << k << " Cannot be deleted from this set!\n";
    }

    IntegerSet unionOfSets(const IntegerSet &s2)
    {
        IntegerSet newSet(size);
        for (int i = 0; i < size; i++)
        {
            if (pointer[i] == 1 || s2.pointer[i] == 1)
            {
                newSet.pointer[i] = 1;
            }
            else
            {
                newSet.pointer[i] = 0;
            }
        }
        return newSet;
    }

    IntegerSet intersectionOfSets(const IntegerSet &s2)
    {
        IntegerSet newSet(size);
        for (int i = 0; i < size; i++)
        {
            if (pointer[i] == 1 && s2.pointer[i] == 1)
            {
                newSet.pointer[i] = 1;
            }
            else
            {
                newSet.pointer[i] = 0;
            }
        }
        return newSet;
    }

    bool findElement(int key)
    {
        if (key >= 0 && key < size)
        {
            if (pointer[key] == 1)
            {
                return true;
            }
        }
        cout << "Sorry the value does not exist in the set!" << endl;
        return false;
    }

    friend ostream &operator<<(ostream &out, const IntegerSet &obj);
};

ostream &operator<<(ostream &out, const IntegerSet &obj)
{
    bool flag = true;
    for (int i = 0; i < obj.size; i++)
    {
        if (obj.pointer[i] == 1)
        {
            flag = false;
            out << i << " ";
        }
    }
    cout << endl;
    if (obj.size == 0 || flag == true)
    {
        out << "- - -" << endl;
    }

    return out;
}

int main()
{
    system("clear");
    IntegerSet s1(6);
    IntegerSet s2(6);

    s1.insertElement(3);
    s1.insertElement(2);
    s1.insertElement(5);
    s1.deleteElement(3); 
    cout << s1;

    s2.insertElement(1);
    s2.insertElement(4);
    s2.insertElement(5);
    cout << s2;

    IntegerSet s3 = s1.unionOfSets(s2);
    cout << "Unoin of sets: " << s3 << endl;

    IntegerSet s4 = s1.intersectionOfSets(s2);
    cout << "Intersection of sets: " << s4 << endl;

    bool s5 = s1.findElement(2);
    cout << "Finding Element: " << s5 << endl;

    return 0;
}