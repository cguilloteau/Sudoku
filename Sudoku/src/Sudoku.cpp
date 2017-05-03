#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "Case.h"
#include <cstdlib>
#include <ctime>
#include "Partie.h"
#include "Grille.h"
#include "List.h"
using namespace std;



/*int GetColonneFromNumber(int n){
    int k = n % 9;
    if (k == 0) {
        return 9 ;
    }
    else {
        return k;
    }
}
int GetLigneFromNumber(int n) {
    int l;
    if (GetColonneFromNumber(n)== 9) {
        l = n/9 ;
    }
    else{
        l = (n/9) + 1;
    }
    return l;
}
int GetRegionFromNumber(int n){
    int k;
    int a = GetColonneFromNumber(n);
    int d = GetLigneFromNumber(n);
    if ((1 <= a) && (a < 4) && (1 <= d) && (d < 4)) {
        k = 1;
    }
    else if ((4 <= a) && (a < 7) && (1 <= d) && (d < 4)) {
        k = 2;
    }
    else if ((7 <= a) && (a < 10) && (1 <= d) && (d < 4)) {
        k = 3;
    }
    else if ((1 <= a) && (a < 4) && (4 <= d) && (d < 7)) {
        k = 4;
    }
    else if ((4 <= a) && (a < 7) && (4 <= d) && (d < 7)) {
        k = 5;
    }
    else if ((7 <= a) && (a < 10) && (4 <= d) && (d < 7)) {
        k = 6;
    }
    else if ((1 <= a) && (a < 4) && (7 <= d) && (d < 10)) {
        k = 7;
    }
    else if ((4 <= a) && (a < 7) && (7 <= d) && (d < 10)) {
        k = 8;
    }
    else if ((7 <= a) && (a < 10) && (7 <= d) && (d < 10)) {
        k = 9;
    }
    return k;
}
bool Conflicts(Case *CurrentValeurs[81], Case test)  {
	bool retour=false;
    for(int j = 0; j<81;j++){
       if (((CurrentValeurs[j]->getColonne() != 0) && (CurrentValeurs[j]->getColonne() == test.getColonne())) || ((CurrentValeurs[j]->getLigne() != 0) && (CurrentValeurs[j]->getLigne() == test.getLigne())) ||((CurrentValeurs[j]->getRegion() != 0) && (CurrentValeurs[j]->getRegion() == test.getRegion()))){
            if (CurrentValeurs[j]->getValeur() == test.getValeur()){
            retour = true;
            }
        }
    }
    return retour;
}
Case Item(int n,int v){
    Case item;
    n+=1;
    item.setColonne(GetColonneFromNumber(n));
    item.setLigne(GetLigneFromNumber(n));
    item.setRegion(GetRegionFromNumber(n));
    item.setValeur(v);
    item.setIndex(n - 1);
    return item;
}
int main(){
srand(time(NULL));
   int c = 0;
   int i,q;
   Case *grille[81];
   for (int t=0; t<81;t++){
	   grille[t] = new Case();
   }
   vector<int> available[81];
   for (int x=0; x < 81; x++){
        for (int l=0; l < 9; l++){
            available[x].push_back(l+1);
      }
   }
   int z = 0;
   c = 0;
    do{
        if(available[c].empty() == false){
        		if(available[c].size()>1){
        			q = rand()%(available[c].size()-1);
        			z = available[c].at(q);
        		}
        		else if(available[c].size()==1){
        			q= 0;
        			z = available[c].at(0);
        		}
            if ((Conflicts(grille,Item(c,z)))==false){
                grille[c]->setColonne((Item(c,z)).getColonne());
                grille[c]->setLigne((Item(c,z)).getLigne());
                grille[c]->setRegion((Item(c,z)).getRegion());
                grille[c]->setIndex((Item(c,z)).getIndex());
                grille[c]->setValeur((Item(c,z)).getValeur());
                std::cout << "la valeur dans grille[" << c << "]  "<< grille[c]->getValeur() << ' ' << endl;
                available[c].erase(available[c].begin()+q);
                c= c+1;
            }
            else{
            	available[c].erase(available[c].begin()+q);
            }
    	}
        else{
        	for(int y=0;y<9;y++){
        			available[c].push_back(y+1) ;
        	}
            c=c-1;
        }
    }while(c<8);
   for(int p=0; p<9;p++){
       std::cout << grille[p]->getValeur() << ' ' ;
    }
   std::cout << ' ' << endl;
   for(int p=9; p<18;p++){
          std::cout << grille[p]->getValeur() << ' ';
       }
   std::cout << ' ' << endl;
   for(int p=18; p<27;p++){
          std::cout << grille[p]->getValeur() << ' ';
       }
   std::cout << ' ' << endl;
   for(int p=27; p<36;p++){
             std::cout << grille[p]->getValeur() << ' ';
          }
   std::cout << ' ' << endl;
   for(int p=36; p<45;p++){
             std::cout << grille[p]->getValeur() << ' ';
          }
   std::cout << ' ' << endl;
   for(int p=45; p<54;p++){
             std::cout << grille[p]->getValeur() << ' ';
          }rti
   std::cout << ' ' << endl;
   for(int p=54; p<63;p++){
               std::cout << grille[p]->getValeur() << ' ';
            }
   std::cout << ' ' << endl;
   for(int p=63; p<72;p++){
                 std::cout << grille[p]->getValeur() << ' ';
              }
   std::cout << ' ' << endl;
   for(int p=72; p<81;p++){
                   std::cout << grille[p]->getValeur() << ' ';
                }
    return (0);
}*/




