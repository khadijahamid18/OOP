#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    system("cls");
    ofstream outf("testt.txt");
    int id = 0;
    float cgpa = 0.0;
    cout << "Enter id and cgpa: ";

    while (cin >> id >> cgpa)
    {
        outf << id << " " << cgpa << endl;
    }

    return 0;
}