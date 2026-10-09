#include <iostream>
using namespace std;

int main()
{
	const int vars = 100;
	int tab[vars];

	for (int i = 0; i < vars; i++)
	{ 
		tab[i] = i;
		cout << tab[i] << endl;
	}

	return 0;
}