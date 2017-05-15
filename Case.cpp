#include "Case.h"


using namespace std;

Case::Case()
{
    colonne = 0;
    ligne = 0;
    region = 0;
    valeur = 0;
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

void Case::setColonne(int col){
 this->colonne=col;
}

void Case::setLigne(int lig){
 this->ligne=lig;
}

void Case::setRegion(int lig, int col, int tailleGrille){
	int reg;
	if (tailleGrille==9){
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
	}
	else{
		if ((1 <= col) && (col < 5) && (1 <= lig) && (lig < 5)) {
	        reg = 1;
		}
		else if ((5 <= col) && (col < 9) && (1 <= lig) && (lig < 5)) {
			reg = 2;
		}
	    else if ((9 <= col) && (col < 13) && (1 <= lig) && (lig < 5)) {
	    	reg = 3;
	    }
	    else if ((13 <= col) && (col < 17) && (1 <= lig) && (lig < 5)) {
	    	reg = 4;
	    }
	    else if ((1 <= col) && (col < 5) && (5 <= lig) && (lig < 9)) {
			reg = 5;
		}
		else if ((5 <= col) && (col < 9) && (5 <= lig) && (lig < 9)) {
			reg = 6;
		}
		else if ((9 <= col) && (col < 13) && (5 <= lig) && (lig < 9)) {
			reg = 7;
		}
		else if ((13 <= col) && (col < 17) && (5 <= lig) && (lig < 9)) {
			reg = 8;
		}
		else if ((1 <= col) && (col < 5) && (9 <= lig) && (lig < 13)) {
			reg = 9;
		}
		else if ((5 <= col) && (col < 9) && (9 <= lig) && (lig < 13)) {
			reg = 10;
		}
		else if ((9 <= col) && (col < 13) && (9 <= lig) && (lig < 13)) {
			reg =11;
		}
		else if ((13 <= col) && (col < 17) && (9 <= lig) && (lig < 13)) {
			reg = 12;
		}
		else if ((1 <= col) && (col < 5) && (13 <= lig) && (lig < 17)) {
			reg = 13;
		}
		else if ((5 <= col) && (col < 9) && (13 <= lig) && (lig < 17)) {
			reg = 14;
		}
		else if ((9 <= col) && (col < 13) && (13 <= lig) && (lig < 17)) {
			reg =15;
		}
		else if ((13 <= col) && (col < 17) && (13 <= lig) && (lig < 17)) {
			reg = 16;
		}
	}
 this->region=reg;
}

void Case::setValeur(int val){
 this->valeur=val;
}
