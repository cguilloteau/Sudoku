/** \class Partie
* \brief Permet d'organiser le d�roulement d'une partie de Sudoku
* \author Zo�, Claire, Fabrice, Tarek
* \version 1.0
* \date Mai 2017
* \bug Aucun bug
* \warning Aucun warning
*
* Compos�e d'un nom de Joueur, une grille et un bool�en qui signale si la partie est termin�e.
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
	 *\brief Constructeur permettant de cr�er une partie. L'attribut finie est initialis� � Faux. Le nom du Joueur et la taille de la grille sont initialis�s � partir des param�tres en entr�e.
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
     *\brief Permet de permuter 2 colonnes de la m�me r�gion choisies al�atoirement, pour chaque r�gion.
     *
     */
	void permuterColonnes();
	/** \fn permuterLignes()
	 *
	 *\brief Permet de permuter 2 lignes de la m�me r�gion choisies al�atoirement, pour chaque r�gion.
	 *
	 */
	void permuterLignes();
	/** \fn initialiser()
	 *
	 *\brief Permet de remplir la grille de la partie � partir d'un tableau initial comportant une grille r�solue. Cette grille initiale sera modifi�e plus tard.
	 *
	 */
	void initialiser();
	/** \fn bool colonneOk (int k, int j)
	 *
	 *\brief Lorsque la grille n'est pas encore pleine, cette fonction permet de v�rifier si la valeur k n'est pas encore dans la colonne j.
	 *
	 *\return True si la valeur k n'est pas encore dans la colonne j, False sinon.
	 */
	bool colonneOk (int k, int j);
	/** \fn bool ligneOk (int k, int i)
	 *
	 *\brief Lorsque la grille n'est pas encore pleine, cette fonction permet de v�rifier si la valeur k n'est pas encore dans la ligne i.
     *
     *\return True si la valeur k n'est pas encore dans la ligne i, False sinon.
     */
	bool ligneOk (int k, int i);
	/** \fn bool regionOk (int k, int i, int j)
	 *
	 *\brief Lorsque la grille n'est pas encore pleine, cette fonction permet de v�rifier si la valeur k n'est pas encore dans la r�gion de la case plac�e � la ligne i et colonne j.
     *
     *\return True si la valeur k n'est pas encore dans la r�gion, False sinon.
     */
	bool regionOk (int k, int i, int j);
	/** \fn bool ligneValide (int k, int i, int j)
	 *
	 *\brief Lorsque la grille est pleine, cette fonction permet de v�rifier si la valeur k n'est pas deux fois dans la ligne i.
     *
     *\return True si la valeur k n'est qu'une fois dans la ligne i, False sinon.
     */
	bool estValide (Grille lagrille, LIST* position);
	/** \fn bool  estValide2(Grille lagrille, LIST* position)
	 *
	 *\brief M�me r�le que estValide(Grille lagrille, LIST* position), mais en proc�dant dans un ordre diff�rent pour le remplissage.
	 *
	 *\return True si la grille a �t� correctement remplie, False sinon.
	 */
	bool estValide2 (Grille lagrille, LIST* position);
	/** \fn int nb_possibles (int i, int j)
	 *
	 *\brief Calcule le nombre de valeurs possibles pour la case � la ligne i et colonne j. Permet de trier, plus tard, les cases dans un ordre de priorit�.
            Effectuer le backtracking depuis les cases avec un minimum de solutions vers les cases avec un maximum de solutions, permet de minimiser sensiblement l'exploration des possibilit�s.
	 *
	 *\return Le nombre de valeurs possibles pour la case choisie.
	 */
	int nb_possibles (int i, int j);
	/** \fn bool resolutionTotale()
	 *
	 *\brief Organise la r�solution int�grale de la grille de la partie. Cr�e la liste des cases � remplir, la trie par ordre de priorit�, puis r�sout la grille en appelant la fonction de backtracking.
	 *
	 *\return True si la grille a �t� correctement remplie, False sinon.
	 */
	bool resolutionTotale();
	/** \fn void resolutionUneCase()
	 *
	 *\brief Remplie une case vide choisie al�atoirement avec une valeur correcte.
	 *
	 */
    void resolutionUneCase();
    /** \fn bool unicite()
	 *
	 *\brief Permet de v�rifier si la grille cr��e n'a qu'une seule solution. Appelle estValide et estValide2, et compare les grilles obtenues. Si elles sont identiques on en d�duit l'unicit�.
	 *
	 *\return True si la grille est unique, False sinon.
	 */
	bool unicite();
	/** \fn bool difficulteGrille(int nbCaseEnMoins)
	 *
	 *\brief Permet de vider la grille du nombre de cases fourni en param�tre. Parcourt les cases al�atoirement et les supprime si la grille reste unique apr�s suppression.
	 *
	 */
	void difficulteGrille(int nbCaseEnMoins);
	/** \fn bool ligneValide (int k, int i, int j)
	 *
	 *\brief Lorsque la grille est pleine, cette fonction permet de v�rifier si la valeur k n'est pas deux fois dans la ligne i.
     *
     *\return True si la valeur k n'est qu'une fois dans la ligne i, False sinon.
     */
	bool ligneValide (int k, int i, int j);
	/** \fn bool colonneValide (int k, int i, int j)
	 *
	 *\brief Lorsque la grille est pleine, cette fonction permet de v�rifier si la valeur k n'est pas deux fois dans la colonne j.
	 *
	 *\return True si la valeur k n'est qu'une fois dans la colonne j, False sinon.
	 */
	bool colonneValide (int k, int i, int j);
	/** \fn jouer()
	 *
	 *\brief Organise le d�roulement de la partie � partir du moment o� la grille de jeu est pr�te � l'emploi.
	 *
	 */
	void jouer();
private :
	bool finie;
	string nomJoueur;
	Grille grille;
};

#endif /* PARTIE_H_ */
