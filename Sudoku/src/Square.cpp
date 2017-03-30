#include "Square.hpp"

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

int Square::getAcross(){
 return this->across;
}

int Square::getDown(){
 return this->down;
}

int Square::getRegion(){
 return this->region;
}

int Square::getValue(){
 return this->value;
}

int Square::getIndex(){
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
