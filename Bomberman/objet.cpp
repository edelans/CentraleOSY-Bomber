#include "Objet.h"



Objet::Objet() : m_coordonnees(), m_passable(false)   // Ed: je sais pas quoi mettre ici pour les coordonnees du constructeur par defaut
{
}

Objet::Objet(coord xy) : m_coordonnees(xy), m_passable(false)  // surcharge du constructeur pour qu'il accepte d'etre initialisé avec des coordonnées en argument
{
}

Objet::~Objet()
{
}


int Objet::getx(){
    return this->m_coordonnees.first;}

int Objet::gety(){
    return this->m_coordonnees.second;}

coord Objet::getCoord(){
    return this->m_coordonnees;}

void Objet::setCoord(int x, int y){
    coord c;
    c.first = x;
    c.second = y;
    this->m_coordonnees = c;
    }

bool Objet::estPassable(){
    return this->m_passable;}

