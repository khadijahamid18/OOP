#include <iostream>
#include <string>
using namespace std;
#define SIZE 50
void letterPerWord(const char *str)
{
    int count = 0;
    int space = 0;

    // for (int i = 0; str[i] != '\0'; i++)
    // {
    //     if (str[i] == ' ')
    //     {
    //         space++;
    //     }
    // }

    // cout << endl << "Space: " << space << endl;
    // cout << "Count : " << count << endl;

    cout << "Words " << "\t\t\t" << "Number of character" << endl;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            count++;
            cout << str[i];
        }
        else if (str[i] == ' ' || str[i] == '\0')
        {
            cout << "\t\t\t" << count << "\t\t\t" << endl;
            count = 0;
        }
        
    }
    cout << "\t\t\t" << count  << endl;
    
    
}

int main()
{
    system("cls");
    string str;

    cout << "Please enter any string(max length 50): " << endl;

    getline(cin, str);
    cout << str << endl;

    letterPerWord(&str[0]);

    return 0;
}