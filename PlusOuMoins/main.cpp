#include <iostream>

using namespace std;

int Start() {
	system("cls");

	int max_attempts = 10;
	int left_attempts = max_attempts;
	int current_attempts = 0;

	int max_random = 100;
	int target = rand() % max_random + 1;
	int guess;

	cout << "Bienvenue dans le jeu du Plus ou Moins. Vous avez " << max_attempts << " essaies pour trouver le chiffre aleatoire entre 0 et " << max_random << "." << endl;
	cout << "Choisis un nombre: ";

	while (true) {
		bool restart;

		current_attempts += 1;
		left_attempts -= 1;

		if (current_attempts == max_attempts) {
			cout << endl << "Vous avez perdu ! Le nombre aleatoire etait : " << target << ". Voulez-vous recommencer ? (Oui: 1 - Non: 0) " << endl << "-> ";
			cin >> restart; if (restart == 1) { Start(); }
			break;
		}

		cin >> guess;
		if (target == guess) {
			cout << "Bravo ! Le nombre aleatoire etait : " << target << ". Tu l'as trouve en " << current_attempts << " essaies." << endl;
			cout << "Veux-tu recommencer ? (Oui: 1 - Non: 0)" << endl << "-> ";

			cin >> restart; if (restart == 1) { Start(); } else { system("exit"); }
			break;
		}

		if (target < guess) {
			cout << "C'est moins ! Il vous reste "<< left_attempts << " essaies. Reessayer : ";
		}

		else {
			cout << "C'est plus ! Il vous reste " << left_attempts << " essaies. Reessayer : ";
		}
	}

	return 0;
}

int main() {
	srand(time(NULL));

	Start();

	return 0;
}