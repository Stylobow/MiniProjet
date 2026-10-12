#include <iostream>

#define DEFAULT "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

const int SIZE = 4; //Nombre de lignes et de colonnes
const int CELLS = SIZE * SIZE; //Nombre total de celules 

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

void PrintCell(int c, int cellNumber)
{
	cout << YELLOW << "[ ";
	if (c == 1)
	{
		cout << RED "X";
	}
	else if (c == 2)
	{
		cout << BLUE "O";
	}
	else
	{
		cout << GREEN "-";
	}
	cout << YELLOW << " ] " DEFAULT;
}

bool CheckWin()
{
	int cells[CELLS];

	for (int i = 0; i < (SIZE * SIZE); i++)
	{
		int index = i * 3;

		if ((cells[index] == 1 || cells[index] == 2) && cells[index] == cells[index + 1] && cells[index] == cells[index + 2])
		{
			return true;
		}
	}
	return false;
}

bool IsGameFull(int cells[CELLS])
{
	for (int i = 0; i < 9; i++)
	{
		if (cells[i] == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	srand(time(NULL));

	int currentPlayer = 1;

	int cells[CELLS] = { 0 }; // 0 = Vide | 1 = Joueur1 (X) | 2 = Joueur2 (O)

	while (true)
	{
		system("cls");
		cout << "Bievenue sur le jeu du Morpion" << endl;
		cout << "Tour du Joueur : " << (currentPlayer == 1 ? RED "Rouge (X)" : BLUE "Bleu (O)") << DEFAULT << endl;

		for (int i = 0; i < CELLS; i++)
		{
			PrintCell(cells[i], i + 1);
			if ((i + 1) % SIZE == 0)
			{
				cout << endl;
			}
		}

		if (CheckWin) {
			cout << RED "Partie fini" DEFAULT;
			break;
		}

		/*
	if (winner != 0)
	{
		cout << endl << (winner == 1 ? DEFAULT "Le " RED "Joueur 1 (X) " DEFAULT "a gagne la partie !" : DEFAULT "Le " BLUE "Joueur 2 (O) " DEFAULT "a gagne la partie !") << DEFAULT << endl;
		break;
	}*/

		if (IsGameFull(cells))
		{
			cout << endl << YELLOW "Match nul !" DEFAULT << endl;
			break;
		}

		if (currentPlayer == 1)
		{
			cout << endl << DEFAULT "C'est a vous de jouer :" << endl;

			cout << "Ligne (1-" << SIZE << ") : ";
			int row = AskInt(1, SIZE);

			cout << "Colonne (1-" << SIZE << ") : ";
			int col = AskInt(1, SIZE);

			int index = (row - 1) * SIZE + (col - 1);

			if (cells[index] != 0)
			{
				cout << RED "Cette case est deja prise ! Veuillez en choisir une autre : " DEFAULT;
				cin.ignore();
				cin.get();
				continue;
			}

			cells[index] = currentPlayer;
		}
		else {
			int index;

			do
			{
				index = rand() % CELLS;
			} while (cells[index] != 0);

			cells[index] = currentPlayer;
		}

		currentPlayer = 3 - currentPlayer;
	}

	return 0;
}