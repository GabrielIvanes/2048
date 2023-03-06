#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int score;

/**
     * Permet de réinitialiser la matrice
     * @param valeur la matrice à réinitialiser
     * @return aucun
*/
void ClearMatrice (int matrice[4][4]) {
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			matrice[i][j] = 0;
		}
	}
}

/**
     * Permet de réinitialiser le tableau compteur
     * @param valeur le tableau à réinitialiser
     * @return aucun
*/
void ClearCompteur (int tableau[4]){
	for (int i = 0; i < 4; i ++) {
		tableau[i] = 0;
	}
}

/**
     * Permet d'affichier la matrice dans le terminal
     * @param valeur la matrice à afficher
     * @return aucun
*/
void AfficheMatrice (int matrice[4][4]) {
	for (int i = 0; i < 4; i ++ ) {
		for (int j = 0; j < 4; j++) {
			printf(" %d ", matrice[i][j]);
		}
		printf("\n");
	}
}

/**
     * Permet d'afficher la matrice dans le terminal en tenant compte du nombre max
     * @param valeur la matrice à afficher
     * @return aucun
*/
void AfficheMatrice2 (int matrice[4][4]) {
	int max_ligne = 0;
	for (int j = 0; j < 4; j ++ ) {
		for (int i = 0; i < 4; i++) {
			if (matrice[i][j] > max_ligne) {
				max_ligne = matrice[i][j];
			}
		}
	}
	if (max_ligne < 10){
		AfficheMatrice(matrice);
	}
	else if ((max_ligne > 10) && (max_ligne < 100)){
		for (int i = 0; i < 4; i ++ ) {
			for (int j = 0; j < 4; j++) {
				if (matrice[i][j] < 10){
					printf(" %d  ", matrice[i][j]);
				}
				else {
					printf(" %d ", matrice[i][j]);
				}
			}
			printf("\n");
		}
	}
	else if ((max_ligne > 100) && (max_ligne < 1000)){
		for (int i = 0; i < 4; i ++ ) {
			for (int j = 0; j < 4; j++) {
				if (matrice[i][j] < 10){
					printf(" %d   ", matrice[i][j]);
				}
				else if ((matrice[i][j]) > 10 && (matrice[i][j] < 100)){
					printf(" %d  ", matrice[i][j]);
				}
				else {
					printf(" %d ", matrice[i][j]);
				}
			}
			printf("\n");
		}
	}
	else if ((max_ligne > 1000) && (max_ligne < 10000)){
		for (int i = 0; i < 4; i ++ ) {
			for (int j = 0; j < 4; j++) {
				if (matrice[i][j] < 10){
					printf(" %d    ", matrice[i][j]);
				}
				else if ((matrice[i][j]) > 10 && (matrice[i][j] < 100)){
					printf(" %d   ", matrice[i][j]);
				}
				else if ((matrice[i][j]) > 100 && (matrice[i][j] < 1000)){
					printf(" %d  ", matrice[i][j]);
				}
				else {
					printf(" %d ", matrice[i][j]);
				}
			}
			printf("\n");
		}
	}
	else if ((max_ligne > 10000) && (max_ligne < 100000)){
		for (int i = 0; i < 4; i ++ ) {
			for (int j = 0; j < 4; j++) {
				if (matrice[i][j] < 10){
					printf(" %d     ", matrice[i][j]);
				}
				else if ((matrice[i][j]) > 10 && (matrice[i][j] < 100)){
					printf(" %d    ", matrice[i][j]);
				}
				else if ((matrice[i][j]) > 100 && (matrice[i][j] < 1000)){
					printf(" %d   ", matrice[i][j]);
				}
				else if ((matrice[i][j]) > 1000 && (matrice[i][j] < 10000)){
					printf(" %d  ", matrice[i][j]);
				}
				else {
					printf(" %d ", matrice[i][j]);
				}
			}
			printf("\n");
		}
	}
}


/**
     * Permet de compter le nombre de 0 de la matrice pour la fonction mettre2ou4Aleatoire
     * @param valeur la matrice dont on veut compter les 0
     * @return le nombre de 0 dans la matrice
*/
int CompterNombrede0 (int matrice[4][4]) {
	int nombrede0 = 0;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			if (matrice[i][j] == 0) {
				nombrede0 ++;
			}
		}
	}
	return nombrede0;
}

