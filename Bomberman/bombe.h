#ifndef DEF_BOMBE
#define DEF_BOMBE

#include <string>

class Bombe
{
    public:
    Bombe();
    ~Bombe();
    void decrementTimer();   // 
    void explose();    // pour détruire les blocs detruisables et appeler afficheExplosion
	void afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
	void decrementTimer(); // pour décrémenter le timer à chaque boucle de temps
	


    private:

    int m_timer;   // compte à rebours entre moment ou elle est posée et explosion
    int m_portee;  // nombre de blocs détruits dans chaque direction lors de l'explosion
};

#endif