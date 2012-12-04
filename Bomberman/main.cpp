#include "CImg.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>

//nos en-t�tes .h en lien direct avec le main (� compl�ter) :
#include "drawing.h"
#include "Objet.h"
#include "Personnage.h" // indisp pour une usage en direct ou h�rit� par Objet.h ?
#include "drawing.h"
#include "cases.h"
#include "carte.h"

#define TEMPS_BOUCLE		200

using namespace cimg_library;
using namespace std;

int main()
{
	carte m;
    listeTypeObstacle types;

    initialiserTypeObstacle(types, "obstacles.config");
    initialiserCarte(types,m,"level.config");

    objet obj;

    objet* obj2 = m[coord (2,2)].getOccupant();
    //string s = (*obj2).getName(); //�a plante ici
    //typeObstacle *t = obs->getType();


    //cout << s << endl;
    cout << obj.getx() << "," << obj.gety() << endl;

    cout << "Point (1,1) : " << m[coord (1,1)].etat() << endl;
    cout << "Point (2,2) : " << m[coord (2,2)].etat() << endl;

    deplacer(m, &obj, 2, 2);

    cout << obj.getx() << "," << obj.gety() << endl;

    cout << "Point (1,1) : " << m[coord (1,1)].etat() << endl;
    cout << "Point (2,2) : " << m[coord (2,2)].etat() << endl;

    // << " " << m[coord (1,2)] << " " << m[coord (1,3)] << endl
    //     << m[coord (2,1)] << " " << m[coord (2,2)] << " " << m[coord (2,3)] << endl
    //     << m[coord (3,1)] << " " << m[coord (3,2)] << " " << m[coord (3,3)];
	//Conctruction des personnages :
	Personnage Joueur (1);
	Personnage Ennemi1 (2);
	Personnage Ennemi2 (2);
	// o� g�rer la position initiale ? dans drawing ?

	game.fill(0);
	drawing d;
	d.initialize("niveau1.lvl");
	CImgDisplay disp(game, "bomberman");

	time_t start,end;
	time(&start);

	// Commandes personnage joueur :
		int derniereAction(Joueur.afficheLastAction());
		time_t tempsActuel;
		if (difftime(derniereAction, tempsActuel) >= TEMPS_BOUCLE) //perd la notion de vitesse, il faudrait Joueur.afficheVitesse()
		{
			switch (disp.released_key(0)) // retourne la derni�re touche press�e
			{
				case 31U: // correspond � la touche Z
					deplacerHaut(x,y);
					//disp.display(personnage); // permet de rafraichir une image en particulier !=> plut�t dans le code d�placement
				case 44U:
					deplacerGauche(x,y);
				case 45U:
					deplacerBas(x,y);
				case 46U:
					deplacerDroite(x,y);
				case 53U:
					poserbombe(x,y);
			}//=> position du break ?
			//mettre � jour le temps Joueur.updateLastAction(time) et la position avec une fonction de la classe objet...
		}
		// on r�p�te pour Ennemi1 avec rand � la place de disp.released_key(0) => d�placement al�atoire
		// on r�p�te pour Ennemi2 avec

	// Savoir qui gagne :
	if (Joueur.estVivant())
	{
		//affichage message ou image "vous avez gagn�"
		// passage � un niveau sup ?
	}
	else
	{
		//affichage message ou image "Vous avez perdu"
	}

	// Gestion du temps => � int�grer plus haut ?
	time(&end);
	double dif;
	dif = difftime (end,start);
	if (dif < TEMPS_BOUCLE)
	{
		disp.wait(TEMPS_BOUCLE - dif);
	}
}