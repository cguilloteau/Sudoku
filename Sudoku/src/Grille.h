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
	void allocationTaille(int laTaille);
	int getTaille()const;
	void setTaille(int uneTaille);
	void chgtValeur(const int lig, const int col, const int val);
	int obtenirValeur(const int lig, const int col);
	void copier(Grille uneGrille);
	void afficher();

private:
    int taille;
    //Case *laGrille[9][9];
    //Case *laGrille16[9][9];
    //Case *laGrille[taille][taille];
    Case **laGrille;
    //std::vector< std::vector<Case> > laGrille;
};

#endif /* GRILLE_H_ */
