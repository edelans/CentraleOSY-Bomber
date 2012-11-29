#ifndef PERSONNAGE
#define PERSONNAGE

#include "CImg.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <windows.h> // pas sûr que tout ça soit nécessaire ici

#include "Bombe.h"
#include "Deplacement.h"


class Personnage
{
public:
	Personnage(): // constructeur
	void modifVie(int deltaVie); // en cas de gain de points vie (bonus) ou de perte (bombe), cette fonction ajuste les points du personnage
	void powerUpSacBombe(int deltaSac);
	bool estVivant();
	int afficheLastAction();
	void updateLastAction(time_t time);
	int afficheVitesse();
	void deposeBombe(int x, int y); // x et y sont les coordoinnées du lieu de dépôt

private:
	int m_vie;
	int m_maxVie; // nombre de points de vie max du personnage
	int m_tailleSacBombe;
	int m_compteurDeBombe;  // c'est le nombre de bombes non explosées que l'utilisateur a posé. Pour vérifier que le joueur ne pose pas trop de bombes en meme temps. Cet attribut doit etre inferieur à m_tailleSacBombe
	int m_scopeDestruction[2]; // définit la zone de destruction (int, int)
	int m_typePerso; //permet de définir 1: joueur ; 2: ordi, déplacement suiveur ; 3: ordi, déplacement aléatoire
	int m_lastAction; // temps du dernier déplacement
	int Deplacement m_vitesseDeplacement; //héritage
};

#endif

