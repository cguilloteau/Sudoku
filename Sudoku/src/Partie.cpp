/*
 * Partie.cpp
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Partie.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Case.h"
#include <cstdlib>
#include <ctime>
#include "Grille.h"

Partie::Partie(string nomJ ) {
	finie = false;
	nomJoueur = nomJ;
	Grille grille;

}


Partie::~Partie() {
	// TODO Auto-generated destructor stub
}

void Partie::initialiser(){
int i,j;
int tab[9][9]={{0, 4, 3, 7, 6, 5, 2, 1, 9},{5, 6, 7, 2, 1, 9, 3, 8, 4},{1, 2, 9, 4, 3, 8, 5, 7, 6},{2, 7, 4, 3, 8, 1, 6, 9, 5},{6, 8, 1, 5, 9, 2, 7, 4, 3},{3, 9, 5, 6, 7, 4, 1, 2, 8},{7, 1, 8, 9, 5, 3, 4, 6, 2},{4, 5, 6, 8, 2, 7, 9, 3, 1},{9, 3, 2, 1, 4, 6, 8, 5, 7}};
for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				grille.chgtValeur(i,j,tab[i][j]);
			}
	}

}

void Partie::permuter(){
	int temp;
	int c1, v1, c11, v11;
	int c2, v2, c22, v22;
	int c3, v3, c33, v33;
	vector<int> tabregion1;
	for (int x=0; x < 3; x++){
		tabregion1.push_back(x);
	}
	c1 = rand()%(tabregion1.size()-1);
	v1 = tabregion1.at(c1);
	tabregion1.erase(tabregion1.begin()+c1);
	c11 = rand()%(tabregion1.size()-1);
	v11 = tabregion1.at(c11);
	tabregion1.erase(tabregion1.begin()+c11);

	vector<int> tabregion2;
	for (int x=3; x < 6; x++){
		tabregion2.push_back(x);
	}
	c2 = rand()%(tabregion2.size()-1);
	v2 = tabregion2.at(c2);
	tabregion2.erase(tabregion2.begin()+c2);
	c22 = rand()%(tabregion2.size()-1);
	v22 = tabregion2.at(c22);
	tabregion2.erase(tabregion2.begin()+c22);

	vector<int> tabregion3;
	for (int x=6; x < 9; x++){
		tabregion3.push_back(x);
	}
	c3 = rand()%(tabregion3.size()-1);
	v3 = tabregion3.at(c3);
	tabregion3.erase(tabregion3.begin()+c3);
	c33 = rand()%(tabregion3.size()-1);
	v33 = tabregion3.at(c33);
	tabregion3.erase(tabregion3.begin()+c33);

	for (int t=0;t<9;t++){
		temp = grille.obtenirValeur(t,v1);
		grille.chgtValeur(t,v1,grille.obtenirValeur(t,v11));
		grille.chgtValeur(t,v11,temp);
	}
	for (int t=0;t<9;t++){
		temp = grille.obtenirValeur(t,v2);
		grille.chgtValeur(t,v2,grille.obtenirValeur(t,v22));
		grille.chgtValeur(t,v22,temp);
	}
	for (int t=0;t<9;t++){
		temp = grille.obtenirValeur(t,v3);
		grille.chgtValeur(t,v3,grille.obtenirValeur(t,v33));
		grille.chgtValeur(t,v33,temp);
	}
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
			}while((colonne<1)||(colonne>9)||((grilleDeBase.obtenirValeur(ligne,colonne))!=0));

			do{
			std::cout << "Quelle valeur souhaitez-vous insérer? " << std::endl;
			std::cin >> valeur;
			}while((valeur<1)||(valeur>9));

			choixOk = true;
		}
		grille.chgtValeur(ligne-1,colonne-1,valeur);
		std::cout << "############################################# " << std::endl;


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
	std::cout << "Vous avez rempli le sudoku BLA BLA BLA BLA, bravo " << nomJoueur << std::endl;

}
