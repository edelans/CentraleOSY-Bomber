#include "Bombe.h"
#include <set>
using namespace std;



void Bombe::boucleTestTimerPourExplosion() // fonciton à rajouter dans le main.cpp à chaque fin de "boucle de temps"
{
	for_each (instances.begin(), instances.end(), testTimerPourExplosion);  // pour toutes les bombes sur la carte: trouver un moyen de pouvoir les parcourir: probablement avec un tableau dynamique statique dont les cases enregistrent un pointeur vers chaque instance. Creuser aussi http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class
} 


void Bombe::testTimerPourExplosion(Bombe* b)
	{
		if (b->m_timer == 0)
		{
			b->explose();  
			b->~Bombe();  
		}
		else 
		{
			b->m_timer -= 1   
		}
	}




Bombe::Bombe()   
{
	instances.insert(this);   // créer un pointeur vers la bombe dans le tableau qui recense les instances de bombe.
}

Bombe::~Bombe() 
{
	// afficher l'image de l'explosion ? -> non, affiché par explose()

	instances.erase(instances.find(this));  // on enleve le pointeur vers la bombe dans le tableau d'instances
	
}


void Bombe::decrementTimer()
{
	m_timer -= 1;  // nb: qd le timer est à 0, un if ds la boucle de temps le detecte et fait exploser la bombe
}





void Bombe::explose()    // pour détruire les blocs detruisables et appeler afficheExplosion
{

}


void Bombe::afficheExplosion()  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
{

}
