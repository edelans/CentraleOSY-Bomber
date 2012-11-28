#include <iostream>
#include <stdio.h>
#include <time.h>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

#define LONGUEUR_MAX 24
#define LARGEUR_MAX 12
#define TAILLE_CASE 32
#define TEMPS_BOUCLE 1000

CImg<unsigned char> game(LONGUEUR_MAX*TAILLE_CASE, LARGEUR_MAX*TAILLE_CASE, 1, 3);

int main()
{
	CImgDisplay disp(game, "bomberman");
	int compte = 0;
	while (compte < 10)
	{
		time_t start,end;
		time(&start);
			switch (disp.key(0)) // retourne la dernière touche pressée
			{
			default:
				cout << "Pas de touche" << endl;
			case cimg::keyARROWUP: // correspond à la touche Z
				cout << "haut" << endl;
				break;
			case cimg::keyARROWLEFT:
				cout << "gauche" << endl;
				break;
			case cimg::keyARROWDOWN:
				cout << "bas" << endl;
				break;
			case cimg::keyARROWRIGHT:
				cout << "droite" << endl;
				break;
			}
		}

	disp.set_key();
	time(&end);
	double dif;
	dif = difftime (end,start);
	if (dif < TEMPS_BOUCLE)
	{
		disp.wait(TEMPS_BOUCLE - dif);
	}
	cout << compte << endl;
	compte++;
	}
	int i;
	cin >> i;
}
