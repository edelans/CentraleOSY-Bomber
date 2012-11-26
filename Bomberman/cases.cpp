#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "cases.h"

// Classe objet --------------


int objet::getx(){
    return this->coordonnees.first;}

int objet::gety(){
    return this->coordonnees.second;}

coord objet::getCoord(){
    return this->coordonnees;}
/*
void objet::setx(int x){
    this->coordx = x;}

void objet::sety(int y){
    this->coordy = y;}
*/
void objet::setCoord(int x, int y){
    coord c;
    c.first = x;
    c.second = y;
    this->coordonnees = c;
    }

bool objet::estPassable(){
    return this->passable;}

string objet::getName(){
    return this->name;}

void objet::setName(string s){
    this->name = s;}


// Classe typeObstacle --------------

typeObstacle::typeObstacle(bool destructible, bool passable, bool protection):
    destructible(destructible),
    passable(passable),
    protection(protection)
    {
    }

int typeObstacle::getId(){
    return this->id;}

bool typeObstacle::estDestructible(){
    return this->destructible;}

bool typeObstacle::estPassable(){
    return this->passable;}

bool typeObstacle::estProtection(){
    return this->protection;}

// Classe point -------------

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

//Classe Obstacle -----------
obstacle::obstacle(typeObstacle* t):
    type(t)
    {
    }

