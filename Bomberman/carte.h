#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <string>
#include "cases.h"

using namespace std;

typedef map<coord,point> carte;


void deplacer (carte &m, objet *obj, int x, int y);

void initialiserTypeObstacle(listeTypeObstacle &types, const char * fichier);
void initialiserCarte(listeTypeObstacle types, carte &m, const char * fichier);


#endif // CARTE_H_INCLUDED
