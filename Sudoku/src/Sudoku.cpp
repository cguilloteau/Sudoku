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
}*/


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

*/


/*int main(){
   int c = 0;
   int i;
   Square *squares[3];
   for(int i=0; i<3;i++){
           squares[i]=(new Square());

       }
   Square carre;
   carre.setValue(5);
   Square autreCarre;
   autreCarre.setValue(7);
   Square carreInit;
   squares[0]= &carre;
   squares[1]= &autreCarre;
   squares[2]= &carreInit;
   int available[80][9];
   for (int x=0; x < 80; x++){
           for (int l=0; l < 9; l++){
               available[x][l] = l+1;
              // std::cout << available[x][l] << ' ';
           }
   }
   int z = 0;
   while(z==0){
                   srand(time(NULL));
                   i = rand()%8;
                   z = available[c][i];
                   std::cout << "nombre tiré au sort  " << i << " donc " << z << ' ' << endl;
           }



    /*for(int i=0; i<3;i++){
        std::cout << squares[i]->getValue() << ' ' << endl ;

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
    int l;
    if (GetAcrossFromNumber(n)== 3) {
        l = n/3 ;
    }
    else{
        l = (n/3) + 1;
    }
    return l;
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


bool Conflicts(Square *CurrentValues[9], Square test)  {
	bool retour=false;
    for(int j = 0; j<9;j++){
       if (((CurrentValues[j]->getAcross() != 0) && (CurrentValues[j]->getAcross() == test.getAcross())) || ((CurrentValues[j]->getDown() != 0) && (CurrentValues[j]->getDown() == test.getDown())) ||((CurrentValues[j]->getRegion() != 0) && (CurrentValues[j]->getRegion() == test.getRegion()))){
            if (CurrentValues[j]->getValue() == test.getValue()){

            retour = true;
            }
        }

    }
    return retour;
}

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
   //Square Sudoku[9];
   //Square squares[9];
   Square *squares[9];
   //vector<Square>* squares;
   Square carre;
   Square carree;
   Square carreee;
   Square carreeee;
   Square carreeeee;
   Square carreeeeee;
   Square carreeeeeee;
   Square carreeeeeeee;
   Square carreeeeeeeee;

   squares[0] = &carre;
   squares[1] = &carree;
   squares[2] = &carreee;
   squares[3] = &carreeee;
   squares[4] = &carreeeee;
   squares[5] = &carreeeeee;
   squares[6] = &carreeeeeee;
   squares[7] = &carreeeeeeee;
   squares[8] = &carreeeeeeeee;

   //for (int t=0; t<9;t++){
	   //squares[t] = Square();
	   /*squares[t]->setAcross(0);
	   squares[t]->setDown(0);
	   squares[t]->setRegion(0);
	   squares[t]->setIndex(0);
	   squares[t]->setValue(0);*/
	   //Square carreInit;
	   //squares->push_back(carreInit);
   //}
   for(int p=0; p<9;p++){
          std::cout << squares[p]->getValue() << ' ' << endl;
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
                //std::cout << "nombre tiré au sort  " << i << " donc " << z << ' ' << endl;
            }
            if ((Conflicts(squares,Item(c,z)))==false){
                //squares->push_back(Item(c,z));
                squares[c]->setAcross((Item(c,z)).getAcross());
                squares[c]->setDown((Item(c,z)).getDown());
                squares[c]->setRegion((Item(c,z)).getRegion());
                squares[c]->setIndex((Item(c,z)).getIndex());
                squares[c]->setValue((Item(c,z)).getValue());
                std::cout << "la valeur dans squares " << squares[c]->getValue() << ' ' << endl;
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

   for(int p=0; p<3;p++){
       std::cout << squares[p]->getValue() << ' ' ;
    }
   std::cout << ' ' << endl;
   for(int p=3; p<6;p++){
          std::cout << squares[p]->getValue() << ' ';
       }
   std::cout << ' ' << endl;
   for(int p=6; p<9;p++){
          std::cout << squares[p]->getValue() << ' ';
       }

    //for(vector<Square>::iterator s = Sudoku.begin(); s != Sudoku.end();s++){
     //   std::cout << s->value << ' ';

    return (0);
}
