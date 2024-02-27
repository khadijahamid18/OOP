#include <iostream>
#include <string>

using namespace std;

char *reverseCase(const char *str)
{
    char *rev = new char[50];

    if (str == NULL)
    {
        cout << "String is empty";
    }
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            rev[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            rev[i] = str[i] + 32;
        }
        else
        {
            rev[i] = str[i];
        }
    }
    rev[i] = '\0';

    return rev;
}
int main()
{
    system("cls");
    string str;
    cout << "Enter any string: ";
    getline(cin, str);

    char *p = reverseCase(&str[0]);

    cout << p;

    delete p;

    return 0;
}