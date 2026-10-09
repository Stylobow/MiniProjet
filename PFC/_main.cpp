#include <iostream>

#define DEFAULT "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

using namespace std;

int AskInt(int min, int max)
{
	int value;
	while (true)
	{
		cin >> value;
		if (value >= min && value <= max)
			break;

		cout << "Erreur saisie" << endl;
	}

	return value;
}

void PrintCell(int c)
{
	cout << YELLOW << "[ ";
	if (c == -1)
	{
		cout << RED << "X";
	}
	else
	{
		cout << GREEN << c;
	}
	cout << YELLOW << " ] ";
}

int main()
{
	int cells[9];
	int index = 0;

	for (int i = 0; i < 9 + 1; i++)
	{
		cells[i] = i + 1;
	}

	while (true)
	{
		cout << "Bievenue sur le jeu du Morpion" << endl;
		for (int i = 0; i < 9; i++)
		{
			PrintCell(cells[i]);
			if ((i + 1 )% 3 == 0)
			{
				cout << endl;
			}
		}

		cout << DEFAULT << "Choisir une case" << endl;
		int index = AskInt(1, 9);
		system("cls");

		cells[index - 1] = -1;

	}

	return 0;
}