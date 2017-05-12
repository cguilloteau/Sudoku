/** \class Case
* \brief Repr�sente une grille de Sudoku
* \author Zo�, Claire, Fabrice, Tarek
* \version 1.0
* \date Mai 2017
* \bug Aucun bug
* \warning Aucun warning
*
* Permet de representer une grille de sudoku qui correspond � tableau dynamique en 2 dimensions.
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
    Case **laGrille;
};

#endif /* GRILLE_H_ */
