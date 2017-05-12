/*
 * Partie.cpp
 *
 *  Created on: 27 avr. 2017
 *      Author: taljijakli
 */

#include "Partie.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "Case.h"
#include <cstdlib>
#include <ctime>
#include "Grille.h"
#include <stddef.h>
#include "List.h"


Partie::Partie(string nomJ, int laTaille) {
	finie = false;
	nomJoueur = nomJ;
	grille.allocationTaille(laTaille);
}


Partie::~Partie() {
	// TODO Auto-generated destructor stub
}

void Partie::initialiser(){
int i,j;
int tabClassique[9][9]={{8, 4, 3, 7, 6, 5, 2, 1, 9},{5, 6, 7, 2, 1, 9, 3, 8, 4},{1, 2, 9, 4, 3, 8, 5, 7, 6},{2, 7, 4, 3, 8, 1, 6, 9, 5},{6, 8, 1, 5, 9, 2, 7, 4, 3},{3, 9, 5, 6, 7, 4, 1, 2, 8},{7, 1, 8, 9, 5, 3, 4, 6, 2},{4, 5, 6, 8, 2, 7, 9, 3, 1},{9, 3, 2, 1, 4, 6, 8, 5, 7}};
int tabGrand[16][16]={{8, 9, 6, 4, 15, 5, 11, 10, 3,14,1,13,12,7,2,16},{7,13,3,2,4,14,1,8,15,12,16,5,10,9,6,11},{14,10,1,12,7,16,3,2,6,11,4,9,5,8,13,15},{15,5,16,11,12,13,9,6,8,2,10,7,3,4,1,14},{11,6,2,5,3,4,10,15,1,16,12,8,9,13,14,7},{4,7,14,3,13,2,16,1,10,6,9,11,8,12,15,5},{9,12,13,16,6,8,5,11,2,15,7,14,1,10,4,3},{10,15,8,1,9,12,7,14,4,13,5,3,2,16,11,6},{13,8,15,9,14,1,12,5,11,7,2,4,16,6,3,10},{3,11,5,6,16,7,13,4,9,10,15,1,14,2,12,8},{2,16,10,14,11,15,6,3,5,8,13,12,4,1,7,9},{12,1,4,7,2,10,8,9,14,3,6,16,15,11,5,13},{6,2,7,13,10,9,14,16,12,1,3,15,11,5,8,4},{5,4,12,8,1,3,15,7,16,9,11,6,13,14,10,2},{1,14,9,15,5,11,2,13,7,4,8,10,6,3,16,12},{16,3,11,10,8,6,4,12,13,5,14,2,7,15,9,1}};
if(grille.getTaille()==9)
	for (i=0;i<9;i++){
			for (j=0;j<9;j++){
				grille.chgtValeur(i,j,tabClassique[i][j]);
			}
	}
if(grille.getTaille()==16)
	for (i=0;i<16;i++){
			for (j=0;j<16;j++){
				grille.chgtValeur(i,j,tabGrand[i][j]);
			}
	}

}


