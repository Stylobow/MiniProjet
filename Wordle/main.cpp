#include <iostream>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define DEFAULT "\033[0m"

using namespace std;

int StrLenght(const char* str) {
	int lenght = 0;
	while (str[lenght] != '\0') {
		lenght++;
	}
	return lenght;
}

int main()
{
	srand(time(NULL));

	const int maxLenght = 14;
	const char dictionary[][maxLenght] = {
		"TABLE", "CHAT", "JEUX", "MAISON", "BONSOIR", "ORDINATEUR", "ROCKETLEAGUE", "CLAVIER", "SOURIS", "PAIN", "MANETTE", "HOMME", "FEMME", "GAMING", "ECOLE",
		"INFORMATIQUE", "BONBON", "POISSON", "DESERT", "JAMBON", "BEURRE", "TARTIFLETTE", "SUCETTE", "RACLETTE", "TELEPHONE", "TELEVISEUR", "TELEVISION","GATEAU",
		"TOBOGAN", "ECRAN", "PROGRAMME", "PROGRAMMATION", "MICRO", "OUVERTURE", "FERMETURE", "FRANCE", "PORTE"," RIDEAU"," EAU", "LAVE", "VOITURE"," TRAIN", "AVION",
		"MOTO", "ROUTE", "SUISSE", "DESSERT", "IMPOSTEUR", "INNOCENT", "CHASSE", "CHASSEUR", "MISSION", "CABLE", "ELECTRIQUE", "ELECTRICITE", "POISON", "CARTE", 
		"ANTENNE", "LAMPE", "MUR", "TOIT", "JOUR", "MOIS", "ANNEE", "HEURE", "MINUTE", "SECONDE", "MICROSCOPIQUE", "JANVIER", "FEVRIER", "MARS", "AVRIL", "MAI",
		"JUIN", "JUILLET", "AOUT", "SEPTEMBRE", "OCTOBRE", "NOVEMBRE", "DECEMBRE", "PLANETE", "MERCURE", "VENUS", "TERRE", "JUPITER", "SATURN", "URANUS", "NEPTUNE",
		"SCIENCE", "MATHEMATIQUE", "SPORT"," FOOTBALL", "PIED", "MAIN", "TETE", "NEZ", "BOITE", "LIQUIDE", "ESCALADE", "LUMIERE", "GRAVITE", "METEORITE", "NUAGE",
		"METEO", "PLUIE", "ORAGE" ,"GLACE", "ANIMAL", "SAUVAGE", "FORET", "BLANC", "NOIR"," JAUNE"," BLEU", "ORANGE", "ROUGE", "VIOLET", "CYAN", "VERT", "ROSE", "MAGENTA",
		"PISCINE", "LETTRE", "ALPHABET", "COURRIER", "PAPIER"," FEUILLE", "LUNE", "MONTRE", "VENTILATTEUR", "PROCESSEUR", "GRAPHISME", "CADRE", "VETEMENTS", "CHAUSSURES",
		"MEUBLE", "BOIS", "PIERRE", "SOL", "HERBE", "TERRE", "ARBRE", "POUSSIERE", "COUVERTURE", "VENT", "TENNIS", "FORMULE", "ORTOGRAPHE", "REGLE", "MORPION"
	};
	const int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

	int previousIndex = -1;
	char playAgain = 'o';
	
	while (playAgain == 'o' || playAgain == 'O') {

		int randomIndex;
		do {
			randomIndex = rand() % dictionarySize;
		} while (randomIndex == previousIndex && dictionarySize > 1);

		previousIndex = randomIndex;
		const char* secretWord = dictionary[randomIndex];

		int wordLenght = StrLenght(secretWord);
		const int maxAttempts = 6;
		bool hasWon = false;

		system("cls");
		cout << "Bienvenue dans le jeu du Wordle" << endl;
		cout << "Devine le mot aleatoire de " << wordLenght << " lettres en " << maxAttempts << " essais." << endl;
		cout << " - " << GREEN << "Vert" << DEFAULT << " : Bonne lettre au bon endroit." << endl;
		cout << " - " << YELLOW << "Jaune" << DEFAULT << " : Bonne lettre au mauvais endroit" << endl;
		cout << " - " << RED << "Rouge" << DEFAULT << " : Lettre pas dans le mot" << endl << endl;

		for (int attempt = 1; attempt <= maxAttempts; attempt++) {
			cout << "Essai " << attempt << "/" << maxAttempts << " : ";
			char guess[maxLenght];
			cin >> guess;

			if (StrLenght(guess) != wordLenght) {
				cout << RED << "Erreur : Le mot doit faire exactement " << YELLOW << wordLenght << RED << " lettres ! " << DEFAULT << endl;
				attempt--;
				continue;
			}

			bool secretMatched[maxLenght] = { 0 };
			bool guessMatched[maxLenght] = { 0 };

			for (int i = 0; i < wordLenght; i++) {
				if (guess[i] == secretWord[i]) {
					guessMatched[i] = true;
					secretMatched[i] = true;
				}
			}

			for (int i = 0; i < wordLenght; i++) {
				if (!guessMatched[i]) {
					bool found = false;
					for (int j = 0; j < wordLenght; j++) {
						if (!secretMatched[j] && guess[i] == secretWord[j]) {
							secretMatched[j] = true;
							found = true;
							break;
						}
					}
					if (found) {
						cout << YELLOW << guess[i] << DEFAULT;
					}
					else {
						cout << RED << guess[i] << DEFAULT;
					}
				}
				else {
					cout << GREEN << guess[i] << DEFAULT;
				}
			}
			cout << DEFAULT << endl;

			bool roundWon = true;
			for (int i = 0; i < wordLenght; i++) {
				if (guess[i] != secretWord[i]) {
					roundWon = false;
					break;
				}
			}

			if (roundWon) {
				cout << GREEN << "Fecilitation ! Vous avez gagne !" << DEFAULT << endl;
				hasWon = true;
				break;
			}
		}

		if (!hasWon) {
			cout << RED << "Perdu ! Le mot secret etait : " << secretWord << DEFAULT << endl;
		}

		cout << endl << "Voulez-vous rejouer ? (o/n)" << endl;
		cin >> playAgain;
	}

	return 0;
}