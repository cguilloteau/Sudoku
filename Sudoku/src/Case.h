/** \class Case
* \brief Représente une case de la grille
* \author Zoé, Claire, Fabrice, Tarek
* \version 1.0
* \date Mai 2017
* \bug Aucun bug
* \warning Aucun warning
*
* Permet de representer une case de la grille en la décrivant selon sa ligne, colonne et région. Elle reçoit également une valeur entre 1 et 9 ou 1 et 16, selon la taille du sudoku choisie.
*/

#include <iostream>
#include<string>

#ifndef CASE_H
#define CASE_H

using namespace std;

class Case
{
    public:
		/** \fn Case()
		 *
		 *\brief Constructeur permettant de créer une case, initialisée avec des 0 dans tous ses attributs.
		 *
		 */
        Case();
        /** \fn virtual ~Case()
         *
         *\brief Destructeur de case.
         *
         */
        virtual ~Case();
        /** \fn setColonne(const int ac)
         *
       	 *\brief Setteur permettant de modifier la valeur de l'attribut Colonne pour un objet Case.
         *
         */
        void setColonne(const int ac);
        /** \fn setLigne(const int dow)
         *
         *\brief Setteur permettant de modifier la valeur de l'attribut Ligne pour un objet Case.
         *
         */
        void setLigne(const int dow);
        /** \fn setRegion(int lig, int col, int tailleGrille)
         *
         *\brief Setteur permettant de modifier la valeur de l'attribut Région pour un objet Case. La région est calculée à partir de la ligne et la colonne de la case.
         *
         */
        void setRegion(int lig, int col, int tailleGrille);
        /** \fn setValeur(const int val)
         *
         *\brief Setteur permettant de modifier la valeur de l'attribut Valeur pour un objet Case.
         *
         */
        void setValeur(const int val);
        /** \fn int getColonne()const
        *
        *\brief Getteur permettant de récupérer la valeur de l'attribut Colonne pour un objet Case.
        *
        *\return La colonne de la Case
        */
        int getColonne()const;
        /** \fn int getLigne()const
         *
         *\brief Getteur permettant de récupérer la valeur de l'attribut Ligne pour un objet Case.
         *
         *\return La ligne de la Case
         */
        int getLigne()const;
        /** \fn int getRegion()const
         *
         *\brief Getteur permettant de récupérer la valeur de l'attribut Region pour un objet Case.
         *
         *\return La région de la Case
         */
        int getRegion()const;
        /** \fn int getValeur()const
         *
         *\brief Getteur permettant de récupérer la valeur de l'attribut Valeur pour un objet Case.
         *
         *\return La valeur dans la Case
         */
        int getValeur()const;

    protected:
    private:
        int colonne;
        int ligne;
        int region;
        int valeur;
};

#endif // Case_H
