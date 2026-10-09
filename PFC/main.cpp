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

void PrintChoice(int index)
{
	if (index == 1)
	{
		cout << "Pierre";
	}
	else if (index == 2)
	{
		cout << "Feuille";
	}
	else
	{
		cout << "Ciseaux";
	}
}

int main()
{
	srand(time(NULL));

	cout << "Bienvenue sur le jeu du Pierre Feuille Ciseaux" << endl;


	while (true) {
		int victory = 0;
		int defeat = 0;
		int draw = 0;

		int round = 0;
		int maxRound = 3;
		int maxPoints = 3;
		int ecartPoints = 2;

		int playerScore = 0;
		int botScore = 0;

		while (round < maxRound) {
			int ecart = abs(playerScore - botScore);
			if ((playerScore >= maxPoints && ecart >= ecartPoints) || (botScore >= maxPoints && ecart >= ecartPoints)) break;
			round++;
			cout << "Pierre: 1 | Feuille: 2 | Ciseaux: 3" << endl;
			int playerChoice = AskInt(1, 3);
			int botChoice = (rand() % 3) + 1;

			PrintChoice(playerChoice);
			cout << " VS ";
			PrintChoice(botChoice);
			cout << endl;

			if ((playerChoice == 1 && botChoice == 3) || (playerChoice == 2 && botChoice == 1) || (playerChoice == 3 && botChoice == 2))
			{
				cout << "Gagne" << endl;
				playerScore++;
				victory++;
			}
			else if (playerChoice == botChoice) {
				cout << "Egalite" << endl;
				draw++;
			}
			else {
				cout << "Perdu" << endl;
				botScore++;
			}
		}
		cout << "Joueur : " << playerScore << " | " << botScore << " Bot" << endl;
		if (playerScore >= maxPoints) {
			cout << "Vous avez gagne" << endl;
		}
		else {
			cout << "Vous avez perdu." << endl;
		}
	}

	return 0;
}