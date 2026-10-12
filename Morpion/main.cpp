#include <iostream>

#define DEFAULT "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

const int SIZE = 8; // Nombre de lignes et de colonnes
const int CELLS = SIZE * SIZE; // Nombre total de celules 

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

bool CheckWin(const int cells[CELLS], int playerSymbol)
{
	/*Test Grille 4x4
	ROW	1	  2     3     4
COL	1 [ 0 ] [ 1 ] [ 2 ] [ 3 ]
	2 [ 4 ] [ 5 ] [ 6 ] [ 7 ]
	3 [ 8 ] [ 9 ] [ 10] [ 11]
	4 [ 12] [ 13] [ 14] [ 15]

	Diagonales gauche : Verifier coin haut gauche à coin bas droit
	[i * SIZE + i]
	i = 0 -> 0 * 4 + 0 = 0
	i = 1 -> 1 * 4 + 1 = 5
	i = 2 -> 2 * 4 + 2 = 10
	i = 3 -> 3 * 4 + 3 = 15

	Diagonales droite : Verifier coin haut droite à coin bas gauche
	[i * SIZE + (SIZE - 1 - i)]
	i = 0 -> 0 * 4 + (4 - 1 - 0) = 3 
	i = 1 -> 1 * 4 + (4 - 1 - 1) = 6
	i = 2 -> 2 * 4 + (4 - 1 - 2) = 9
	i = 3 -> 3 * 4 + (4 - 1 - 3) = 12
	*/

	//Verifiction Lignes
	for (int row = 0; row < SIZE; row++)
	{
		bool win = true;
		for (int col = 0; col < SIZE; col++)
		{
			if (cells[row * SIZE + col] != playerSymbol) // Mauvais Symbole
			{
				win = false;
				break;
			}
		}
		if (win) return true;
	}

	//Verification Collones
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

	//Verification Diagonales
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

		int lastPlayer = 3 - currentPlayer;
		if (CheckWin(cells, lastPlayer)) {
			cout << endl << (lastPlayer == 1 ? RED "Le Joueur 1 (X) a gagne la partie !" : BLUE "Le Joueur 2 (O) a gagne la partie !") << DEFAULT << endl;
			break;
		}

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