#include "point.h"


point::point():
    occupe(false)
    {
    }

point::point(int x,int y):
    occupe(false)
    {
        coord c;
        c.first = x;
        c.second = y;
        this->coordonnees = c;
    }

coord point::getCoord(){
    return this->coordonnees;}

int point::getx(){
    return this->coordonnees.first;}

int point::gety(){
    return this->coordonnees.second;}

bool point::estOccupe(){
    return this->occupe;}

void point::setOccupant(objet* obj){
    this->occupant = obj;
    if (obj != NULL){
        this->occupe = true;
    }else{
        this->occupe = false;
    }
}

objet* point::getOccupant(){
    return this->occupant;}

string point::etat(){
    if (this->occupe){
        return "Occupé";
    }else{
        return "Vide";
    }
}
