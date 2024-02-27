#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    system("cls");
    ifstream inf("input.txt");

    int id = 0;
    float cgpa = 0.0;

    if (!inf)
    {
        cout << "File opening failed!" << endl;
        exit(0);
    }

    inf >> id >> cgpa; 
    while (!inf.eof())
    {
        cout << "ID " << "\t" << "CGPA " << endl;
        inf >> id >> cgpa;
    }

    inf.close();
    
    return 0;
}