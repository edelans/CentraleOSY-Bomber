#ifndef DEF_BOMBE
#define DEF_BOMBE

#include <string>
#include <set>
#include "Objet.h"
#include "Personnage.h"


class Bombe : public Objet //Bombe herite de objet pour avoir des coordonnees !
{
public: 
	static			std::set<Bombe const *> instances;  // on crée un set nommé "instances", pour l'instant vide, et qui contiendra des pointeurs vers les bombes, et qui va référencer les instances de Bombe, ce qui permettra de compter les bombes sur la carte et de les atteindre.  http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class
	static void		boucleTestTimerPourExplosion();  // fonciton à rajouter dans le main.cpp à chaque fin de "boucle de temps". Elle applique la fonction testTimerPourExplosion() à toutes les instances de bombes
	static void		testTimerPourExplosion(Bombe* b);        // 
    Bombe();
	Bombe(coord xy, int puissance, Personnage* proprietaire);
    ~Bombe();
	void	explose();    // pour détruire les blocs destructibles, tuer les personnages  //
	void	afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
	void	enleverAffichageExplosion(); // pour nettoyer la map des images d'explosion
	


private:
	int				m_timer;   // compte à rebours entre moment ou elle est posée et explosion
	int				m_portee;  // nombre de blocs détruits dans chaque direction lors de l'explosion
	Personnage*		m_adressePersoProprio;  // pour savoir qui a posé la bombe: necessaire pour savoir quelle compteurDeBombe incrémenter losque la bombe explose

// a voir si on a besoin des attributs suivants
//	bool	m_isExploding;  // correspond à l'etat ou les images de l'explosion sont affichées
//	bool	m_isExploded;   // correspond a l'etat ou on a arrete d'afficher les images d'explosion
};


#endif