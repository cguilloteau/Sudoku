/*
 * Partie.cpp
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Partie.h"


Partie::Partie(string nomJ ) {
	finie = false;
	nomJoueur = nomJ;
	Grille grille;

}


Partie::~Partie() {
	// TODO Auto-generated destructor stub
}

void Partie::test(){
grille.afficher();
}

void Partie::jouer(){
	int ligne, colonne, valeur, i,j, temp, nbzeros;
	bool choixOk;
	Grille grilleDeBase;

	for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				temp = grille.obtenirValeur(i,j);
				grilleDeBase.chgtValeur(i,j,temp);
			}
	}

	while(finie == false){
		grille.afficher();
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		choixOk = false;
		while(choixOk == false){
			do{
				std::cout << "Quelle ligne voulez-vous modifier? " << std::endl;
				std::cin >> ligne;
			}while((ligne<1)||(ligne>9));

			do{
				std::cout << "Quelle colonne voulez-vous modifier? " << std::endl;
				std::cin >> colonne;
				if((grilleDeBase.obtenirValeur(ligne,colonne))!=0){
					cout << "Vous ne pouvez pas modifier cette case" << std::endl;
				}
			}while(((colonne<1)||(colonne>9))&&((grilleDeBase.obtenirValeur(ligne,colonne))!=0));

			do{
			std::cout << "Quelle valeur souhaitez-vous insérer? " << std::endl;
			std::cin >> valeur;
			}while((valeur<1)||(valeur>9));
			choixOk = true;
		}
		grille.chgtValeur(ligne-1,colonne-1,valeur);
		std::cout << "############################################# " << std::endl;
		//grille.afficher();

		nbzeros = 0;           ////La on regarde si toute la grille est pleine pour mettre fin au jeu
		for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				if (grille.obtenirValeur(i,j)==0){
					nbzeros= nbzeros+1;
				}
			}
		}
		if(nbzeros == 0){//grille pleine -> fin du jeu
			finie = true;
		}
	}

	std::cout << "############################################# " << std::endl;
	std::cout << "Vous avez rempli le sudoku BLA BLA BLA BLA" << std::endl;

}
