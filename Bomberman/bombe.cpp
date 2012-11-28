#include "Bombe.h"

using namespace std;



Bombe::Bombe()   
{
	// créer un pointeur vers la bombe dans le tableau qui recense les instances de bombe.

}

Bombe::~Bombe() 
{
	// afficher l'image de l'explosion ? -> non, affiché par explose()

}


void Bombe::decrementTimer()
{
	m_timer -= 1;  // nb: qd le timer est à 0, un if ds la boucle de temps le detecte et fait exploser la bombe
}


/* // code à rajouter dans le main.cpp à chaque fin de "boucle de temps"
for () // pour toutes les bombes sur la carte: trouver un moyen de pouvoir les parcourir: probablement avec un tableau dynamique statique dont les cases enregistrent un pointeur vers chaque instance. Creuser aussi http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class
{
	if (m_timer == 0)
	{
		explose();   //// ATTENTION: rajouter l'objet avant la méthode...dépend de la déclaration de la boucle for (parcours des bombes posées sur la carte)
		~Bombe();   // pour détruire l'instance de la bombe
	}
}

*/


void Bombe::explose();    // pour détruire les blocs detruisables et appeler afficheExplosion
{

}


void Bombe::afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
{

}
