#include "Square.hpp"


using namespace std;

Square::Square()
{
    across = 0;
    down = 0;
    region = 0;
    value = 0;
    index = 0;
}

Square::~Square()
{
    //dtor
}

int Square::getAcross()const{
 return this->across;
}

int Square::getDown()const{
 return this->down;
}

int Square::getRegion()const{
 return this->region;
}

int Square::getValue()const{
 return this->value;
}

int Square::getIndex()const{
 return this->index;
}

void Square::setAcross(int ac){
 this->across=ac;
}

void Square::setDown(int dow){
 this->down=dow;
}

void Square::setRegion(int reg){
 this->region=reg;
}

void Square::setValue(int val){
 this->value=val;
}

void Square::setIndex(int ind){
 this->index=ind;
}


ostream& operator<< (ostream& unFlux, const Square& unCarre)
		{
		    return unFlux << unCarre.getValue();
		}