void Partie::permuterColonnes(){
	int temp;
	int c1, c11;
	int c2, c22;
	int c3, c33;
	int c4, c44;

	if(grille.getTaille()==9){
		vector<int> tabregion1;   //vecteur qui va permettre le tirage au sort entre les 3 premières colonnes (quand  on en tire 1 on le supprime pour le second tirage)
		for (int x=0; x < 3; x++){
			tabregion1.push_back(x);
		}
		std::random_shuffle (tabregion1.begin(), tabregion1.end() );
		c1=tabregion1.at(0);
		c11=tabregion1.at(1);


		vector<int> tabregion2;
		for (int x=3; x < 6; x++){
			tabregion2.push_back(x);
		}
		std::random_shuffle (tabregion2.begin(), tabregion2.end() );
		c2=tabregion2.at(0);
		c22=tabregion2.at(1);

		vector<int> tabregion3;
		for (int x=6; x < 9; x++){
			tabregion3.push_back(x);
		}
		std::random_shuffle (tabregion3.begin(), tabregion3.end() );
		c3=tabregion3.at(0);
		c33=tabregion3.at(1);


		for (int t=0;t<grille.getTaille();t++){
			temp = grille.obtenirValeur(t,c1);
			grille.chgtValeur(t,c1,grille.obtenirValeur(t,c11));
			grille.chgtValeur(t,c11,temp);
		}
		for (int t=0;t<grille.getTaille();t++){
			temp = grille.obtenirValeur(t,c2);
			grille.chgtValeur(t,c2,grille.obtenirValeur(t,c22));
			grille.chgtValeur(t,c22,temp);
		}
		for (int t=0;t<grille.getTaille();t++){
			temp = grille.obtenirValeur(t,c3);
			grille.chgtValeur(t,c3,grille.obtenirValeur(t,c33));
			grille.chgtValeur(t,c33,temp);
		}
	}

	if(grille.getTaille()==16){
		vector<int> tabregion1;   //vecteur qui va permettre le tirage au sort entre les 4 colonnes de la région 1 (quand  on en tire 1 on le supprime pour le second tirage)
				for (int x=0; x < 4; x++){
					tabregion1.push_back(x);
				}
				std::random_shuffle (tabregion1.begin(), tabregion1.end() );
				c1=tabregion1.at(0);
				c11=tabregion1.at(1);


				vector<int> tabregion2;
				for (int x=4; x < 8; x++){
					tabregion2.push_back(x);
				}
				std::random_shuffle (tabregion2.begin(), tabregion2.end() );
				c2=tabregion2.at(0);
				c22=tabregion2.at(1);

				vector<int> tabregion3;
				for (int x=8; x < 12; x++){
					tabregion3.push_back(x);
				}
				std::random_shuffle (tabregion3.begin(), tabregion3.end() );
				c3=tabregion3.at(0);
				c33=tabregion3.at(1);

				vector<int> tabregion4;
					for (int x=12; x < 16; x++){
						tabregion4.push_back(x);
					}
					std::random_shuffle (tabregion4.begin(), tabregion4.end() );
					c4=tabregion4.at(0);
					c44=tabregion4.at(1);

				for (int t=0;t<grille.getTaille();t++){
					temp = grille.obtenirValeur(t,c1);
					grille.chgtValeur(t,c1,grille.obtenirValeur(t,c11));
					grille.chgtValeur(t,c11,temp);
				}
				for (int t=0;t<grille.getTaille();t++){
					temp = grille.obtenirValeur(t,c2);
					grille.chgtValeur(t,c2,grille.obtenirValeur(t,c22));
					grille.chgtValeur(t,c22,temp);
				}
				for (int t=0;t<grille.getTaille();t++){
					temp = grille.obtenirValeur(t,c3);
					grille.chgtValeur(t,c3,grille.obtenirValeur(t,c33));
					grille.chgtValeur(t,c33,temp);
				}
				for (int t=0;t<grille.getTaille();t++){
					temp = grille.obtenirValeur(t,c4);
					grille.chgtValeur(t,c4,grille.obtenirValeur(t,c44));
					grille.chgtValeur(t,c44,temp);
				}
	}
}


