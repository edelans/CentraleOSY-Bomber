#include <iostream>
#include <stdio.h>
#include <time.h>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

#define LONGUEUR_MAX		24
#define LARGEUR_MAX			12
#define TAILLE_CASE			32
#define TEMPS_BOUCLE		1000

CImg<unsigned char> game(LONGUEUR_MAX*TAILLE_CASE, LARGEUR_MAX*TAILLE_CASE, 1, 3);

int main()
{
	CImgDisplay disp(game, "bomberman");
	int compte = 0;
	while (compte < 10)
	{
	time_t start,end;
	time(&start);
	switch (disp.released_key(0)) // retourne la dernière touche pressée
	{
		cout << "touche lachée" << endl;
	case 31U: // correspond à la touche Z
		cout << "haut" << endl;
	case 44U:
		cout << "gauche" << endl;
	case 45U:
		cout << "bas" << endl;
	case 46U:
		cout << "droite" << endl;
	}
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
