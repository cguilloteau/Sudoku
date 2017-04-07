#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Square.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;


/*int GetAcrossFromNumber(int n){
    int k = n % 9;
    if (k == 0) {
        return 9 ;
    }
    else {
        return k;
    }
}

int GetDownFromNumber(int n) {
    int k;
    if (GetAcrossFromNumber(n)== 9) {
        k = n/9 ;
    }
    else{
        k = (n/9) + 1;
    }
    return k;
}

int GetRegionFromNumber(int n){
    int k;
    int a = GetAcrossFromNumber(n);
    int d = GetDownFromNumber(n);

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

*/
bool Conflicts(vector<Square>* CurrentValues, Square test)  {
	bool retour = false;
    for(vector<Square>::iterator s = CurrentValues->begin(); s != CurrentValues->end();s++){
       if (((s->getAcross() != 0) && (s->getAcross() == test.getAcross())) || ((s->getDown() != 0) && (s->getDown() == test.getDown())) ||((s->getRegion() != 0) && (s->getRegion() == test.getRegion()))){
            if (s->getValue() == test.getValue()){
                retour= true;
            }
        }
    }
    return retour;
}


/*
Square Item(int n,int v){
    Square item;
    n+=1;
    item.setAcross(GetAcrossFromNumber(n));
    item.setDown(GetDownFromNumber(n));
    item.setRegion(GetRegionFromNumber(n));
    item.setValue(v);
    item.setIndex(n - 1);
    return item;
}*/



/*int main(){
   int c = 0;
   int i,z;
   Square carreInit;
  // vector<Square> Sudoku;
   std::vector<Square>* squares ;
   //vector<Square> squares;

   squares =new std::vector<Square>(carreInit);
   //squares.push_back(carreInit);

   int available[80][9];
   for (int x=0; x < 80; x++){
        for (int l=0; l < 9; l++){
            available[x][l] = l+1;
      }
   }

    do {
        int leszeros=0;
        for(int j=0;j<9;j++){
            if (available[c][j] == 0){
                leszeros=leszeros+1;
            }
        }
        if (leszeros<9){
            do{
                srand(time(NULL));
                i = rand()%8;
                z = available[c][i];
            }while(z!=0);
            if ((Conflicts(squares,Item(c,z)))==false){
                squares.push_back(Item(c,z));
                available[c][i]=0;
                c+=1;
            }
            else{
                available[c][i]=0;
            }
        }
        else{
            for(int y=0;y<9;y++){
                available[c][y]=y+1 ;
            }
            c=c-1;
        }
    }while( c<2 );
    for(vector<Square>::iterator s = squares.begin(); s != squares.end();s++){
        /*Sudoku.push_back(*s);
        std::cout << ((s)->getValue()) << ' ';
    }

    /*for(vector<Square>::iterator s = Sudoku.begin(); s != Sudoku.end();s++){
        std::cout << s->value << ' ';




int main(){
   int c = 0;
   int i;
   int z;
   vector<Square> Sudoku;
   vector<Square> squares;
   Square carre;
   carre.setValue(5);
   Square autreCarre;
   autreCarre.setValue(7);
   Square carreInit;
   squares.push_back(carre);
   squares.push_back(autreCarre);
   squares.push_back(carreInit);
   int available[80][9];
  /* std::vector<Square>::iterator it;
   it = squares.begin();
   int val = it->getValue();
   for (int x=0; x < 80; x++){
        for (int l=0; l < 9; l++){
            available[x][l] = l+1;
            std::cout << available[x][l] << ' ';
        }
   }*
    std::cout << "val fixe" << carre.getValue() << ' ';
    std::cout << "val test" << val << ' ';
    for(vector<Square>::iterator s = squares.begin(); s != squares.end();s++){
        std::cout << ((s)->getValue()) << ' ';

}
}*/






//TEST SUR UN MINI CARRE



int GetAcrossFromNumber(int n){
    int k = n % 3;
    if (k == 0) {
        return 3 ;
    }
    else {
        return k;
    }
}

int GetDownFromNumber(int n) {
    int k;
    if (GetAcrossFromNumber(n)== 3) {
        k = n/3 ;
    }
    else{
        k = (n/3) + 1;
    }
    return k;
}

int GetRegionFromNumber(int n){
    int k;
    int a = GetAcrossFromNumber(n);
    int d = GetDownFromNumber(n);

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


/*bool Conflicts(Square CurrentValues[9], Square test)  {
	bool retour=false;
    for(int j = 0; j<9;j++){
       if (((CurrentValues[j].getAcross() != 0) && (CurrentValues[j].getAcross() == test.getAcross())) || ((CurrentValues[j].getDown() != 0) && (CurrentValues[j].getDown() == test.getDown())) ||((CurrentValues[j].getRegion() != 0) && (CurrentValues[j].getRegion() == test.getRegion()))){
            if (CurrentValues[j].getValue() == test.getValue()){

            retour = true;
            }
        }

    }
    return retour;
}*/

Square Item(int n,int v){
    Square item;
    n+=1;
    item.setAcross(GetAcrossFromNumber(n));
    item.setDown(GetDownFromNumber(n));
    item.setRegion(GetRegionFromNumber(n));
    item.setValue(v);
    item.setIndex(n - 1);
    return item;
}



int main(){
   int c = 0;
   int i;
   Square carreInit;
   //Square Sudoku[9];
   //Square squares[9];
   vector<Square>* squares;
   for (int t=0; t<9;t++){
	   Square carreInit;
	   squares->push_back(carreInit);
   }

   for(int p=0; p<9;p++){
          std::cout << squares->at(p) << ' ' << endl;
       }

   int available[9][9];
   for (int x=0; x < 9; x++){
        for (int l=0; l < 9; l++){
            available[x][l] = l+1;
      }
   }
   int leszeros=0;
   int z = 0;
    do{
        leszeros = 0;
        for(int j=0;j<9;j++){
            if (available[c][j] == 0){
                leszeros=leszeros+1;
            }
        }
        std::cout << "nb de zeros " << leszeros << ' ' << endl;

        if (leszeros<9){
        	z = 0;
            while(z==0){
                srand(time(NULL));
                i = rand()%8;
                z = available[c][i];
                std::cout << "nombre tir� au sort  " << i << z << ' ' << endl;
            }
            if ((Conflicts(squares,Item(c,z)))==false){
                squares->push_back(Item(c,z));
                /*squares[c].setAcross((Item(c,z)).getAcross());
                squares[c].setDown((Item(c,z)).getDown());
                squares[c].setRegion((Item(c,z)).getRegion());
                squares[c].setIndex((Item(c,z)).getIndex());*/
                //std::cout << "la valeur dans squares " << squares[c] << ' ' << endl;
                available[c][i]=0;
                c+=1;
            }
            else{
                available[c][i]=0;
            }
        }
        else{
            for(int y=0;y<9;y++){
                available[c][y]=y+1 ;
            }
            c=c-1;
        }
    }while( c<9 );
   for(int p=0; p<9;p++){
       // std::cout << squares[p] << ' ' << endl;
    }

    /*for(vector<Square>::iterator s = Sudoku.begin(); s != Sudoku.end();s++){
        std::cout << s->value << ' ';*/

    return (0);
}
