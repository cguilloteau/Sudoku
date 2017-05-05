#include <iostream>
#include<string>

#ifndef CASE_H
#define CASE_H

using namespace std;

class Case
{
    public:
        Case();
        virtual ~Case();
        void setColonne(const int ac);
        void setLigne(const int dow);
        void setRegion(int lig, int col, int tailleGrille);
        void setValeur(const int val);
        void setIndex(const int ind);
        int getColonne()const;
        int getLigne()const;
        int getRegion()const;
        int getValeur()const;

    protected:
    private:
        int colonne;
        int ligne;
        int region;
        int valeur;
};

#endif // Case_H
