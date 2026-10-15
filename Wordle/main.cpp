#include <iostream>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define DEFAULT "\033[0m"

using namespace std;

int main()
{
	const char word[] = "TABLE";

	char guess[6];
	cin >> guess;

	cout << guess;

	return 0;
}