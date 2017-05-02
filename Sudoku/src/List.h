/*
 * List.h
 *
 *  Created on: 2 mai 2017
 *      Author: taljijakli
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
