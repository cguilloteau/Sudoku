/** \class List
* \brief Repr�sente une liste de positions de cases
* \author Zo�, Claire, Fabrice, Tarek
* \version 1.0
* \date Mai 2017
* \bug Aucun bug
* \warning Aucun warning
*
* Permet de g�n�rer une liste de cases vides, qui enregistre les coordonn�es et le nombre de valeurs possibles de chaque case. On triera la liste en ordre croissant, puis on la passe en argument de notre fonction de backtracking.
*/

#ifndef LIST_H
#define LIST_H


typedef struct list
{
    int i, j;
    int nbValeursPossibles;
    struct list *next;
} LIST;


static LIST* new_elem (int i, int j, int n);
void liste_delete (LIST** list);
void liste_cons (LIST** list, int i, int j, int n);
void insertion (LIST** list, LIST* elem);
LIST* list_sort (LIST* list);


#endif // LIST_H
