/*
 * Partie.h
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Grille.h"
#include "Case.h"
#include "List.h"



using namespace std ;

#ifndef PARTIE_H_
#define PARTIE_H_

class Partie {
public:
	Partie(string nomJ);
	virtual ~Partie();
	void jouer();
	void permuter();
	void initialiser();
	bool colonneOk (int k, int j);
	bool ligneOk (int k, int i);
	bool regionOk (int k, int i, int j);
	//bool estValideInitial (Grille lagrille, LIST* position);
	bool estValide (Grille lagrille, LIST* position);
	bool estValide2 (Grille lagrille, LIST* position);
	int nb_possibles (int i, int j);
	bool resolutionTotale();
    void resolutionUneCase();
	bool unicite();
	void difficulteGrille(int nbCaseEnMoins);
private :
	bool finie;
	string nomJoueur;
	Grille grille;
};

#endif /* PARTIE_H_ */
