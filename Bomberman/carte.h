#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <string>

#include "objet.h"
#include "typeObstacle.h"
#include "point.h"

class Personnage;

typedef std::map<coord,point> carte;

int     largeur(carte m);
int     hauteur(carte m);
int     surface(carte m);

void    placer(carte &m, Objet *obj, int x, int y);
int     deplacer (carte &m, Objet *obj, int x, int y);


void    initialiserCarte(listeTypeObstacle types, carte &m, const char * fichier);


#endif // CARTE_H_INCLUDED
