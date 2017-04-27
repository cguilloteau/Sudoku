#include "Case.h"


using namespace std;

Case::Case()
{
    colonne = 0;
    ligne = 0;
    region = 0;
    valeur = 0;
    index = 0;
}

Case::~Case()
{
    //dtor
}

int Case::getColonne()const{
 return this->colonne;
}

int Case::getLigne()const{
 return this->ligne;
}

int Case::getRegion()const{
 return this->region;
}

int Case::getValeur()const{
 return this->valeur;
}

int Case::getIndex()const{
 return this->index;
}

void Case::setColonne(int col){
 this->colonne=col;
}

void Case::setLigne(int lig){
 this->ligne=lig;
}

void Case::setRegion(int lig, int col){
	int reg;
		if ((1 <= col) && (col < 4) && (1 <= lig) && (lig < 4)) {
	        reg = 1;
	    }
	    else if ((4 <= col) && (col < 7) && (1 <= lig) && (lig < 4)) {
	        reg = 2;
	    }
	    else if ((7 <= col) && (col < 10) && (1 <= lig) && (lig < 4)) {
	        reg = 3;
	    }
	    else if ((1 <= col) && (col < 4) && (4 <= lig) && (lig < 7)) {
	        reg = 4;
	    }
	    else if ((4 <= col) && (col < 7) && (4 <= lig) && (lig < 7)) {
	        reg = 5;
	    }
	    else if ((7 <= col) && (col < 10) && (4 <= lig) && (lig < 7)) {
	        reg = 6;
	    }
	    else if ((1 <= col) && (col < 4) && (7 <= lig) && (lig < 10)) {
	        reg = 7;
	    }
	    else if ((4 <= col) && (col < 7) && (7 <= lig) && (lig < 10)) {
	        reg = 8;
	    }
	    else if ((7 <= col) && (col < 10) && (7 <= lig) && (lig < 10)) {
	        reg = 9;
	    }
 this->region=reg;
}

void Case::setValeur(int val){
 this->valeur=val;
}

void Case::setIndex(int ind){
 this->index=ind;
}


/*ostream& operator<< (ostream& unFlux, const Case& unCarre)
		{
		    return unFlux << unCarre.getValeur();
		}*/
