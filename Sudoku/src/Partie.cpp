/*
 * Partie.cpp
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Partie.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Case.h"
#include <cstdlib>
#include <ctime>
#include "Grille.h"
#include <stddef.h>
#include "List.h"

Partie::Partie(string nomJ ) {
	finie = false;
	nomJoueur = nomJ;
	Grille grille;

}


Partie::~Partie() {
	// TODO Auto-generated destructor stub
}

void Partie::initialiser(){
int i,j;
//int tab[9][9]={{8, 4, 3, 7, 6, 5, 2, 1, 9},{5, 6, 7, 2, 1, 9, 3, 8, 4},{1, 2, 9, 4, 3, 8, 5, 7, 6},{2, 7, 4, 3, 8, 1, 6, 9, 5},{6, 8, 1, 5, 9, 2, 7, 4, 3},{3, 9, 5, 6, 7, 4, 1, 2, 8},{7, 1, 8, 9, 5, 3, 4, 6, 2},{4, 5, 6, 8, 2, 7, 9, 3, 1},{9, 3, 2, 1, 4, 6, 8, 5, 7}};
//int tab[9][9]={{0, 4, 0, 0, 0, 5, 0, 0, 0},{0, 0, 0, 2, 1, 9, 3, 8, 4},{0, 0, 9, 0, 3, 8, 0, 7, 6},{0, 7, 0, 3, 0, 1, 0, 0, 0},{6, 0, 1, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 7, 4,0, 2, 0},{0, 1,0, 9, 0,0 , 0, 6, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0},{9, 0, 0, 0, 0, 6, 0, 0, 0}};
int tab[9][9]={{8, 4, 3, 7, 6, 5, 0, 1, 9},{5, 0, 7, 2, 1, 9, 3, 8, 4},{1, 2, 9, 4, 3, 8, 5, 7, 6},{2, 7, 4, 3, 8, 1, 6, 9, 5},{6, 8, 1, 5, 9, 2, 7, 4, 3},{3, 9, 5, 6, 7, 4, 1, 2, 8},{7, 1, 8, 9, 5, 3, 4, 6, 2},{4, 5, 6, 8, 2, 7, 9, 3, 1},{9, 3, 2, 1, 4, 6, 8, 5, 7}};

for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				grille.chgtValeur(i,j,tab[i][j]);
			}
	}

}

void Partie::permuter(){
	int temp;
	int c1, v1, c11, v11;
	int c2, v2, c22, v22;
	int c3, v3, c33, v33;
	vector<int> tabregion1;
	for (int x=0; x < 3; x++){
		tabregion1.push_back(x);
	}
	c1 = rand()%(tabregion1.size()-1);
	v1 = tabregion1.at(c1);
	tabregion1.erase(tabregion1.begin()+c1);
	c11 = rand()%(tabregion1.size()-1);
	v11 = tabregion1.at(c11);
	tabregion1.erase(tabregion1.begin()+c11);

	vector<int> tabregion2;
	for (int x=3; x < 6; x++){
		tabregion2.push_back(x);
	}
	c2 = rand()%(tabregion2.size()-1);
	v2 = tabregion2.at(c2);
	tabregion2.erase(tabregion2.begin()+c2);
	c22 = rand()%(tabregion2.size()-1);
	v22 = tabregion2.at(c22);
	tabregion2.erase(tabregion2.begin()+c22);

	vector<int> tabregion3;
	for (int x=6; x < 9; x++){
		tabregion3.push_back(x);
	}
	c3 = rand()%(tabregion3.size()-1);
	v3 = tabregion3.at(c3);
	tabregion3.erase(tabregion3.begin()+c3);
	c33 = rand()%(tabregion3.size()-1);
	v33 = tabregion3.at(c33);
	tabregion3.erase(tabregion3.begin()+c33);

	for (int t=0;t<9;t++){
		temp = grille.obtenirValeur(t,v1);
		grille.chgtValeur(t,v1,grille.obtenirValeur(t,v11));
		grille.chgtValeur(t,v11,temp);
	}
	for (int t=0;t<9;t++){
		temp = grille.obtenirValeur(t,v2);
		grille.chgtValeur(t,v2,grille.obtenirValeur(t,v22));
		grille.chgtValeur(t,v22,temp);
	}
	for (int t=0;t<9;t++){
		temp = grille.obtenirValeur(t,v3);
		grille.chgtValeur(t,v3,grille.obtenirValeur(t,v33));
		grille.chgtValeur(t,v33,temp);
	}
}

bool Partie::ligneOk (int k, int i){
    for (int j=0; j < 9; j++)
        if (grille.obtenirValeur(i,j) == k)
            return false;
    return true;
}

bool Partie::colonneOk (int k, int j){
    for (int i=0; i < 9; i++)
        if (grille.obtenirValeur(i,j) == k)
            return false;
    return true;
}

bool Partie::regionOk (int k, int i, int j)
{
    int iR = i-(i%3);  //valeur de la ligne la plus haute de la region de la case
    int jR = j-(j%3);  //valeur de la colonne la plus � gauche de la region de la case
    for (i=iR; i < iR+3; i++)
        for (j=jR; j < jR+3; j++)  //parcours de la region en partant de la case en haut a gauche
            if (grille.obtenirValeur(i,j) == k)
                return false;
    return true;
}


bool Partie::estValide (Grille lagrille, LIST* position){
    // Si la liste est vide (fin de liste)
    if (position == NULL)
        return true;

    int i = position->i, j = position->j;

    for (int k=1; k <= 9; k++)
    {
        if ( ligneOk(k,i) && colonneOk(k,j) && regionOk(k,i,j) )
        {
            lagrille.chgtValeur(i,j,k);

            if ( estValide(lagrille,position->next) )
                return true;
        }
    }
    lagrille.chgtValeur(i,j,0);

    return false;
}

bool Partie::estValide2 (Grille lagrille, LIST* position){
    // Si la liste est vide (fin de liste)
    if (position == NULL)
        return true;

    int i = position->i, j = position->j;

    for (int k=9; k >=1; k--)
    {
        if ( ligneOk(k,i) && colonneOk(k,j) && regionOk(k,i,j) )
        {
            lagrille.chgtValeur(i,j,k);

            if ( estValide2(lagrille,position->next) )
                return true;
        }
    }
    lagrille.chgtValeur(i,j,0);

    return false;
}


// Calcule le nombre de valeurs possibles pour une case vide
int Partie::nb_possibles (int i, int j){
    int nb_poss = 0;
    for (int k=0; k < 9; k++)
        if ( ligneOk(k,i) && colonneOk(k,j) && regionOk(k,i,j) )
            nb_poss++;
    return nb_poss;
}


bool Partie::unicite(){
	bool unique = false;
	string sol="sol";
	string sol2="sol2";
	Partie solution(sol);
	Partie solution2(sol2);
    // cr�e et remplit une liste pour les cases vides � visiter
    LIST* positions = NULL;
    for (int i=0; i < 9; i++){
        for (int j=0; j < 9; j++){
        	solution.grille.chgtValeur(i,j,grille.obtenirValeur(i,j));
    		solution2.grille.chgtValeur(i,j,grille.obtenirValeur(i,j));
            if ( grille.obtenirValeur(i,j) == 0 )
                liste_cons ( &positions, i, j, nb_possibles(i, j) );
        }
	}
    // Trie la liste (ordre croissant)
    positions = list_sort (positions);

    // Appelle la fonction de backtracking r�cursive estValide()
    bool ret1 = estValide (solution.grille,positions);
    bool ret2= estValide2(solution2.grille,positions);
    if((ret1 ==true)&&(ret2==true)){
    	for (int i=0; i < 9; i++){
            for (int j=0; j < 9; j++){
            	if(solution.grille.obtenirValeur(i,j)==solution2.grille.obtenirValeur(i,j))
            		unique=true;
            	else
            		unique=false;
            }
    	}
    }
    if (unique==true){
    	bool ret = estValide(grille,positions);
    }
    // D�truit la liste
    liste_delete (&positions);
    // retourne le resultat
    return unique;
}


bool Partie::resolution(){
    // cr�e et remplit une liste pour les cases vides � visiter
    LIST* positions = NULL;
    for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
            if ( grille.obtenirValeur(i,j) == 0 )
                liste_cons ( &positions, i, j, nb_possibles(i, j) );

    // Trie la liste (ordre croissant)
    positions = list_sort (positions);

    // Appelle la fonction de backtracking r�cursive estValide()
    bool ret = estValide (grille,positions);
    // D�truit la liste
    liste_delete (&positions);
    // retourne le resultat
    return ret;
}


void Partie::jouer(){
	int ligne, colonne, valeur, i,j, temp, nbzeros;
	bool choixOk;
	Grille grilleDeBase;
	for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				temp = grille.obtenirValeur(i,j);
				grilleDeBase.chgtValeur(i,j,temp);
			}
	}

	while(finie == false){
		grille.afficher();
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		choixOk = false;
		while(choixOk == false){
			do{
				std::cout << "Quelle ligne voulez-vous modifier? " << std::endl;
				std::cin >> ligne;
			}while((ligne<1)||(ligne>9));

			do{
				std::cout << "Quelle colonne voulez-vous modifier? " << std::endl;
				std::cin >> colonne;
				if((grilleDeBase.obtenirValeur(ligne-1,colonne-1))!=0){
					cout << "Vous ne pouvez pas modifier cette case" << std::endl;
				}
			}while((colonne<1)||(colonne>9)||((grilleDeBase.obtenirValeur(ligne-1,colonne-1))!=0));

			do{
			std::cout << "Quelle valeur souhaitez-vous ins�rer? " << std::endl;
			std::cin >> valeur;
			}while((valeur<1)||(valeur>9));

			choixOk = true;
		}
		grille.chgtValeur(ligne-1,colonne-1,valeur);
		std::cout << "############################################# " << std::endl;


		nbzeros = 0;           ////La on regarde si toute la grille est pleine pour mettre fin au jeu
		for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				if (grille.obtenirValeur(i,j)==0){
					nbzeros= nbzeros+1;
				}
			}
		}
		if(nbzeros == 0){//grille pleine -> fin du jeu
			finie = true;
		}
	}

	std::cout << "############################################# " << std::endl;
	std::cout << "Vous avez rempli le sudoku BLA BLA BLA BLA, bravo " << nomJoueur << std::endl;

}

