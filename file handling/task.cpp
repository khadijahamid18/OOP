#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    system("cls");
    ofstream outf("test.txt"); 
    if(!outf)
    {
        cerr << "File creation failed!" << endl;
        exit(0);
    }
    // cout << "Ok" << endl;
    outf << "Hello Khadija" << endl;
     


    outf.close();
    return 0;
}