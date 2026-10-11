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
	cout << YELLOW << " ] ";
}

int CheckWin(int cells[9])
{
	int wins[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Horizontal
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Vertical
		{0, 4, 8}, {2, 4, 6}			 // Diagonale
	};

	for (int i = 0; i < 8; i++)
	{
		if (cells[wins[i][0]] != 0 && cells[wins[i][0]] == cells[wins[i][1]] && cells[wins[i][0]] == cells[wins[i][2]])
		{
			return cells[wins[i][0]];
		}
	}
	return 0;
}

bool IsGameFull(int cells[9])
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
	int currentPlayer = 1;

	int cells[9] = { 0 }; // 0 = Vide | 1 = Joueur1 (X) | 2 = Joueur2 (O)

	while (true)
	{
		system("cls");
		cout << "Bievenue sur le jeu du Morpion" << endl;
		cout << "Tour du Joueur : " << (currentPlayer == 1 ? RED "Rouge (X)" : BLUE "Bleu (O)") << DEFAULT << endl;

		for (int i = 0; i < 9; i++)
		{
			PrintCell(cells[i], i + 1);
			if ((i + 1) % 3 == 0)
			{
				cout << endl;
			}
		}

		int winner = CheckWin(cells);
		
		if (winner != 0)
		{
			cout << endl << (winner == 1 ? DEFAULT "Le " RED "Joueur 1 (X) " DEFAULT "a gagne la partie !" : DEFAULT "Le " BLUE "Joueur 2 (O)" DEFAULT "a gagne la partie !") << DEFAULT << endl;
			break;
		}

		if (IsGameFull(cells)) 
		{
			cout << endl << YELLOW "Match nul !" DEFAULT << endl;
			break;
		}

		cout << endl << DEFAULT "Choisisez une case : " << endl;
		
		cout << "Ligne (1-3) : ";
		int row = AskInt(1, 3);

		cout << "Colonne (1-3) :";
		int col = AskInt(1, 3);

		int index = (row - 1) * 3 + (col - 1);

		if (cells[index] != 0)
		{
			cout << RED "Cette case est deja prise ! Veuillez en choisir une autre : " DEFAULT;
			cin.ignore();
			cin.get();
			continue;
		}

		cells[index] = currentPlayer;

		currentPlayer = 3 - currentPlayer;

	}

	return 0;
}