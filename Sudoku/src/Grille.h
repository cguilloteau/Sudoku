/*
 * Grille.h
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Case.h"

#ifndef GRILLE_H_
#define GRILLE_H_

class Grille {
public:
	Grille();
	virtual ~Grille();
	void chgtValeur(const int lig, const int col, const int val);
	int obtenirValeur(const int lig, const int col);
	void afficher();

private:
    Case *laGrille[9][9];
};

#endif /* GRILLE_H_ */