/**
     * Permet de mettre des 2 ou 4 aléatoirement dans la matrice après que le joueur ait décidé de son mouvement
     * @param valeur la matrice pour laquelle on veut mettre un 2 ou 4 aléatoirement
     * @return 1 si un 2 ou 4 a été ajouté, 0 sinon
*/
int Mettre2ou4Aleatoire (int matrice[4][4]) {
//Permet de mettre des 2 ou 4 aléatoirement sur la matrice après que le joueur ait décidé de son mouvement
	int nombrede0 = CompterNombrede0(matrice);
	int PlaceAleatoire2 = 0;
	int PlaceAleatoire4 = 0;
	if (nombrede0 != 0) {
		PlaceAleatoire2 = rand()%nombrede0+1;
		PlaceAleatoire4 = rand()%100+1;
		while (PlaceAleatoire4 == PlaceAleatoire2) {
			PlaceAleatoire4 = rand()%100+1;
		}
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				if ((matrice[i][j] == 0) && (PlaceAleatoire2 == 1)) {
					matrice[i][j] = 2;
					return 1;
				}
				else if ((matrice[i][j] == 0) && (PlaceAleatoire4 == 1)) {
					matrice[i][j] = 4;
					return 1;
				}
				PlaceAleatoire2 = rand()%nombrede0+1;
				PlaceAleatoire4 = rand()%100+1;
			}
		}
		return 0;
	}
	else if (nombrede0 == 0) {
		return 1;
	}
	return 0;
}

/**
     * Permet de comparer deux matrices afin de vérifier si tour n égal au tour n-1
     * @param valeur des matrices que l'on veut comparer
     * @return 1 si les matrices sont différentes, 0 sinon
*/
int compareMatrice (int matrice1[4][4], int matrice2[4][4]){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (matrice1[i][j] != matrice2[i][j]) {
				return 1;
			}
		}
	}
	return 0;
}

/**
     * Permet le déplacement des nombres de la matrice vers la gauche en ne faisant que 1 addition, celle la plus à gauche (règle du jeu)
     * @param valeur de la matrice pour laquelle on souhaite aller à gauche, colonnes, lignes, tableau compteur pour savoir si une addition a déjà été réalisé
     * @return aucun
*/
void AllerGauche (int matrice[4][4], int j, int i, int compteur[4]) {
	if (j != 0) {
		if (matrice[i][j-1] == 0) {
			matrice[i][j-1] = matrice[i][j];
			matrice[i][j] = 0;
			AllerGauche (matrice, j-1, i, compteur);
		}
		else if ((matrice[i][j-1] == matrice[i][j]) && (compteur[j-1] != 1) && (compteur[j] != 1)){
			matrice[i][j-1] = 2 * matrice[i][j];
			matrice[i][j] = 0;
			compteur[j-1] = 1;
			score = score + matrice[i][j-1];
			AllerGauche (matrice, j-1, i, compteur);
		}
	}
}

/**
     * Permet le déplacement des nombres de la matrice vers la droite en ne faisant que 1 addition, celle la plus à droite (règle du jeu)
     * @param valeur la matrice pour laquelle on souhaite aller à droite, colonnes, lignes, tableau compteur pour savoir si une addition a déjà été réalisé
     * @return aucun
*/
void AllerDroite (int matrice[4][4], int j, int i, int compteur[4]) {
	if (j!=3) {
		if (matrice[i][j+1] == 0) {
			matrice[i][j+1] = matrice[i][j];
			matrice[i][j] = 0;
			AllerDroite (matrice, j+1, i, compteur);
		}
		else if ((matrice[i][j+1] == matrice[i][j]) && (compteur[j+1] != 1) && (compteur[j] != 1)) {
			matrice[i][j+1] = 2 * matrice[i][j];
			matrice[i][j] = 0;
			compteur[j+1] = 1;
			score = score + matrice[i][j+1];
			AllerDroite (matrice, j+1, i, compteur);
		}
	}
}

