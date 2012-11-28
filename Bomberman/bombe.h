#ifndef DEF_BOMBE
#define DEF_BOMBE

#include <string>

class Bombe
{
	static std::set<Bombe const *> instances;  // http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class

public: 
    Bombe() : { instances.insert(this); };
    ~Bombe(){ instances.delete(this); };
    void decrementTimer();   // 
    void explose();    // pour détruire les blocs detruisables et appeler afficheExplosion
	void afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
	void decrementTimer(); // pour décrémenter le timer à chaque boucle de temps
	


private:
    int m_timer;   // compte à rebours entre moment ou elle est posée et explosion
    int m_portee;  // nombre de blocs détruits dans chaque direction lors de l'explosion
	bool m_isExploding;  // correspond à l'etat ou les images de l'explosion sont affichées
	bool m_isExploded;   // correspond a l'etat ou on a arrete d'afficher les images d'explosion
};

#endif