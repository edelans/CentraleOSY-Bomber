#ifndef DEF_BOMBE
#define DEF_BOMBE

#include <string>
#include <set>
#include "Objet.h"
#include "Personnage.h"
#include "carte.h"

class Personnage;

class Bombe : public Objet //Bombe herite de objet pour avoir des coordonnees !
{
public:
	static			std::set<Bombe*> instances;  // on cr�e un set nomm� "instances", pour l'instant vide, et qui contiendra des pointeurs vers les bombes, et qui va r�f�rencer les instances de Bombe, ce qui permettra de compter les bombes sur la carte et de les atteindre.  http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class
	static void		boucleTestTimerPourExplosion();  // fonciton � rajouter dans le main.cpp � chaque fin de "boucle de temps". Elle applique la fonction testTimerPourExplosion() � toutes les instances de bombes
	static void		testTimerPourExplosion(Bombe* b);        //
    Bombe();
	Bombe(coord xy, int puissance, Personnage* proprietaire);  // ca serait pas plutot Personnage &proprietaire ???
    ~Bombe();
	void	explose();    // pour d�truire les blocs destructibles, tuer les personnages  //
	void	afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
	void	enleverAffichageExplosion(); // pour nettoyer la map des images d'explosion



private:
	int				m_timer;   // compte � rebours entre moment ou elle est pos�e et explosion
	int				m_portee;  // nombre de blocs d�truits dans chaque direction lors de l'explosion
	Personnage*		m_adressePersoProprio;  // pour savoir qui a pos� la bombe: necessaire pour savoir quel compteurDeBombe incr�menter losque la bombe explose

// a voir si on a besoin des attributs suivants
//	bool	m_isExploding;  // correspond � l'etat ou les images de l'explosion sont affich�es
//	bool	m_isExploded;   // correspond a l'etat ou on a arrete d'afficher les images d'explosion
};


#endif
