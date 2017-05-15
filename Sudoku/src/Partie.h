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
	/** \fn bool regionOk (int k, int i, int j)
	 *
	 *\brief Lorsque la grille n'est pas encore pleine, cette fonction permet de vérifier si la valeur k n'est pas encore dans la région de la case placée à la ligne i et colonne j.
     *
     *\return True si la valeur k n'est pas encore dans la région, False sinon.
     */
	bool regionOk (int k, int i, int j);
	/** \fn bool ligneValide (int k, int i, int j)
	 *
	 *\brief Lorsque la grille est pleine, cette fonction permet de vérifier si la valeur k n'est pas deux fois dans la ligne i.
     *
     *\return True si la valeur k n'est qu'une fois dans la ligne i, False sinon.
     */
	bool estValide (Grille lagrille, LIST* position);
	/** \fn bool  estValide2(Grille lagrille, LIST* position)
	 *
	 *\brief Même rôle que estValide(Grille lagrille, LIST* position), mais en procédant dans un ordre différent pour le remplissage.
	 *
	 *\return True si la grille a été correctement remplie, False sinon.
	 */
	bool estValide2 (Grille lagrille, LIST* position);
	/** \fn int nb_possibles (int i, int j)
	 *
	 *\brief Calcule le nombre de valeurs possibles pour la case à la ligne i et colonne j. Permet de trier, plus tard, les cases dans un ordre de priorité.
            Effectuer le backtracking depuis les cases avec un minimum de solutions vers les cases avec un maximum de solutions, permet de minimiser sensiblement l'exploration des possibilités.
	 *
	 *\return Le nombre de valeurs possibles pour la case choisie.
	 */
	int nb_possibles (int i, int j);
	/** \fn bool resolutionTotale()
	 *
	 *\brief Organise la résolution intégrale de la grille de la partie. Crée la liste des cases à remplir, la trie par ordre de priorité, puis résout la grille en appelant la fonction de backtracking.
	 *
	 *\return True si la grille a été correctement remplie, False sinon.
	 */
	bool resolutionTotale();
	/** \fn void resolutionUneCase()
	 *
	 *\brief Remplie une case vide choisie aléatoirement avec une valeur correcte.
	 *
	 */
    void resolutionUneCase();
    /** \fn bool unicite()
	 *
	 *\brief Permet de vérifier si la grille créée n'a qu'une seule solution. Appelle estValide et estValide2, et compare les grilles obtenues. Si elles sont identiques on en déduit l'unicité.
	 *
	 *\return True si la grille est unique, False sinon.
	 */
	bool unicite();
	/** \fn bool difficulteGrille(int nbCaseEnMoins)
	 *
	 *\brief Permet de vider la grille du nombre de cases fourni en paramètre. Parcourt les cases aléatoirement et les supprime si la grille reste unique après suppression.
	 *
	 */
	void difficulteGrille(int nbCaseEnMoins);
	/** \fn bool ligneValide (int k, int i, int j)
	 *
	 *\brief Lorsque la grille est pleine, cette fonction permet de vérifier si la valeur k n'est pas deux fois dans la ligne i.
     *
     *\return True si la valeur k n'est qu'une fois dans la ligne i, False sinon.
     */
	bool ligneValide (int k, int i, int j);
	/** \fn bool colonneValide (int k, int i, int j)
	 *
	 *\brief Lorsque la grille est pleine, cette fonction permet de vérifier si la valeur k n'est pas deux fois dans la colonne j.
	 *
	 *\return True si la valeur k n'est qu'une fois dans la colonne j, False sinon.
	 */
	bool colonneValide (int k, int i, int j);
	/** \fn jouer()
	 *
	 *\brief Organise le déroulement de la partie à partir du moment où la grille de jeu est prête à l'emploi.
	 *
	 */
	void jouer();
private :
	bool finie;
	string nomJoueur;
	Grille grille;
};

#endif /* PARTIE_H_ */
