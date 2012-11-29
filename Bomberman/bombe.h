#ifndef DEF_BOMBE
#define DEF_BOMBE

#include <string>
#include <set>



class Bombe
{
	static std::set<Bombe const *> instances;  // on crée un set nommé "instances", pour l'instant vide, et qui contiendra des pointeurs vers les bombes, et qui va référencer les instances de Bombe, ce qui permettra de compter les bombes sur la carte et de les atteindre.
                                               // 
											   // http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class

	static void boucleTestTimerPourExplosion();  // fonciton à rajouter dans le main.cpp à chaque fin de "boucle de temps". Elle applique la fonction testTimerPourExplosion() à toutes les instances de bombes
	static void testTimerPourExplosion(Bombe* b);        // 

public: 
    Bombe();
    ~Bombe();
    void decrementTimer();   // 
    void explose();    // pour détruire les blocs detruisables et appeler afficheExplosion
	void afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
	


private:
    int m_timer;   // compte à rebours entre moment ou elle est posée et explosion
    int m_portee;  // nombre de blocs détruits dans chaque direction lors de l'explosion
	bool m_isExploding;  // correspond à l'etat ou les images de l'explosion sont affichées
	bool m_isExploded;   // correspond a l'etat ou on a arrete d'afficher les images d'explosion
};

std::set<Bombe> Bombe::instances;  // pour etre conforme a http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class . j'imagine que c'est une sorte d'initialisation.

#endif