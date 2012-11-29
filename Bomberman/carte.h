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

using namespace std;

typedef map<coord,point> carte;


void deplacer (carte &m, objet *obj, int x, int y);

void initialiserCarte(listeTypeObstacle types, carte &m, const char * fichier);


#endif // CARTE_H_INCLUDED
