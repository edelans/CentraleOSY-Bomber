#include <set>
#include <algorithm> // indispensable pour le for_each

#include "Bombe.h"
#include "Personnage.h"

using namespace std;



void Bombe::boucleTestTimerPourExplosion() // fonciton � rajouter dans le main.cpp � chaque fin de "boucle de temps"
{
	for_each (instances.begin(), instances.end(), testTimerPourExplosion);  // pour toutes les bombes instanci�es, on teste le timer et on agit en cons�quence.
}


void Bombe::testTimerPourExplosion(Bombe* b)
	{
		if (b->m_timer == 0)
		{
			b->enleverAffichageExplosion();
			Personnage::decrementeCompteurDeBombe(b->m_adressePersoProprio); 			// il manque ici la decrementation du compteurDeBombe du personnage !!!! /////////////\\\\\\\\\\\\\\\\\\\ !!!!!!!!!!!!
			b->~Bombe();


		}
		else if (b->m_timer > 0 && b->m_timer < 5 )  // c'est ici qu'est r�gl�e la dur�e de l'explosion !
		{
			b->afficheExplosion();
			b->m_timer -= 1 ;
		}
		else
		{
			b->m_timer -= 1 ;
		}
	}


// a voir aussi pour la gestion du timer: http://www.cppfrance.com/forum/sujet-GESTION-TIMER_1422701.aspx

Bombe::Bombe() : Objet(), m_timer(20), m_portee(2), m_adressePersoProprio(0)  // pas sur qu'on ait besoin de ce constructeur, je ne sais pas � quoi correspond un constructeur par d�faut (sans arguments) puisqu'une bombe aura forc�ment des coordonn�es.
{
	instances.insert(this);   // cr�er un pointeur vers la bombe dans le tableau qui recense les instances de bombe.
}


Bombe::Bombe(coord xy, int puissance, Personnage* proprietaire):
    Objet(xy),
    m_timer(20),
    m_portee(puissance),
    m_adressePersoProprio(proprietaire)
{
	instances.insert(this);   // cr�er un pointeur vers la bombe dans le tableau qui recense les instances de bombe.
}

Bombe::~Bombe()
{
	instances.erase(instances.find(this));  // on enleve le pointeur vers la bombe dans le tableau d'instances
}





void Bombe::explose()    // pour d�truire les blocs destructibles et appeler afficheExplosion()
{
	// est-ce la bonne classe pour cette fonction ??
}


void Bombe::afficheExplosion()  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion, dans la limite de la port�e de la bombe
{
	// est-ce la bonne classe pour cette fonction ??
}

void Bombe::enleverAffichageExplosion()
{

}

std::set<Bombe*> Bombe::instances;  // Initialisation de l'attribut statique (oui oui ca se met bien ds le cpp, cf sdz).pour etre conforme a http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class .
