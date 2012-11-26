#include "Personnage.h"

using namespace std;

CImg<unsigned char> pictoJoueur(Joueur.png);
CImg<unsigned char> pictoEnnemi(Ennemi.png);


Personnage::Personnage(int typePerso) // constructeur du personnage
{
	if typePerso = 1
	{
		m_picto(pictoJoueur); // personnage du joueur
	}
	else
	{
		m_picto(pictoEnnemi);
	}
	m_vie(m_maxVie);
	m_maxVie(100);
	//m_vitesse (??) => On met des niveau de vitesse genre 1,2,3 pour chaque personnage ?
	m_tailleSacBombe(100); //valeur à discuter
	m_typePerso(typePerso);
	m_scopeDestruction[0] = 1; // zone de destruction latérale horizontale des bombes poseés par le personnage (ici : 1 case de chaque côté de la bombe)
	m_scopeDestruction[1] = 1; // zone de destruction latérale verticale des bombes poseés par le personnage

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
	if m_vie > 0
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
	//à voir avec la classe Bombe...
}

