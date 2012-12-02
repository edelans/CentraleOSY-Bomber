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

point::point(int x,int y,char* f):
    occupe(false),
    m_image(f)
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

bool point::estPassable(){
    return (bool) (!(this->occupe))||(this->occupant->estPassable());
}

void point::setOccupant(Objet* obj){
    this->occupant = obj;
    if (obj != NULL){
        this->occupe = true;
    }else{
        this->occupe = false;
    }
}

Objet* point::getOccupant(){
    return this->occupant;}

std::string point::etat(){
    if (this->occupe){
        return "Occupé";
    }else{
        return "Vide";
    }
}

Image point::affiche()
{
    Image aff(this->m_image);
    return aff;
}
