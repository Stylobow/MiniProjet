#include <iostream>

using namespace std;

void Secure_var(int& var, int min, int max) {
	while (!(cin >> var) || var < min || var > max) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Une erreur est survenue, veuillez resaisir votre valeur : ";
	}
}

int Start() {
	system("cls");
	int indication = 0; // Oui : 1 | Non : 0
	int difficulty = 0; // Facile : 0 | Normal : 1 | Difficile : 2
	int hotncold = 0;   // Oui : 1 | Non : 0

	int max_attempts = 10;
	int left_attempts = max_attempts;
	int current_attempts = 0;

	int max_random;
	int guess = 0;

	cout << "Bienvenue dans le jeu du Plus ou Moins." << endl;
	cout << "Dans quel mode de jeu voulez-vous jouer ? (Facile: 0 - Normal : 1 - Difficile : 2) -> ";
	Secure_var(difficulty, 0, 2);

	if (difficulty == 0) {
		max_random = 20;
	}
	else if (difficulty == 1) {
		max_random = 100;
	}
	else if (difficulty == 2) {
		max_random = 500;
	}
	else {
		max_random = 100;
	}

	cout << "Voulez-vous activer le mode de jeu Chaud et Froid ? (Oui: 1 - Non: 0) -> ";
	Secure_var(hotncold, 0, 1);

	if (!hotncold) {
		cout << "Voulez-vous activer les indications de distance ? (Oui: 1 - Non: 0) -> ";
		Secure_var(indication, 0, 1);
	}

	cout << "Vous avez " << max_attempts << " essaies pour trouver le chiffre aleatoire entre 0 et " << max_random << "." << endl;
	cout << "Choisisez un nombre: ";

	int target = rand() % max_random + 1;

	while (true) {
		int restart;

		Secure_var(guess, 0, 500);
		if (left_attempts > 1) {

			string distance;
			string temperature;
			int ecart = abs(guess - target);

			int last_guess = 0;
			int temp_ecart = (guess - last_guess);

			if (indication) {
				if (ecart >= 20) {
					distance = " beaucoup ";
				}
				else {
					distance = " un peu ";
				}
			}
			else if (!indication) {
				distance = " ";
			}

			if (hotncold) {
				if (temp_ecart != 0) {
					if (temp_ecart > 0) {
						temperature = " Froid ";
					}
					else {
						temperature = " Chaud ";
					}
				}
			}

			if (target == guess) {
				cout << "Bravo ! Le nombre aleatoire etait : " << target << ". Tu l'as trouve en " << current_attempts << " essaies." << endl;
				cout << "Veux-tu recommencer ? (Oui: 1 - Non: 0)" << endl << "-> ";

				Secure_var(restart, 0, 1); if (restart == 1) { Start(); }
				else { exit(0); }
				break;
			}

			if (target < guess) {
				current_attempts += 1;
				left_attempts -= 1;
				if (hotncold && current_attempts > 1) {
					cout << "C'est" << temperature << "! Il vous reste " << left_attempts << " essaies. Reesayer : ";
				}
				else {
				cout << "C'est" << distance << "moins ! Il vous reste " << left_attempts << " essaies. Reessayer : ";
				last_guess = guess;
				}
			}

			else {
				current_attempts += 1;
				left_attempts -= 1;
				if (hotncold && current_attempts > 1) {
					cout << "C'est " << temperature << " ! Il vous reste " << left_attempts << " essaies. Reesayer :";
				}
				else {
					cout << "C'est" << distance << "plus ! Il vous reste " << left_attempts << " essaies. Reessayer : ";
					last_guess = guess;
				}
			}
		}
		else {
			cout << endl << "Vous avez perdu ! Le nombre aleatoire etait : " << target << ". Voulez-vous recommencer ? (Oui: 1 - Non: 0) " << endl << "-> ";
			Secure_var(restart, 0, 1); if (restart == 1) { Start(); }
			else { exit(0); }
			break;
		}


	}

	return 0;
}

int main() {
	srand(time(NULL));

	Start();

	return 0;
}