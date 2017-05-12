/** \class Partie
* \brief Permet d'organiser le déroulement d'une partie de Sudoku
* \author Zoé, Claire, Fabrice, Tarek
* \version 1.0
* \date Mai 2017
* \bug Aucun bug
* \warning Aucun warning
*
* Composée d'un nom de Joueur, une grille et un booléen qui signale si la partie est terminée.
*/

#include "Grille.h"
#include "Case.h"
#include "List.h"



using namespace std ;

#ifndef PARTIE_H_
#define PARTIE_H_

class Partie {
public:
	/** \fn Partie(string nomJ, int laTaille)
	 *
	 *\brief Constructeur permettant de créer une partie. L'attribut finie est initialisé à Faux. Le nom du Joueur et la taille de la grille sont initialisés à partir des paramètres en entrée.
	 *
	 */
	Partie(string nomJ, int laTaille);
	/** \fn virtual ~Partie()
	 *
	 *\brief Destructeur de Partie.
	 *
	 */
	virtual ~Partie();
	/** \fn jouer()
	 *
	 *\brief Organise le déroulement de la partie à partir du moment où la grille de jeu est prête à l'emploi.
	 *
	 */
	void jouer();
	/** \fn permuterColonnes()
	 *
     *\brief Permet de permuter 2 colonnes de la même région choisies aléatoirement, pour chaque région.
     *
     */
	void permuterColonnes();
	/** \fn permuterLignes()
	 *
	 *\brief Permet de permuter 2 lignes de la même région choisies aléatoirement, pour chaque région.
	 *
	 */
	void permuterLignes();
	/** \fn initialiser()
	 *
	 *\brief Permet de remplir la grille de la partie à partir d'un tableau initial comportant une grille résolue. Cette grille initiale sera modifiée plus tard.
	 *
	 */
	void initialiser();
	/** \fn bool colonneOk (int k, int j)
	 *
	 *\brief Lorsque la grille n'est pas encore pleine, cette fonction permet de vérifier si la valeur k n'est pas encore dans la colonne j.
	 *
	 *\return True si la valeur k n'est pas encore dans la colonne j, False sinon.
	 */
	bool colonneOk (int k, int j);
	/** \fn bool ligneOk (int k, int i)
	 *
	 *\brief Lorsque la grille n'est pas encore pleine, cette fonction permet de vérifier si la valeur k n'est pas encore dans la ligne i.
     *
     *\return True si la valeur k n'est pas encore dans la ligne i, False sinon.
     */
	bool ligneOk (int k, int i);
	bool regionOk (int k, int i, int j);
	bool ligneValide (int k, int i, int j);
	bool colonneValide (int k, int i, int j);
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
