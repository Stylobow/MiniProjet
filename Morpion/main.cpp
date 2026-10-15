#include <iostream>
#include <conio.h>

#define DEFAULT "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

const int SIZE = 3; // Nombre de lignes et de colonnes
const int CELLS = SIZE * SIZE; // Nombre total de cellules

using namespace std;

void PrintCell(int c, bool isSelected)
{
	cout << YELLOW << "[ ";
	if (c == 1)
	{
		cout << RED << (isSelected ? "@" : "X");
	}
	else if (c == 2)
	{
		cout << BLUE << (isSelected ? "@" : "O");
	}
	else
	{
		if (isSelected)
		{
			cout << CYAN "@";
		}
		else {
			cout << GREEN "-";
		}
	}
	cout << YELLOW << " ] " DEFAULT;
}

bool CheckWin(const int cells[CELLS], int playerSymbol)
{
	/*Test Grille 4x4
	ROW	1	  2     3     4
COL	1 [ 0 ] [ 1 ] [ 2 ] [ 3 ]
	2 [ 4 ] [ 5 ] [ 6 ] [ 7 ]
	3 [ 8 ] [ 9 ] [ 10] [ 11]
	4 [ 12] [ 13] [ 14] [ 15]

	Diagonales gauche : Verifier coin haut gauche � coin bas droit
	[i * SIZE + i]
	i = 0 -> 0 * 4 + 0 = 0
	i = 1 -> 1 * 4 + 1 = 5
	i = 2 -> 2 * 4 + 2 = 10
	i = 3 -> 3 * 4 + 3 = 15

	Diagonales droite : Verifier coin haut droite � coin bas gauche
	[i * SIZE + (SIZE - 1 - i)]
	i = 0 -> 0 * 4 + (4 - 1 - 0) = 3
	i = 1 -> 1 * 4 + (4 - 1 - 1) = 6
	i = 2 -> 2 * 4 + (4 - 1 - 2) = 9
	i = 3 -> 3 * 4 + (4 - 1 - 3) = 12
	*/


	// Verification Lignes
	for (int row = 0; row < SIZE; row++)
	{
		bool win = true;
		for (int col = 0; col < SIZE; col++)
		{
			if (cells[row * SIZE + col] != playerSymbol)
			{
				win = false;
				break;
			}
		}
		if (win) return true;
	}

	// Verification Colonnes
	for (int col = 0; col < SIZE; col++)
	{
		bool win = true;
		for (int row = 0; row < SIZE; row++)
		{
			if (cells[row * SIZE + col] != playerSymbol)
			{
				win = false;
				break;
			}
		}
		if (win) return true;
	}

	// Verification Diagonale 1
	bool winDiag1 = true;
	for (int i = 0; i < SIZE; i++)
	{
		if (cells[i * SIZE + i] != playerSymbol)
		{
			winDiag1 = false;
			break;
		}
	}
	if (winDiag1) return true;

	// Verification Diagonale 2
	bool winDiag2 = true;
	for (int i = 0; i < SIZE; i++)
	{
		if (cells[i * SIZE + (SIZE - 1 - i)] != playerSymbol)
		{
			winDiag2 = false;
			break;
		}
	}
	if (winDiag2) return true;

	return false;
}

void AI_Play(int cells[CELLS], int aiPlayer)
{
	int opponent = 3 - aiPlayer;

	for (int i = 0; i < CELLS; i++)
	{
		if (cells[i] == 0)
		{
			cells[i] = aiPlayer;
			if (CheckWin(cells, aiPlayer))
				return;

			cells[i] = 0;
		}
	}

	for (int i = 0; i < CELLS; i++)
	{
		if (cells[i] == 0)
		{
			cells[i] = opponent;
			if (CheckWin(cells, opponent))
			{
				cells[i] = aiPlayer;
				return;
			}
			cells[i] = 0;
		}
	}

	int index;
	do {
		index = rand() % CELLS;
	} while (cells[index] != 0);

	cells[index] = aiPlayer;
}

bool IsGameFull(int cells[CELLS])
{
	for (int i = 0; i < CELLS; i++)
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
	int selectedCell = 0;

	while (true)
	{
		int lastPlayer = 3 - currentPlayer;
		if (CheckWin(cells, lastPlayer)) {
			system("cls");
			cout << "=== FIN DE PARTIE ===" << endl << endl;
			for (int i = 0; i < CELLS; i++)
			{
				PrintCell(cells[i], false);
				if ((i + 1) % SIZE == 0) cout << endl;
			}
			cout << endl << (lastPlayer == 1 ? RED "Le Joueur 1 (X) a gagne !" : BLUE "Le Joueur 2 (O) a gagne !") << DEFAULT << endl;
			break;
		}

		if (IsGameFull(cells))
		{
			system("cls");
			cout << "=== FIN DE PARTIE ===" << endl << endl;
			for (int i = 0; i < CELLS; i++)
			{
				PrintCell(cells[i], false);
				if ((i + 1) % SIZE == 0) cout << endl;
			}
			cout << endl << YELLOW "Match nul !" DEFAULT << endl;
			break;
		}

		if (currentPlayer == 1)
		{
			int row = selectedCell / SIZE;
			int col = selectedCell % SIZE;
			bool validated = false;

			while (!validated)
			{
				system("cls");
				cout << "Bienvenue sur le jeu du Morpion" << endl;
				cout << "Deplacez-vous avec les fleches, puis appuyez sur ENTREE pour valider." << endl << endl;
				cout << "Tour du Joueur : " << (currentPlayer == 1 ? RED "Rouge (X)" : BLUE "Bleu (O)") << DEFAULT << endl;

				for (int i = 0; i < CELLS; i++)
				{
					PrintCell(cells[i], selectedCell == i);
					if ((i + 1) % SIZE == 0)
					{
						cout << endl;
					}
				}

				int key = _getch();

				if (key == 0 || key == 224)
				{
					key = _getch();
					switch (key)
					{
					case 72: // Flèche Haut
						if (row > 0) row--;
						break;
					case 80: // Flèche Bas
						if (row < SIZE - 1) row++;
						break;
					case 75: // Flèche Gauche
						if (col > 0) col--;
						break;
					case 77: // Flèche Droite
						if (col < SIZE - 1) col++;
						break;
					}
					selectedCell = row * SIZE + col;
				}
				else if (key == 13)
				{
					if (cells[selectedCell] != 0)
					{
						cout << endl << RED "Case deja prise !" DEFAULT;
						_getch();
					}
					else
					{
						cells[selectedCell] = currentPlayer;
						validated = true;
					}
				}
			}
		}
		else
		{
			AI_Play(cells, currentPlayer);
		}

		currentPlayer = 3 - currentPlayer;
	}

	return 0;
}