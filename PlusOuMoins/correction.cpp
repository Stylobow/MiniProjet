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

void Play()
{
	float nearRatio = 0.1f;
	float farRatio = 0.5f;

	cout << "Choisir une difficulte facile(1), normal(2), difficile(3)" << endl;
	int difficulty = AskInt(1, 3);

	cout << "Indication ?(0: oui, 1: non)" << endl;
	int answerIndication = AskInt(0, 1);

	int max;
	if (difficulty == 1)
	{
		max = 20;
	}
	else if (difficulty == 2)
	{
		max = 100;
	}
	else
	{
		max = 500;
	}

	int mysteryNumber = rand() % (max + 1);
	cout << "Choisir un nombre entre 0 et " << max << " :";

	int guess;
	int tries = 0;
	int maxTries = 10;
	while (true)
	{
		guess = AskInt(0, max);
		tries++;

		if (mysteryNumber == guess)
		{
			cout << "Bravo !" << tries << " essais" << endl;
			break;
		}

		cout << "C'est ";

		if (answerIndication == 0)
		{
			int distance = mysteryNumber - guess;
			if (distance < 0)
				distance *= -1;

			float ratio = distance / (float)(max + 1);

			if (ratio >= farRatio)
			{
				cout << "beaucoup ";
			}
			else if (ratio <= nearRatio)
			{
				cout << "un peu ";
			}
		}

		if (mysteryNumber < guess)
		{
			cout << "moins !" << endl;
		}
		else
		{
			cout << "plus !" << endl;
		}

		maxTries--;
		if (maxTries == 0)
		{
			cout << "Perdu" << endl;
			break;
		}

		cout << maxTries << " essais restants" << endl;
	}
}

int main()
{
	srand(time(NULL));

	cout << "Bienvenue dans le jeu du plus ou moins" << endl;

	while (true)
	{
		Play();

		cout << "recommencer ? (1: oui, 2: non)" << endl;
		int answer = AskInt(1, 2);
		if (answer == 2)
			break;
	}

	return 0;
}