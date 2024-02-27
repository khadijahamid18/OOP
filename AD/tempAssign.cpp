#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    T *ptr;
    int size;
    int top;

public:
    // Constructors and Destructor

    // Default Constructors
    Stack()
    {
        size = 5;
        ptr = new T[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = 0;
        }
    }

    // Parameteric Constructor
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->ptr = new T[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = i;
        }
    }

    // Copy Constructor
    Stack(const Stack &obj)
    {
        this->size = obj.size;
        this->top = obj.top;
        for (int i = 0; i < size; i++)
        {
            this->ptr[i] = obj.ptr[i];
        }
    }

    // Destructor
    ~Stack()
    {
        delete[] ptr;
    }

    //  Member Function

    int getSize()
    {
        return top;
    }

    int getTotalSize()
    {
        return size;
    }

    void push(T value)
    {
        if (top == size - 1)
        {
            cout << "Error: Size is full" << endl;
        }
        top++;
        ptr[top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Error: Stack is empty" << endl;
        }
        top--;
    }

    T Top()
    {
        return top;
    }

    bool isEmpty()
    {
        return top = -1;
    }

    void erase()
    {
        delete[] ptr;
        // OR top = -1;
    }

    void reverse()
    {
        T temp;
        int i = 0;
        int j = top;
        while (i < j)
        {
            temp = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = temp;
            i++;
            j--;
        }
    }

    bool operator==(const Stack<T> &obj)
    {
        if (this.size != obj.size || this.top != obj.top)
        {
            return false;
        }
        for (int i = 0; i <= top; i++)
        {
            if (ptr[i] != obj.ptr[i])
            {
                return false;
            }
        }
        return true;
    }

    Stack &operator=(const Stack<T> &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        if (size != obj.size)
        {
            delete[] ptr;
            this->size = obj.size;
            this->ptr = new T[size];
        }
        top = obj.top;
        for (int i = 0; i <= top; i++)
        {
            ptr[i] = obj.ptr[i];
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i];
        }
    }

    friend ostream &operator<<(ostream &out, const Stack &obj);
    friend istream &operator>>(istream &in, const Stack &obj);
    
};

ostream &operator<<(ostream &out, const Stack &obj)
{
    for (int i = 0; i < obj.top; i++)
    {
        out << obj.ptr[i] << endl;
    }
    cout << endl;
    return out;
}

istream &operator>>(istream &in, const Stack &obj)
{
    cout << "Enter the value: ";
    for (int i = 0; i < obj.top; i++)
    {
        in >> obj.ptr[i];
    }
    return in;
}

int main()
{
    system("cls");
    Stack<int> o1(5);
    Stack<int> o2;
    o1.print();
    cout << endl;
    o1.reverse();
    o1.print();

    // o1.push(3);
    // o1.print();

    // o1.pop();
    // o1.print();

    return 0;
}