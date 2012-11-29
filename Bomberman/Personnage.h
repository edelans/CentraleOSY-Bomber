#ifndef PERSONNAGE
#define PERSONNAGE

#include "assets/CImg.h"
//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <iomanip>
//#include <fstream>
#include <time.h>
#include <windows.h> // pas s�r que tout �a soit n�cessaire ici

#include "Bombe.h"
#include "Deplacement.h"
#include "objet.h"


class Personnage : public objet
{
public:
	Personnage(); // constructeur par d�faut
	Personnage(int typePerso);// 1 = joueur, sinon ennemi
	void    modifVie(int deltaVie); // en cas de gain de points vie (bonus) ou de perte (bombe), cette fonction ajuste les points du personnage
	void    powerUpSacBombe(int deltaSac);
	bool    estVivant();
	int     afficheLastAction();
	void    updateLastAction(time_t time);
	int     afficheVitesse();
	void    deposeBombe(int x, int y); // x et y sont les coordoinn�es du lieu de d�p�t

private:
	int     m_vie;
	int     m_maxVie; // nombre de points de vie max du personnage
	int     m_tailleSacBombe;
	int     m_scopeDestruction[2]; // d�finit la zone de destruction (int, int)
	int     m_typePerso; //permet de d�finir 1: joueur ; 2: ordi, d�placement suiveur ; 3: ordi, d�placement al�atoire
	int     m_lastAction; // temps du dernier d�placement
	int Deplacement m_vitesseDeplacement; //h�ritage
};

#endif

