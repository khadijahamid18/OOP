#include <iostream>
using namespace std;

class Collection
{
    int *data;
    int size;

public:
    Collection()
    {
        this->size = 0;
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    Collection(int s)
    {
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            this->data[i] = 0;
        }
    }

    Collection(const Collection &obj)
    {
        this->size = obj.size;
        for (int i = 0; i < size; i++)
        {
            this->data[i] = obj.data[i];
        }
    }

    Collection(int* arr, int s)
    {
        this->size = s;
        for (int i = 0; i < size; i++)
        {
            this->data[i] = arr[i];
        }
        
    }

    ~Collection()
    {
        delete [] data;
    }

    
};

int main()
{
    system("cls");

    return 0;
}