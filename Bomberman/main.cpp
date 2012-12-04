#include "CImg.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>

using namespace cimg_library;
using namespace std;

#define LONGUEUR_MAX		24
#define LARGEUR_MAX			18
#define TAILLE_CASE			32
#define TEMPS_BOUCLE		400

CImg<unsigned char> game(LONGUEUR_MAX*TAILLE_CASE, LARGEUR_MAX*TAILLE_CASE, 1, 3);
CImg<unsigned char> gamerunning(LONGUEUR_MAX*TAILLE_CASE, LARGEUR_MAX*TAILLE_CASE, 1, 3);

int main()
{
	game.fill(0);
	drawing d;
	d.initialize("testniveau.txt");
	CImgDisplay disp(LONGUEUR_MAX*TAILLE_CASE, LARGEUR_MAX*TAILLE_CASE);
	
	int compte = 0;
	while (!disp.is_closed)
	{
		time_t start,end;
		time(&start);
		gamerunning.draw_image(game);
			switch (disp.key(0)) // retourne la dernière touche pressée
			{
			default:
				cout << "Pas de touche" << endl;
				gamerunning.draw_image(4*TAILLE_CASE,4*TAILLE_CASE,murdestr);
				break;
			case cimg::keyARROWUP:
				cout << "haut" << endl;
				gamerunning.draw_image(4*TAILLE_CASE,3*TAILLE_CASE,murdestr);
				break;
			case cimg::keyARROWLEFT:
				cout << "gauche" << endl;
				gamerunning.draw_image(3*TAILLE_CASE,4*TAILLE_CASE,murdestr);
				break;
			case cimg::keyARROWDOWN:
				cout << "bas" << endl;
				gamerunning.draw_image(4*TAILLE_CASE,5*TAILLE_CASE,murdestr);
				break;
			case cimg::keyARROWRIGHT:
				cout << "droite" << endl;
				gamerunning.draw_image(5*TAILLE_CASE,4*TAILLE_CASE,murdestr);
				break;
			}
	disp.set_key();
	time(&end);
	disp.display(gamerunning);
	double dif;
	dif = difftime (end,start);
	if (dif < TEMPS_BOUCLE)
	{
		disp.wait(); // étonnant car avec cette syntaxe, on devrait attendre un événement, et pourtant parfois aucune touche n'est détectée par l'ordinateur, alors que je ne fais qu'appuyer sur les flèches
		disp.wait(TEMPS_BOUCLE - dif);
	}
	cout << compte << endl;
	compte++;
	}
	int i;
	cin >> i;
}