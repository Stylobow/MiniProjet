#include <iostream>

using namespace std;

int main() {
	srand(time(NULL));

	cout << "Bienvenue dans le jeu du Plus ou Moins." << endl;
	cout << "Choisis un nombre: ";
	
	int target = rand() % 101;
	int guess;
	while (true) { 
		cin >> guess;

		if (target == guess) {
			system("cls");
			cout << guess << endl;
			cout << "Bravo !" << endl;
			break;
		}

		if (target < guess) {
			system("cls");
			cout << guess << endl;
			cout << "C'est moins !" << endl;
		}

		else {
			system("cls");
			cout << guess << endl;
			cout << "C'est plus !" << endl;
		}
	}

	return 0;
}