#include "objet.h"


int objet::getx(){
    return this->coordonnees.first;}

int objet::gety(){
    return this->coordonnees.second;}

coord objet::getCoord(){
    return this->coordonnees;}

void objet::setCoord(int x, int y){
    coord c;
    c.first = x;
    c.second = y;
    this->coordonnees = c;
    }

bool objet::estPassable(){
    return this->passable;}

char* objet::getName(){
    return this->name;}

void objet::setName(char* s){
    this->name = s;}

