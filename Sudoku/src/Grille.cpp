/*
 * Grille.cpp
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Grille.h"

Grille::Grille() {
	int i,j ;
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			laGrille[i][j] = new Case();
			laGrille[i][j]->setColonne(j+1);
			laGrille[i][j]->setLigne(i+1);
			laGrille[i][j]->setRegion(i+1,j+1);
		}
	}

}

Grille::~Grille() {
	// TODO Auto-generated destructor stub
}



void Grille::chgtValeur(int lig, int col, int val){
	(laGrille[lig][col])->setValeur(val);
}

int Grille::obtenirValeur(int lig, int col){
	return laGrille[lig][col]->getValeur();
}


void Grille::afficher(){
	int i,j;
	std::cout << "    1   2   3   4   5   6   7   8   9" << std::endl;
	std::cout << "  +---+---+---+---+---+---+---+---+---+" << std::endl;
	for (i=0 ; i< 9 ; i++){
		std::cout << i+1 << " |" ;
		for (j=0; j<9 ; j++){
			std::cout << " " <<laGrille[i][j]->getValeur() << " " << "|";
		}
		std::cout << std::endl;
		std::cout << "  +---+---+---+---+---+---+---+---+---+" << std::endl;
	}
}
