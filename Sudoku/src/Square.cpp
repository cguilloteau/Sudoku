#include "Square.hpp"


using namespace std;

Square::Square()
{
    across = 3;
    down = 3;
    region = 3;
    value = 3;
    index = 3;
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
