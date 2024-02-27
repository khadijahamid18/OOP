#include "iostream"

using namespace std;

//Funcion template to add two number
template<class t>
t add(t value1, t value2)
{
	return value1 + value2;
}
//----------------------------------------------------------------//

//Function template with two unknowns
template<class t1, class t2>
t1 multiply(t1 a, t2 b)
{
	return a * b;
}
//----------------------------------------------------------------//

//Function template to display array's content
template<typename arrayType>
void printArray(const arrayType ar[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << "\t";
	}

	cout << endl;
}
//----------------------------------------------------------------//

int main()
{
	cout << add(1, 2) << endl;				//automatically identify the datatype of parameters (int)
	cout << add<float>(1.1f, 2.2f) << endl;
	cout << add<char>('a', 'b') << endl;

	//add(1, 1.2f);		Error

	cout << add<float>(1, 1.2f) << endl;	//will work
	//-------------------------------------------------------------//

	cout << multiply(3.2f, 2) << endl;		//automatically identify the datatype of parameters (float, int)
	cout << multiply<float, int>(3.2f, 4) << endl;
	//----------------------------------------------------------------//

	int i_array[] = { 1, 2, 3, 4, 5 };

	printArray(i_array, sizeof(i_array) / sizeof(int));

	float f_array[] = { 1.1f, 2.2f, 3.3f };

	printArray(f_array, sizeof(f_array) / sizeof(float));

	char c_array[] = { 'A', 'B', 'C', 'D' };

	printArray<char>(c_array, sizeof(c_array) / sizeof(char));

	return 0;
}