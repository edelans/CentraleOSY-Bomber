#ifndef DRAWING
#define DRAWING

#include "assets/CImg.h"
#include <iostream>
#include <stdio.h>
//#include <string>
#include <iomanip>
#include <fstream>

#include "carte.h"

#define LONGUEUR_MAX		24
#define LARGEUR_MAX			12
#define TAILLE_CASE			32

class drawing
{
public:
	void initialize(const char* file) const;
	//void afficher(carte m,cimg_library::CImg<unsigned char> jeu); //initialiser l'affichage une fois le jeu chargé à partir des fichiers de config
};

void afficher(carte m,cimg_library::CImg<unsigned char> jeu); //initialiser l'affichage une fois le jeu chargé à partir des fichiers de config

#endif
