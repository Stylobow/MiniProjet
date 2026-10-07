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
		int round = 0;
		int maxPoints = 3;

		int playerScore = 0;
		int botScore = 0;

		while (true) {
			if (playerScore >= maxPoints || botScore >= maxPoints) break;
			round++;
			cout << "Pierre: 1 | Feuille: 2 | Ciseaux: 3" << endl;
			int playerChoice = AskInt(1, 3);
			int botChoice = (rand() % 3) + 1;

			PrintChoice(playerChoice);
			cout << " VS ";
			PrintChoice(botChoice);
			cout << endl;

			if (playerChoice == 1)
			{
				if (botChoice == 1)
				{
					cout << "Egalite" << endl;
				}
				else if (botChoice == 2) {
					cout << "Perdu" << endl;
					botScore++;
				}
				else {
					cout << "Gagne" << endl;
					playerScore++;
				}
			}
			else if (playerChoice == 2)
			{
				if (botChoice == 1)
				{
					cout << "Gagne" << endl;
					playerScore++;
				}
				else if (botChoice == 2) {
					cout << "Egalite" << endl;
				}
				else {
					cout << "Perdu" << endl;
					botScore++;
				}
			}
			else
			{
				if (botChoice == 1)
				{
					cout << "Perdu" << endl;
					botScore++;
				}
				else if (botChoice == 2) {
					cout << "Gagne" << endl;
					playerScore++;
				}
				else {
					cout << "Egalite" << endl;
				}
			}
		}
		cout << "Joueur : " << playerScore << " | " << botScore << " Bot" << endl;
		if (playerScore >= maxPoints) {
			cout << "Vous avez gagne" << endl;
		}
		else {
			cout << "Vous avez perdu." << endl;
		}
		cout << "Voulez-vous recommencer ? (Oui: 1 | Non: 2)";
		int restart;
		cin >> restart;
		if (!restart) { break; };
	}

	return 0;
}