void Partie::permuterLignes(){
	int temp;
	int l1, l11;
	int l2, l22;
	int l3, l33;
	int l4, l44;
	if(grille.getTaille()==9){
		vector<int> tabregion1;   //vecteur qui va permettre le tirage au sort entre les 3 colonnes de la région 1 (quand  on en tire 1 on le supprime pour le second tirage)
		for (int x=0; x < 3; x++){
			tabregion1.push_back(x);
		}
		std::random_shuffle (tabregion1.begin(), tabregion1.end() );
		l1=tabregion1.at(0);
		l11=tabregion1.at(1);


		vector<int> tabregion2;
		for (int x=3; x < 6; x++){
			tabregion2.push_back(x);
		}
		std::random_shuffle (tabregion2.begin(), tabregion2.end() );
		l2=tabregion2.at(0);
		l22=tabregion2.at(1);

		vector<int> tabregion3;
		for (int x=6; x < 9; x++){
			tabregion3.push_back(x);
		}
		std::random_shuffle (tabregion3.begin(), tabregion3.end() );
		l3=tabregion3.at(0);
		l33=tabregion3.at(1);


		for (int t=0;t<9;t++){
			temp = grille.obtenirValeur(l1,t);
			grille.chgtValeur(l1,t,grille.obtenirValeur(l11,t));
			grille.chgtValeur(l11,t,temp);
		}
		for (int t=0;t<9;t++){
			temp = grille.obtenirValeur(l2,t);
			grille.chgtValeur(l2,t,grille.obtenirValeur(l22,t));
			grille.chgtValeur(l22,t,temp);
		}
		for (int t=0;t<9;t++){
			temp = grille.obtenirValeur(l3,t);
			grille.chgtValeur(l3,t,grille.obtenirValeur(l33,t));
			grille.chgtValeur(l33,t,temp);
		}
	}

	if(grille.getTaille()==16){
		vector<int> tabregion1;   //vecteur qui va permettre le tirage au sort entre les 4 lignes de la région 1 (quand  on en tire 1 on le supprime pour le second tirage)
		for (int x=0; x < 4; x++){
			tabregion1.push_back(x);
		}
		std::random_shuffle (tabregion1.begin(), tabregion1.end() );
		l1=tabregion1.at(0);
		l11=tabregion1.at(1);

		vector<int> tabregion2;
		for (int x=4; x < 8; x++){
			tabregion2.push_back(x);
		}
		std::random_shuffle (tabregion2.begin(), tabregion2.end() );
		l2=tabregion2.at(0);
		l22=tabregion2.at(1);

		vector<int> tabregion3;
		for (int x=8; x < 12; x++){
			tabregion3.push_back(x);
		}
		std::random_shuffle (tabregion3.begin(), tabregion3.end() );
		l3=tabregion3.at(0);
		l33=tabregion3.at(1);

		vector<int> tabregion4;
		for (int x=12; x < 16; x++){
			tabregion4.push_back(x);
		}
		std::random_shuffle (tabregion4.begin(), tabregion4.end() );
		l4=tabregion4.at(0);
		l44=tabregion4.at(1);

		for (int t=0;t<grille.getTaille();t++){
			temp = grille.obtenirValeur(l1,t);
			grille.chgtValeur(l1,t,grille.obtenirValeur(l11,t));
			grille.chgtValeur(l11,t,temp);
		}
		for (int t=0;t<grille.getTaille();t++){
			temp = grille.obtenirValeur(l2,t);
			grille.chgtValeur(l2,t,grille.obtenirValeur(l22,t));
			grille.chgtValeur(l22,t,temp);
		}
		for (int t=0;t<grille.getTaille();t++){
			temp = grille.obtenirValeur(l3,t);
			grille.chgtValeur(l3,t,grille.obtenirValeur(l33,t));
			grille.chgtValeur(l33,t,temp);
		}
		for (int t=0;t<grille.getTaille();t++){
			temp = grille.obtenirValeur(l4,t);
			grille.chgtValeur(l4,t,grille.obtenirValeur(l44,t));
			grille.chgtValeur(l44,t,temp);
		}
	}
}

bool Partie::ligneOk (int k, int i){      //Check si la valeur n'est pas encore dans la ligne (grille non finie)
    for (int j=0; j < grille.getTaille(); j++)
        if (grille.obtenirValeur(i,j) == k)
            return false;
    return true;
}

bool Partie::colonneOk (int k, int j){  //check  si la valeur n'est pas encore dans la colonne (grille non finie)
    for (int i=0; i < grille.getTaille(); i++)
        if (grille.obtenirValeur(i,j) == k)
            return false;
    return true;
}

