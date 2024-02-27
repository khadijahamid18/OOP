#include <iostream>

template <class T>
class Stack
{
private:
    T *ptr;   // pointer to dynamic array
    int size; // size of array
    int top;  // current top of stack
public:
    // default constructor
    Stack()
    {
        size = 5;          // default size of 5
        ptr = new T[size]; // allocate memory on heap
        top = -1;          // stack is empty
    }
    // parametric constructor
    Stack(int stackSize)
    {
        size = stackSize;
        ptr = new T[size];
        top = -1;
    }
    // copy constructor
    Stack(const Stack<T> &other)
    {
        size = other.size;
        ptr = new T[size];
        top = other.top;
        for (int i = 0; i <= top; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }
    // destructor
    ~Stack()
    {
        delete[] ptr;
    }
    // get current size of stack
    int getSize() const
    {
        return top + 1;
    }
    // get total size of stack
    int getTotalSize() const
    {
        return size;
    }
    // push an element onto the stack
    void push(T value)
    {
        if (top == size - 1)
        {
            std::cout << "Stack overflow\n";
            return;
        }
        top++;
        ptr[top] = value;
    }
    // pop an element from the top of the stack
    void pop()
    {
        if (top == -1)
        {
            std::cout << "Stack underflow\n";
            return;
        }
        top--;
    }
    // get the element at the top of the stack
    T getTop() const
    {
        if (top == -1)
        {
            std::cout << "Stack is empty\n";
            return T(); // default value of T
        }
        return ptr[top];
    }
    // check if the stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }
    // erase all elements from the stack
    void erase()
    {
        top = -1;
    }
    // reverse the elements in the stack
    void reverse()
    {
        int i = 0, j = top;
        while (i < j)
        {
            T temp = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = temp;
            i++;
            j--;
        }
    }
    // == operator to check if two stacks are equal
    bool operator==(const Stack<T> &other) const
    {
        if (size != other.size || top != other.top)
        {
            return false;
        }
        for (int i = 0; i <= top; i++)
        {
            if (ptr[i] != other.ptr[i])
            {
                return false;
            }
        }
        return true;
    }
    // = operator to assign one stack to another
    void operator=(const Stack<T> &other)
    {
        if (this == &other)
        {
            return;
        }
        if (size != other.size)
        {
            delete[] ptr;
            size = other.size;
            ptr = new T[size];
        }
        top = other.top;
        for (int i = 0; i <= top; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i];
        }
    }
    // << operator to print stack
    // template<typename U>
    // friend std::ostream& operator<<(std::ostream& out, const Stack<U>& stack);
    // // >> operator to take input for stack
    // template
};
int main()
{
    Stack<int> o1(5);
    Stack<int> o2;
    o1.print();
    // cout << endl;
    o1.reverse();
    o1.print();
}