#include "Personnage.h"
#include "carte.h"

#define TAILLE_CASE				32
#define TAILLE_PERSONNAGE		TAILLE_CASE-10 // la différence de taille doit être paire
#define VITESSE_DEPLACEMENT		TAILLE_CASE/4

using namespace std;

CImg<unsigned char> pictoJoueur(Joueur.png);
CImg<unsigned char> pictoEnnemi(Ennemi.png);



void Personnage::decrementeCompteurDeBombe(Personnage* p)
{
	p->m_compteurDeBombe-=1;
}


Personnage::Personnage(int typePerso) : Objet() // constructeur du personnage
{
	if (m_typePerso = 1)
	{
		m_picto(pictoJoueur); // personnage du joueur
	}
	else
	{
		m_picto(pictoEnnemi);
	}
	m_vie(m_maxVie);
	m_maxVie(3);
	m_tailleSacBombe(2); 
	m_typePerso(typePerso);
	m_scopeDestruction = 3; // zone de destruction des bombes poseés par le personnage
}


void Personnage::modifVie(signed int deltaVie) // prévoit les bonus de type potions ou autre
{
	if (m_vie + deltaVie <= 0)
	{
		m_vie = 0;
		m_estVivant = false;
	}
	else if (m_vie + deltaVie >= m_maxVie)
	{
		m_vie = m_maxVie;
	}
	else
	{
		m_vie += deltaVie;
	}
}

void Personnage::powerUpSacBombe(int deltaSac)
{
	m_tailleSacBombe += deltaSac;
}

bool Personnage::estVivant()
{
	if (m_vie > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Personnage::afficheLastAction()
{
	return m_lastAction;
}

void Personnage::updateLastAction(time_t time)
{
	m_lastAction = time;
}


void Personnage::deposeBombe()
{
	if (m_compteurDeBombe<m_tailleSacBombe)
	{
		Bombe(m_coordonnees, m_scopeDestruction, this);   //on appelle le constructeur de la classe Bombe avec les coordonnées du personnage.
		m_compteurDeBombe +=1;
	}
}

void Personnage::deplacerhaut()
{
	int x = Personnage.getx();
	int y = Personnage.gety();
	int decalage_x_gauche = x-x/TAILLE_CASE*TAILLE_CASE; // nombre positif, calcule de combien de pixels le personnage est décalé du bord de sa case actuelle

	if (decalage_x_gauche < TAILLE_PERSONNAGE/2) // empiète sur la case de gauche
	{
		if (y/TAILLE_CASE > 0 && carte[coord(x/TAILLE_CASE, y/TAILLE_CASE)].estPassable && carte[coord(x/TAILLE_CASE+1, y/TAILLE_CASE)].estPassable) // les 2 cases gauche haut et haut doivent être passables
		{
			m_coordonnees.second -= VITESSE_DEPLACEMENT;
		}

	}
	else if (decalage_x_gauche > TAILLE_CASE-TAILLE_PERSONNAGE) // empiète sur la case de droite
	{
		if (y/TAILLE_CASE > 0 && carte[coord(x/TAILLE_CASE+1, y/TAILLE_CASE)].estPassable && carte[coord(x/TAILLE_CASE+2, y/TAILLE_CASE)].estPassable) // les 2 cases droite haut et haut doivent être passables
		{
			m_coordonnees.second -= VITESSE_DEPLACEMENT;
		}
	}
	else
	{
		if (y/TAILLE_CASE > 0 && carte[coord(x/TAILLE_CASE+1, y/TAILLE_CASE)].estPassable) // la case du dessus doit etre passable
		{
			m_coordonnees.second -= VITESSE_DEPLACEMENT;
		}
	}
}

