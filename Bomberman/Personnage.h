#ifndef PERSONNAGE
#define PERSONNAGE

//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <iomanip>
//#include <fstream>

#include "Bombe.h"  // n�cessaire pour appeler le constructeur de Bombe
#include "Objet.h"
#include "carte.h"

class Personnage : public Objet
{
public:
	Personnage(); // constructeur par d�faut
	Personnage(int typePerso);// 1 = joueur, sinon ennemi
	static void		decrementeCompteurDeBombe(Personnage* p);

	void	modifVie(int deltaVie); // en cas de gain de points vie (bonus) ou de perte (bombe), cette fonction ajuste les points du personnage
	void	powerUpSacBombe(int deltaSac);
	bool	estVivant();
	int		afficheLastAction();
	int		getVitesse();
	void	modifVitesse(int deltaVitesse);
	void	updateLastAction(time_t time);
	void	deposeBombe(carte &m); // pas besoin de donner des coordonnees en argument, comme Personnage herite de Objet, m_coordonnees est un attribut de Personnage
                                    // El : par contre, besoin de pr�ciser la carte, pour que la bombe apparaisse vraiment dans le niveau (la fonction deposeBombe doit �tre � effet de bord)
	void	deplacerhaut(carte &m); //El : idem
	void	deplacerbas(carte &m);
	void	deplacergauche(carte &m);
	void	deplacerdroite(carte &m);

private:
	int		m_vie;
	int		m_maxVie; // nombre de points de vie max du personnage
	int		m_tailleSacBombe;
	int		m_compteurDeBombe;  // c'est le nombre de bombes non explos�es que l'utilisateur a pos�. Pour v�rifier que le joueur ne pose pas trop de bombes en meme temps. Cet attribut doit etre inferieur � m_tailleSacBombe
	int		m_scopeDestruction; // d�finit la puissance de la bombe
	int		m_typePerso; //permet de d�finir 1: joueur ; 2: ordi, d�placement suiveur ; 3: ordi, d�placement al�atoire
	int		m_lastAction; // temps du dernier d�placement
	int		m_idJoueur;  // n�cessaire pour les bombes
	int     m_vitesse;
};

void    deplacerPerso(carte &m, Personnage* perso, int direction);

#endif

