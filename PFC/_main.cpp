#include <iostream>

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
	cout << "[";
	if (c == -1)
	{
		cout << "X";
	}
	else
	{
		cout << c;
	}
	cout << "]";
}

int main()
{
	cout << "Bievenue sur le jeu du Morpion" << endl;

	const int length = 3; // Longueur
	const int width = 3;  // Largeur
	int cell_count = 1;
	int cells[length * width];

	for (int l = 1; l < length+1; l++)
	{
		for (int w = 1; w < width+1; w++)
		{
			cells[cell_count] = cell_count;
			PrintCell(cell_count);
			cell_count++;
		}
		cout << endl;
	}

	while (true)
	{

		cout << "Choisir une case" << endl;
		int index = AskInt(1, 9);
		system("cls");

		
		
	}



	return 0;
}