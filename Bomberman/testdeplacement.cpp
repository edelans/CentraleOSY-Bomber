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

CImg<unsigned char> sol("sol.bmp");
CImg<unsigned char> murdestr("murdestr.bmp");
CImg<unsigned char> mur("mur.bmp");

class drawing
{
public:
	void initialize(const string file) const;
};

void drawing::initialize(const string file) const
{
	ifstream is(file); // tous les numéros codant les cases dans le fichier sont lues
	if(!is) 
        {       
            cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
	string s;
	int longueur_niveau;
	getline(is,s);
	longueur_niveau = (s.size()+1)/2; // on récupère la taille du niveau (nombre de cases sur une ligne)
	is.seekg(0,ios::beg);

	int décalage_X = (LONGUEUR_MAX - longueur_niveau)*TAILLE_CASE/2;
	int décalage_Y = (LARGEUR_MAX - longueur_niveau)*TAILLE_CASE/2;

	string nombre;
	int NumeroCase = 1;

	while (is >> nombre) // parcours de chaque case codée dans le fichier de niveau
	{
		int value =	atoi(nombre.c_str());
		int NumeroLigne;
		int NumeroColonne;
		NumeroLigne = (NumeroCase-1)/longueur_niveau + 1;
		NumeroColonne = NumeroCase - (NumeroCase-1)/longueur_niveau*longueur_niveau;
		switch (value)
		{
		case 1:
			game.draw_image((NumeroColonne - 3/2)*TAILLE_CASE + décalage_X,(NumeroLigne - 3/2)*TAILLE_CASE + décalage_Y,sol);
			break;
		case 2:
			game.draw_image((NumeroColonne - 3/2)*TAILLE_CASE + décalage_X,(NumeroLigne - 3/2)*TAILLE_CASE + décalage_Y,murdestr);
			break;
		case 3:
			game.draw_image((NumeroColonne - 3/2)*TAILLE_CASE + décalage_X,(NumeroLigne - 3/2)*TAILLE_CASE + décalage_Y,mur);
			break;
		default:
			cerr << "Fichier non conforme au type attendu : la case numéro " << NumeroCase << " ne correspond pas à un type de terrain dans le champ attendu" << endl;
			break;
		}
		NumeroCase++;
	}
	is.close();
}


int main()
{
	game.fill(0);
	drawing d;
	d.initialize("testniveau.txt");
	CImgDisplay disp(LONGUEUR_MAX*TAILLE_CASE, LARGEUR_MAX*TAILLE_CASE);

	int compte = 0;
	while (compte < 30)
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