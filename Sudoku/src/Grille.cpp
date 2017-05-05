/*
 * Grille.cpp
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Partie.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "Case.h"
#include <cstdlib>
#include <ctime>
#include "Grille.h"
#include <stddef.h>
#include "List.h"

Grille::Grille(int laTaille) {
	int i,j;
	taille= laTaille;
	for (i=0;i<taille;i++){
		for (j=0;j<taille;j++){
			laGrille[i][j] = new Case();
			laGrille[i][j]->setColonne(j+1);
			laGrille[i][j]->setLigne(i+1);
			laGrille[i][j]->setRegion(i+1,j+1,taille);
		}
	}

}

Grille::~Grille() {
	// TODO Auto-generated destructor stub
}


int Grille::getTaille()const{
 return this->taille;
}

void Grille::setTaille(int uneTaille){
	this->taille=uneTaille;
}


void Grille::chgtValeur(int lig, int col, int val){
	(laGrille[lig][col])->setValeur(val);
}

int Grille::obtenirValeur(int lig, int col){
	return laGrille[lig][col]->getValeur();
}

void Grille::copier(Grille uneGrille){
	 for (int i=0;i<taille;i++){
		 for (int j=0;j<taille;j++){
			 int val = uneGrille.obtenirValeur(i,j);
			 laGrille[i][j]->setValeur(val);
	     }
	 }
}


/*void Grille::afficher(){
	int i,j;
	std::cout << "    1   2   3   4   5   6   7   8   9" << std::endl;
	std::cout << "  +---+---+---+---+---+---+---+---+---+" << std::endl;
	for (i=0 ; i< 9 ; i++){
		std::cout << i+1 << " |" ;
		for (j=0; j<9 ; j++){
			if(laGrille[i][j]->getValeur() ==0 ){
				std::cout << " " <<" " << " " << "|";
			}
			else {
				std::cout << " " <<laGrille[i][j]->getValeur() << " " << "|";
			}
		}
		std::cout << std::endl;
		std::cout << "  +---+---+---+---+---+---+---+---+---+" << std::endl;
	}
}*/

void Grille::afficher(){
	int i,j;
	if(taille==9){
		std::cout << "    1   2   3   4   5   6   7   8   9" << std::endl;
		std::cout << "  +---+---+---+---+---+---+---+---+---+" << std::endl;
		for (i=0 ; i< 9 ; i++){
			std::cout << i+1 << " |" ;
			for (j=0; j<9 ; j++){
				if(laGrille[i][j]->getValeur() ==0 ){
					std::cout << " " <<" " << " " << "|";
				}
				else {
					std::cout << " " <<laGrille[i][j]->getValeur() << " " << "|";
				}
			}
			std::cout << std::endl;
			std::cout << "  +---+---+---+---+---+---+---+---+---+" << std::endl;
		}
	}
	else if(taille==16){
		std::cout << "    1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16" << std::endl;
		std::cout << "  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << std::endl;
		for (i=0 ; i< 16 ; i++){
			std::cout << i+1 << " |" ;
			for (j=0; j<16 ; j++){
				if(laGrille[i][j]->getValeur() ==0 ){
					std::cout << " " <<" " << " " << "|";
				}
				else {
					std::cout << " " <<laGrille[i][j]->getValeur() << " " << "|";
				}
			}
			std::cout << std::endl;
			std::cout << "  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << std::endl;
		}

	}
}

