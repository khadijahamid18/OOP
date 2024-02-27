template <typename T>
class Stack
{
private:
    T *ptr;
    int size;
    int top;

public:
    Stack() : size(5), top(-1)
    {
        ptr = new T[size];
        memset(ptr, 0, sizeof(T) * size);
    }
    Stack(int stackSize) : size(stackSize), top(-1)
    {
        ptr = new T[size];
        memset(ptr, 0, sizeof(T) * size);
    }
    Stack(const Stack &other) : size(other.size), top(other.top)
    {
        ptr = new T[size];
        memcpy(ptr, other.ptr, sizeof(T) * size);
    }
    ~Stack()
    {
        delete[] ptr;
    }
    int getSize() const
    {
        return top + 1;
    }
    int getTotalSize() const
    {
        return size;
    }
    void push(T value)
    {
        if (top == size - 1)
        {
            T *newPtr = new T[size * 2];
            memcpy(newPtr, ptr, sizeof(T) * size);
            size *= 2;
            delete[] ptr;
            ptr = newPtr;
        }
        ptr[++top] = value;
    }
    void pop()
    {
        if (top < 0)
        {
            throw std::underflow_error("Stack underflow");
        }
        top--;
    }
    T topValue() const
    {
        if (top < 0)
        {
            throw std::underflow_error("Stack underflow");
        }
        return ptr[top];
    }
    bool isEmpty() const
    {
        return top == -1;
    }
    void erase()
    {
        top = -1;
    }
    void reverse()
    {
        std::reverse(ptr, ptr + top + 1);
    }
    bool operator==(const Stack &other) const
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
    Stack &operator=(const Stack &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] ptr;
        size = other.size;
        top = other.top;
        ptr = new T[size];
        memcpy(ptr, other.ptr, sizeof(T) * size);
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const Stack &stack)
    {
        out << "[ ";
        for (int i = 0; i <= stack.top; i++)
        {
            out << stack.ptr[i] << " ";
        }
        out << "]";
        return out;
    }
    friend std::istream &operator>>(std::istream &in, Stack &stack)
    {
        T value;
        in >> value;
        stack.push(value);
        return in;
    }
};
