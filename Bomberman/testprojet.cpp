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

CImg<unsigned char> game(LONGUEUR_MAX*TAILLE_CASE, LARGEUR_MAX*TAILLE_CASE, 1, 3);

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
	ifstream is(file); // tous les num�ros codant les cases dans le fichier sont lues
	if(!is) 
        {       
            cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
	string s;
	int longueur_niveau;
	getline(is,s);
	longueur_niveau = (s.size()+1)/2; // on r�cup�re la taille du niveau (nombre de cases sur une ligne)
	is.seekg(0,ios::beg);

	int d�calage_X = (LONGUEUR_MAX - longueur_niveau)*TAILLE_CASE/2;
	int d�calage_Y = (LARGEUR_MAX - longueur_niveau)*TAILLE_CASE/2;

	string nombre;
	int NumeroCase = 1;

	while (is >> nombre) // parcours de chaque case cod�e dans le fichier de niveau
	{
		int value =	atoi(nombre.c_str());
		int NumeroLigne;
		int NumeroColonne;
		NumeroLigne = (NumeroCase-1)/longueur_niveau + 1;
		NumeroColonne = NumeroCase - (NumeroCase-1)/longueur_niveau*longueur_niveau;
		switch (value)
		{
		case 1:
			game.draw_image((NumeroColonne - 3/2)*TAILLE_CASE + d�calage_X,(NumeroLigne - 3/2)*TAILLE_CASE + d�calage_Y,sol);
			break;
		case 2:
			game.draw_image((NumeroColonne - 3/2)*TAILLE_CASE + d�calage_X,(NumeroLigne - 3/2)*TAILLE_CASE + d�calage_Y,murdestr);
			break;
		case 3:
			game.draw_image((NumeroColonne - 3/2)*TAILLE_CASE + d�calage_X,(NumeroLigne - 3/2)*TAILLE_CASE + d�calage_Y,mur);
			break;
		default:
			cerr << "Fichier non conforme au type attendu : la case num�ro " << NumeroCase << " ne correspond pas � un type de terrain dans le champ attendu" << endl;
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
	CImgDisplay disp(game, "jeu");

	int i;
	cin >> i;
	return 0;
}