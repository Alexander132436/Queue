#include <iostream>
#include "Printer.h"
using namespace std;

int  main() 
{
	srand(time(0));
	int size = 5;
	Printer a(5);
	std::string* arr = new std::string[size]{ "Nastya","Sergey","Roman","Ira","Pavel" };
	for (int i = 0; i < size; i++) 
	{
		a.add(arr[i], rand() % 5 + 1, rand() % 23,rand() % 60,rand() % 60);
	}
	a.Show();
	a.Extract();
	cout << endl;
	a.Show();

}