bool Partie::regionOk (int k, int i, int j){   //check  si la valeur n'est pas encore dans la région (grille non finie)
	bool retour=true;
	if(grille.getTaille()==9){
		int iR = i-(i%3);  //valeur de la ligne la plus haute de la region de la case
		int jR = j-(j%3);  //valeur de la colonne la plus à gauche de la region de la case
		for (i=iR; i < iR+3; i++)
			for (j=jR; j < jR+3; j++)  //parcours de la region en partant de la case en haut a gauche
				if (grille.obtenirValeur(i,j) == k)
					retour= false;
	}
	if(grille.getTaille()==16){
		int iR = i-(i%4);  //valeur de la ligne la plus haute de la region de la case
		int jR = j-(j%4);  //valeur de la colonne la plus à gauche de la region de la case
		for (i=iR; i < iR+4; i++)
			for (j=jR; j < jR+4; j++)  //parcours de la region en partant de la case en haut a gauche
				if (grille.obtenirValeur(i,j) == k)
					retour= false;
	}
	return retour;
}


bool Partie::ligneValide (int k, int i, int j){  //Check si la valeur n'est pas ailleurs dans la ligne (grille finie)
	bool check = true ;
    for (int c=0; c < grille.getTaille(); c++){
    	if(c!=j){      //on vérifie toutes les colonnes de la ligne sauf celle que l'on vérifie
    		if (grille.obtenirValeur(i,c) == k)
    			check= false;
    	}
    }
    return check;
}

bool Partie::colonneValide (int k, int i, int j){  //check  si la valeur n'est pas ailleurs dans la colonne (grille finie)
	bool check = true;
    for (int l=0; l < grille.getTaille(); l++){
    	if(l!=i){		//on vérifie toutes les lignes de la colonne sauf celle que l'on vérifie
    		if (grille.obtenirValeur(l,j) == k)
            check = false;
    	}
    }
    return check;
}