/**
     * Permet le déplacement des nombres de la matrice vers le haut en ne faisant que 1 addition, celle la plus en haut (règle du jeu)
     * @param valeur la matrice pour laquelle on souhaite aller en haut, colonnes, lignes, tableau compteur pour savoir si une addition a déjà été réalisé
     * @return aucun
*/
void AllerHaut (int matrice[4][4], int j, int i, int compteur[4]) {
	if (i != 0) {
		if (matrice[i-1][j] == 0) {
			matrice[i-1][j] = matrice[i][j];
			matrice[i][j] = 0;
			AllerHaut (matrice, j, i-1, compteur);
		}
		else if ((matrice[i-1][j] == matrice[i][j]) && (compteur[i-1] != 1) && (compteur[i] != 1)){
			matrice[i-1][j] = 2 * matrice[i][j];
			matrice[i][j] = 0;
			compteur[i-1] = 1;
			score = score + matrice[i-1][j];
			AllerHaut (matrice, j, i-1, compteur);
		}
	}
}

/**
     * Permet le déplacement des nombres de la matrice vers le bas en ne faisant que 1 addition, celle la plus en bas (règle du jeu)
     * @param valeur la matrice pour laquelle on souhaite aller en bas, colonnes, lignes, tableau compteur pour savoir si une addition a déjà été réalisé
     * @return aucun
*/
void AllerBas (int matrice[4][4], int j, int i, int compteur[4]) {
	if (i!=3) {
		if (matrice[i+1][j] == 0) {
			matrice[i+1][j] = matrice[i][j];
			matrice[i][j] = 0;
			AllerBas (matrice, j, i+1, compteur);
		}
		else if ((matrice[i+1][j] == matrice[i][j]) && (compteur[i+1] != 1) && (compteur[i] != 1)){
			matrice[i+1][j] = 2 * matrice[i][j];
			matrice[i][j] = 0;
			compteur[i+1] = 1;
			score = score + matrice[i+1][j];
			AllerBas (matrice, j, i+1, compteur);
		}
	}
}

/**
     * Permet de regarder si plus aucun mouvement ne sont possibles
     * @param valeur la matrice 
     * @return 1 si plus aucun mouvement possible, 0 sinon
*/
int PartieFinie (int matrice[4][4]) {
	for (int i = 0; i < 4; i ++ ) {
		for (int j = 0; j < 4; j++) {
			if (matrice[i][j] == 0) {
				return 0;
			}
			else {
				if ((matrice[0][1] == matrice[0][0]) || (matrice[0][1] == matrice[0][2]) || (matrice[0][1] == matrice[1][1])) {
					return 0;
				}
				else if ((matrice[0][2] == matrice[0][3]) || (matrice[0][2] == matrice[1][2])) {
					return 0;
				}
				else if ((matrice[1][0] == matrice[0][0]) || (matrice[1][0] == matrice[1][1])) {
					return 0;
				}
				else if ((matrice[1][1] == matrice[1][2]) || (matrice[1][1] == matrice[2][1])) {
					return 0;
				}
				else if ((matrice[1][3] == matrice[0][3]) || (matrice[1][3] == matrice[1][2]) || (matrice[1][3] == matrice[2][3])) {
					return 0;
				}
				else if ((matrice[2][0] == matrice[1][0]) || (matrice[2][0] == matrice[2][1]) || (matrice[2][0] == matrice[3][0])) {
					return 0;
				}
				else if ((matrice[2][2] == matrice[1][2]) || (matrice[2][2] == matrice[2][1])) {
					return 0;
				}
				else if ((matrice[2][3] == matrice[1][3]) || (matrice[2][3] == matrice[2][2]) || (matrice[2][3] == matrice[3][3])) {
					return 0;
				}
				else if ((matrice[3][1] == matrice[3][0]) || (matrice[3][1] == matrice[2][1])) {
					return 0;
				}
				else if ((matrice[3][2] == matrice[3][1]) || (matrice[3][2] == matrice[2][2]) || (matrice[3][2] == matrice[3][3])) {
					return 0;
				}
			}
		}
	}
	return 1;
}

/**
     * Permet de lancer la partie en plaçant 2 éléments aléatoirement : un 2 ou un 4
     * @param valeur la matrice
     * @return aucun
*/
void DebutPartie (int matrice[4][4]) {
	srand(time(NULL));
	int changementAleatoire = rand()%4+1;
	int PlaceNombreAleatoire1 = rand()%3+0;
	int PlaceNombreAleatoire2 = rand()%3+0;
	int PlaceNombreAleatoire3 = rand()%3+0;
	int PlaceNombreAleatoire4 = rand()%3+0;
	while ((PlaceNombreAleatoire1 == PlaceNombreAleatoire3) & (PlaceNombreAleatoire2 == PlaceNombreAleatoire4)) {
		if (changementAleatoire == 1) {
			PlaceNombreAleatoire1 = rand()%3+0;
		}
		else if (changementAleatoire == 2) {
			PlaceNombreAleatoire2 = rand()%3+0;
		}
		else if (changementAleatoire == 3) {
			PlaceNombreAleatoire3 = rand()%3+0;
		}
		else if (changementAleatoire == 4) {
			PlaceNombreAleatoire4 = rand()%3+0;
		}

	}

	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			if (((i == PlaceNombreAleatoire1) && (j == PlaceNombreAleatoire2)) || ((i == PlaceNombreAleatoire3) && (j == PlaceNombreAleatoire4))) {
				matrice[i][j] = 2;
			}
		}
	}
	AfficheMatrice2(matrice);
}

