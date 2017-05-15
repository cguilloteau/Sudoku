/** \class List
* \brief Repr�sente une liste de positions de cases
* \author Zo�, Claire, Fabrice, Tarek
* \version 1.0
* \date Mai 2017
* \bug Aucun bug
* \warning Aucun warning
*
* Permet de g�n�rer une liste de cases vides, qui enregistre les coordonn�es et le nombre de valeurs possibles de chaque case. On triera la liste en ordre croissant (en fonction du nombre de valeurs possibles par case), puis on la passe en argument de notre fonction de backtracking.
*/

#ifndef LIST_H
#define LIST_H


typedef struct list
{
    int i, j;
    int nbValeursPossibles;
    struct list *next;
} LIST;


/** \fn LIST* new_elem (int i, int j, int n)
*
*\brief  un nouvel �l�ment initialis�
*
*/

static LIST* new_elem (int i, int j, int n);

/** \fn liste_delete(LIST** list)
*
*\brief fonction permettant de supprimer int�gralment une liste cha�n�e
*
*/


void liste_delete (LIST** list);


/** \fn liste_cons (LIST** list, int i, int j, int n)
*
*\brief fonction permettant d'ajouter en t�te un �l�ment
*
*/

void liste_cons (LIST** list, int i, int j, int n);

/** \fn insertion (LIST** list, LIST* elem)
*
*\brief fonction permettant d'effectuer un tri par insertion sur  une liste cha�n�e.
*
*/

void insertion (LIST** list, LIST* elem);
LIST* list_sort (LIST* list);



#endif // LIST_H
