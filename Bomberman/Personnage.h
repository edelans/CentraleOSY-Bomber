#ifndef PERSONNAGE
#define PERSONNAGE

//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <iomanip>
//#include <fstream>
#include <time.h>
#include <windows.h> // pas sûr que tout ça soit nécessaire ici

#include "Bombe.h"  // nécessaire pour appeler le constructeur de Bombe
#include "Objet.h"

#define VITESSEMAX 5

class Personnage : public Objet
{
public:
	Personnage(); // constructeur par défaut
	Personnage(int typePerso);// 1 = joueur, sinon ennemi
	static void		decrementeCompteurDeBombe(Personnage* p); 
	void    modifVie(int deltaVie); // en cas de gain de points vie (bonus) ou de perte (bombe), cette fonction ajuste les points du personnage
	void    powerUpSacBombe(int deltaSac);
	void    powerUpVitessDeplacement(int deltaVit);
	bool    estVivant();
	int     afficheLastAction();
	void    updateLastAction(time_t time);
	int     afficheVitesse();
	void    deposeBombe(); // pas besoin de donner des coordonnees en argument, comme Personnage herite de Objet, m_coordonnees est un attribut de Personnage

private:
	int		m_vie;
	int		m_maxVie; // nombre de points de vie max du personnage
	int		m_tailleSacBombe;
	int		m_compteurDeBombe;  // c'est le nombre de bombes non explosées que l'utilisateur a posé. Pour vérifier que le joueur ne pose pas trop de bombes en meme temps. Cet attribut doit etre inferieur à m_tailleSacBombe
	int		m_scopeDestruction; // définit la puissance de la bombe
	int		m_typePerso; //permet de définir 1: joueur ; 2: ordi, déplacement suiveur ; 3: ordi, déplacement aléatoire
	int		m_lastAction; // temps du dernier déplacement
	int		m_vitesseDeplacement;
	int		m_idJoueur;  // nécessaire pour les bombes
};

#endif

