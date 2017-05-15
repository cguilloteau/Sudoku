/*
 * List.cpp
 *
 *  Created on: 2 mai 2017
 *      Author: taljijakli
 */

#include "List.h"
#include <stddef.h>
#include <stdlib.h>

// retourne un nouvel élément initialisé
static LIST* new_elem (int i, int j, int n){
    LIST* ret = (LIST*) malloc(sizeof* ret);
    if (ret != NULL)
        ret->i = i, ret->j = j, ret->nbValeursPossibles = n, ret->next = NULL;
    return ret;
}

// supprime intégralement une liste chainée
void liste_delete (LIST** list){
    LIST* tmp;
    while ( (tmp = *list) != NULL)
        *list = (*list)->next, free(tmp);
}

// ajoute en tête
void liste_cons (LIST** list, int i, int j, int n){
    LIST* elem = new_elem (i, j, n);
    if (elem != NULL)
        elem->next = *list, *list = elem;
}

// insertion dans une liste triée
void insertion (LIST** list, LIST* elem){
    if (*list == NULL)
        *list = elem, elem->next = NULL;
    else if ((*list)->nbValeursPossibles < elem->nbValeursPossibles)
        insertion (&(*list)->next, elem);
    else
        elem->next = *list, *list = elem;
}

// tri insertion sur liste chainée
LIST* list_sort (LIST* list){
    LIST *curr, *list2 = NULL, *tmp;
    for (curr = list; curr != NULL; curr = tmp)
    {
        tmp = curr->next;
        insertion (&list2, curr);
    }
    return list2;
}
