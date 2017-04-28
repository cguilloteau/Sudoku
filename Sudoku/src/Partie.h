/*
 * Partie.h
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Grille.h"
#include "Case.h"


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
private :
	bool finie;
	string nomJoueur;
	Grille grille;
};

#endif /* PARTIE_H_ */