/**
     * Permet de créer la partie et de faire l'affiche du terminal
     * @param valeur la matrice
     * @return aucun
*/
void Partie(int matrice[4][4]) {
	char direction;
	int comparateur = 0;
	int compteur[4] = {0};
	int j = 0;
	int i = 0;
	int stop = 0;
	score = 0;
	int maxscore = 0;
	int refaireUnePartie = 1;
	printf ("Pour aller à gauche: q\nPour aller à droite: d\nPour aller vers le haut: z\nPour aller vers les bas: s\n\n");
	while (PartieFinie(matrice) != 1) {
		printf ("Entrez la direction souhaitée: ");
		scanf (" %c", &direction);
		printf("\n\n");
		int copie1[4][4];
		for (int i = 0; i<4; i++) {
			for (int j = 0; j<4; j++) {
				copie1[i][j] = matrice[i][j];
			}
		}
		AfficheMatrice2(copie1);
		switch (direction) {
			case 'q':
			for (i = 0; i < 4; i++) {
				for (j = 1; j < 4; j++) {
					AllerGauche (matrice, j, i, compteur);
				}
				ClearCompteur (compteur);
			}
			ClearCompteur (compteur);
			break;
			case 'd':
			for (i = 0; i < 4; i++) {
				for (j = 3; j>=0; j--) {
					AllerDroite (matrice, j, i, compteur);
				}
				ClearCompteur (compteur);
			}
			ClearCompteur (compteur);
			break;
			case 'z':
			for (j = 0; j < 4; j++) {
				for (i = 1; i < 4; i++) {
					AllerHaut(matrice, j, i, compteur);
				}
				ClearCompteur (compteur);
			}
			ClearCompteur (compteur);
			break;
			case 's':
			for (j = 0; j < 4; j++) {
				for (i = 3; i >= 0; i--) {
					AllerBas (matrice, j, i, compteur);
				}
				ClearCompteur (compteur);
			}
			ClearCompteur (compteur);
			break;
			default:
			printf("mauvais choix de direction\n\n");
			Partie(matrice);
		}
		AfficheMatrice2(matrice);
		printf("\n\n");
		int copie2[4][4];
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				copie2[i][j] = matrice[i][j];
			}
		}
		AfficheMatrice2(copie2);
		printf("\n\n");
		comparateur = compareMatrice (copie1, copie2);
		if (comparateur != 0) {
			while (stop != 1) {
				stop = Mettre2ou4Aleatoire (matrice);
			}
			stop = 0;
		}
			system("cls"); //clear output
			printf ("\nscore: %d\n", score);
			AfficheMatrice2(matrice);
		}
		printf("Dommage, vous avez perdu !\n");
		printf ("Votre score de la partie est de : %d\n", score);
		if (score > maxscore) {
			printf ("Bravo vous avez battu votre record !!\n");
			maxscore = score;
		}
		else {
			printf("Votre meilleur score est de : %d, essayez de le battre !\n", maxscore);
		}
	}


int main () {
	int m[4][4];
	int refaireUnePartie = 1;
	printf("%d", refaireUnePartie);
	while (refaireUnePartie != 0) {
		ClearMatrice(m);
		DebutPartie (m);
		Partie(m);
		printf("Voulez-vous refaire une partie ?\n0 pour non\n1 pour oui\n");
		scanf("%d", &refaireUnePartie);
		if ((refaireUnePartie != 1) || (refaireUnePartie != 0)) {
			printf ("Mauvaise entrée\n\n");
			printf("Voulez-vous refaire une partie ?\n0 pour non\n1 pour oui\n");
			scanf("%d", &refaireUnePartie);
		}
	}	
	return 0;
}