bool Partie::estValide (Grille lagrille, LIST* position){ //permet de résoudre la grille
    // Si la liste est vide (fin de liste)
    if (position == NULL)
        return true;

    int i = position->i, j = position->j;

    for (int k=1; k <= grille.getTaille(); k++)
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

bool Partie::estValide2 (Grille lagrille, LIST* position){ //permet de résoudre la grille d'une manière différente pour voir si au moins deux solutions existent
    // Si la liste est vide (fin de liste)
    if (position == NULL)
        return true;

    int i = position->i, j = position->j;

    for (int k=grille.getTaille(); k >=1; k--)
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
    for (int k=0; k < grille.getTaille(); k++)
        if ( ligneOk(k,i) && colonneOk(k,j) && regionOk(k,i,j) )
            nb_poss++;
    return nb_poss;
}


bool Partie::unicite(){
	bool unique = false;
	Partie solution("sol",grille.getTaille());
	Partie solution2("sol2",grille.getTaille());
    // crée et remplit une liste pour les cases vides à visiter
    LIST* positions = NULL;
    for (int i=0; i < grille.getTaille(); i++){
        for (int j=0; j < grille.getTaille(); j++){
        	solution.grille.chgtValeur(i,j,grille.obtenirValeur(i,j));
    		solution2.grille.chgtValeur(i,j,grille.obtenirValeur(i,j));
            if ( grille.obtenirValeur(i,j) == 0 )
                liste_cons ( &positions, i, j, nb_possibles(i, j) );
        }
	}
    // Trie la liste (ordre croissant)
    positions = list_sort (positions);

    // Appelle la fonction de backtracking récursive estValide()
    bool ret1 = estValide (solution.grille,positions);
    bool ret2= estValide2(solution2.grille,positions);
    if((ret1 ==true)&&(ret2==true)){
    	for (int i=0; i < grille.getTaille(); i++){
            for (int j=0; j < grille.getTaille(); j++){
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
    // Détruit la liste
    liste_delete (&positions);
    // retourne le resultat
    return unique;
}

void Partie::difficulteGrille(int nbCaseEnMoins){
    int caseEnleve = 0;  //compteur de case qu'on enleve au fur et a mesure
    int iGrille, jGrille;
    bool uniciteOk= false;
	Partie testVidage("test",grille.getTaille());

    std::vector<int> listeCase;
    int nbCases = (grille.getTaille()*grille.getTaille());  //nombre de cases = taille * taille
    for (int i=0; i<nbCases; ++i)
    	listeCase.push_back(i); // vecteur de 0 à nbCases-1 représentant les cases
    std::random_shuffle ( listeCase.begin(), listeCase.end() ); //melange les cases pour le tirage au sort

    for (unsigned x=0; x<listeCase.size(); x++){
        if(caseEnleve<nbCaseEnMoins){
            iGrille = (listeCase.at(x) / grille.getTaille());    //on recupere ligne et colonne dans la grille pour la case tirée
            jGrille = (listeCase.at(x) % grille.getTaille());

            testVidage.grille.copier(grille);  //on copie la grille du jeu dans la grille de test
            testVidage.grille.chgtValeur(iGrille,jGrille,0);
            uniciteOk = testVidage.unicite();
            if (uniciteOk==true){
                grille.chgtValeur(iGrille,jGrille,0);
                caseEnleve=caseEnleve+1;
            }
        }
    }
}

bool Partie::resolutionTotale(){
    // crée et remplit une liste pour les cases vides à visiter
    LIST* positions = NULL;
    for (int i=0; i < grille.getTaille(); i++)
        for (int j=0; j < grille.getTaille(); j++)
            if ( grille.obtenirValeur(i,j) == 0 )
                liste_cons ( &positions, i, j, nb_possibles(i, j) );

    // Trie la liste (ordre croissant)
    positions = list_sort (positions);      //la reponse donnée sera la case avec le moins de possibilités
    // Appelle la fonction de backtracking récursive estValide()
    bool ret = estValide (grille,positions);
    // Détruit la liste
    liste_delete (&positions);
    // retourne le resultat
    return ret;
}

void Partie::resolutionUneCase(){
    bool sudokuCorrect=false;
    int caseAjoute=0;
    int iGrille,jGrille;
    Partie partieTemp("temp",grille.getTaille());

    partieTemp.grille.copier(grille);   //on copie la grille du jeu dans la grille temporaire
    sudokuCorrect = partieTemp.resolutionTotale();
    if(sudokuCorrect==true){
        std::vector<int> listeCase;
        int nbCases = grille.getTaille()*grille.getTaille();
        for (int i=0; i<nbCases; ++i)
            listeCase.push_back(i); // vecteur de 0 à nbCases-1 représentant les cases
        std::random_shuffle ( listeCase.begin(), listeCase.end() ); //melange les cases pour le tirage au sort

        for (unsigned x=0; x<listeCase.size(); x++){
            if(caseAjoute<1){
                iGrille = (listeCase.at(x) / grille.getTaille());    //on recupere ligne et colonne dans la grille pour la case tirée
                jGrille = (listeCase.at(x) % grille.getTaille());
                if((partieTemp.grille.obtenirValeur(iGrille,jGrille)!=grille.obtenirValeur(iGrille,jGrille))){
                    grille.chgtValeur(iGrille,jGrille,partieTemp.grille.obtenirValeur(iGrille,jGrille));
                    caseAjoute=caseAjoute+1;
                }

            }
        }
    }
}


void Partie::jouer(){
	int ligne=0, colonne, valeur, i,j, nbzeros, numeroCoup=0;
	bool choixOk;
	Grille grilleDeBase;   //sert à retenir les valeurs initiales du sudoku pour ne pas les modifier
	grilleDeBase.allocationTaille(grille.getTaille());

	Grille mesCoups[120]; //tableau de grille qui va recenser les coups joués pour revenir en arrière
	for(int c=0; c<120; c++)
		mesCoups[c].allocationTaille(grille.getTaille());

	Partie solutionFinale("solfinale",grille.getTaille());   //partie créée avec la meme grille initiale et résolue intégralement ensuite, afin de comparer la réponse correcte à celle du joueur
	grilleDeBase.copier(grille);

	solutionFinale.grille.copier(grille);
    solutionFinale.resolutionTotale();     //on a la grille finale correcte

    mesCoups[0].copier(grilleDeBase);  //on initialise le tableau (qui retient les grilles au fur et à mesure) avec la grille initiale
	while(finie == false){
		grille.afficher();
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		choixOk = false;
		while(choixOk == false){
			do{
				std::cout << "Quelle ligne voulez-vous modifier? (0 pour obtenir de l'aide/21 pour revenir en arrière)"<< std::endl;
				std::cin >> ligne;
				if(ligne==0){
					numeroCoup++;
					mesCoups[numeroCoup].copier(grille);
                    resolutionUneCase();
                    grille.afficher();
				}
				if(ligne==21){

					grille.copier(mesCoups[numeroCoup]);
					numeroCoup--;
                    grille.afficher();
				}
			}while((ligne<1)||(ligne>grille.getTaille()));

			do{
				std::cout << "Quelle colonne voulez-vous modifier? (0 pour changer de ligne)" << std::endl;
				std::cin >> colonne;
				if(colonne==0){
                    do{
                        std::cout << "Quelle ligne voulez-vous modifier? " << std::endl;
                        std::cin >> ligne;
                        }while((ligne<1)||(ligne>grille.getTaille()));
                    std::cout << "Quelle colonne voulez-vous modifier? " << std::endl;
                    std::cin >> colonne;
				}
				if((grilleDeBase.obtenirValeur(ligne-1,colonne-1))!=0){
					cout << "Vous ne pouvez pas modifier cette case" << std::endl;
				}
			}while((colonne<1)||(colonne>grille.getTaille())||((grilleDeBase.obtenirValeur(ligne-1,colonne-1))!=0));  //on vérifie que l'on ne change pas une des valeurs de la grille initiale

			do{
			std::cout << "Quelle valeur souhaitez-vous insérer? " << std::endl;
			std::cin >> valeur;
			}while((valeur<1)||(valeur>grille.getTaille()));

			choixOk = true;
		}
		numeroCoup++;
		mesCoups[numeroCoup].copier(grille);  //on recense avant le nouveau coup
		grille.chgtValeur(ligne-1,colonne-1,valeur);
		std::cout << "***************************************************** " << std::endl;
        std::cout << "" << std::endl;

		nbzeros = 0;           ////La on regarde si toute la grille est pleine pour mettre fin au jeu
		for (i=0;i<grille.getTaille();i++){
			for (j=0;j<grille.getTaille();j++){
				if (grille.obtenirValeur(i,j)==0){
					nbzeros= nbzeros+1;
				}
			}
		}
		if(nbzeros == 0){//grille pleine -> fin du jeu
			finie = true;
		}
	}

	bool different= false;

	std::cout << "***************************************************** " << std::endl;
	std::cout << "Vous avez rempli le sudoku, vérifions qu'il est correct" << std::endl;
	bool correct=true;
	for (i=0;i<grille.getTaille();i++){
        for (j=0;j<grille.getTaille();j++){
            if (grille.obtenirValeur(i,j)!=solutionFinale.grille.obtenirValeur(i,j)){
            	different= true;
            	for (int l=0;l<grille.getTaille();l++){
            		for (int m=0;m<grille.getTaille();m++){
            			if (!( ligneValide(grille.obtenirValeur(l,m),l,m) || colonneValide(grille.obtenirValeur(l,m),l,m))){
            				correct=false;
            			}
            		}
            	}
            }
         }
    }
	std::cout << "***************************************************** " << std::endl;
	if(correct==true){
        std::cout << "BRAVO " << nomJoueur << " c'est correct! " << std::endl;
        if(different==true){
        	std::cout << "Une autre solution est : " << std::endl;
        	solutionFinale.grille.afficher();
        }
	}
	else{
        std::cout << "Désolé " << nomJoueur << " il y a une erreur, voici la bonne solution! " << std::endl;
        solutionFinale.grille.afficher();
	}
    std::cout << "***************************************************** " << std::endl;
    std::cout << "************************ FIN ************************ " << std::endl;
    std::cout << "***************************************************** " << std::endl;
}