int main(){
	srand(time(NULL));
	std::cout << "WESH WESH BIENVENUE SUR LE SUDOKU DES INTELLOS BG" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "CEST QUOI TON BLAZE FRERE?" << std::endl;
	string nomJ;
	std::cin >> nomJ ;

	int choixMenu = 0;
	int choixDifficulte = 0;
	do{
        std::cout << "" << std::endl;
		std::cout << "VASY ON FAIT QUOI FRERE?" << std::endl;
		std::cout << "1- PETITE PARTIE DES FAMILLLES OKLM" << std::endl;
		std::cout << "2- ON DISCUTE UN COUP OU KOI?" << std::endl;
		std::cout << "3- MAIS NON PARS PAS WESH ON COMMENCE A PEINE" << std::endl;
		std::cin >> choixMenu;

		switch(choixMenu){
		case 1:{
		    do{
                std::cout << "##### Niveau de difficulté #####" << std::endl;
                std::cout << "1- Facile #boloss" << std::endl;
                std::cout << "2- Moyen #boloss aussi" << std::endl;
                std::cout << "3- Difficile #boloss refoulé" << std::endl;
                std::cout << "4- Diabolique #tu vas perdre" << std::endl;
                std::cout << "5- Retour au menu #pas de couilles" << std::endl;
                std::cin >> choixDifficulte;

                switch(choixDifficulte){
                    case 1:{
                        std::cout << " " << std::endl;
                        std::cout << "VASY CA PART, BON CHANCE" << std::endl;
                        std::cout << " " << std::endl;
                        Partie partie(nomJ);
                        partie.initialiser();
                        partie.permuter();
                        partie.difficulteGrille(45);
                        partie.jouer();
                        break;
                    }
                    case 2:{
                        std::cout << " " << std::endl;
                        std::cout << "VASY CA PART, BON CHANCE" << std::endl;
                        std::cout << " " << std::endl;
                        Partie partie(nomJ);
                        partie.initialiser();
                        partie.permuter();
                        partie.difficulteGrille(50);
                        partie.jouer();
                        break;
                    }
                    case 3:{
                        std::cout << " " << std::endl;
                        std::cout << "VASY CA PART, BON CHANCE" << std::endl;
                        std::cout << " " << std::endl;
                        Partie partie(nomJ);
                        partie.initialiser();
                        partie.permuter();
                        partie.difficulteGrille(55);
                        partie.jouer();
                        break;
                    }
                    case 4:{
                        std::cout << " " << std::endl;
                        std::cout << "VASY CA PART, BON CHANCE" << std::endl;
                        std::cout << " " << std::endl;
                        Partie partie(nomJ);
                        partie.initialiser();
                        partie.permuter();
                        partie.difficulteGrille(60);
                        partie.jouer();
                        break;
                    }
                    case 5:{
                        choixMenu=0;
                        break;
                    }
                }
            }while((choixDifficulte<1)||(choixDifficulte>5));
            break;
            }
        case 2:{
			//Trouver des trucs à mettre (les règles? ou alors choix niveau difficulté?)  /!\ version assistée et accéléree? (genre une sans question ligne, colonne et valeur)
			std::cout << "BON CEST QUOI TON TERTER TOI BG?" << std::endl;
			break;
			}
		case 3:{
			std::cout << "BAH VASY SALAM" << std::endl;
			exit(1);
			break;
			}
		}
	}while((choixMenu!=3)||(choixMenu==0));


	return 0;
}
