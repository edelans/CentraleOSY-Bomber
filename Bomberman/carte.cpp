#include "carte.h"
#include "obstacle.h"
#include <cstring>
//#include <string>
#include <sstream>
using namespace std;

int largeur(carte m)
{
    carte::iterator it;
    int l = 0;

    for ( it=m.begin() ; it != m.end(); it++ )
    {
        if ((it->first).first > l)
        {
            l = (it->first).first;
        }
    }
    return l;
}

int hauteur(carte m)
{
    carte::iterator it;
    int h = 0;

    for ( it=m.begin() ; it != m.end(); it++ )
    {
        if ((it->first).second > h)
        {
            h = (it->first).second;
        }
    }
    return h;
}

int surface(carte m)
{
    return m.size();
}

void placer (carte &m, Objet *obj, int x, int y)
{
    point* p = &(m[coord (x,y)]);

    int x0 = obj->getCoord().first;
    int y0 = obj->getCoord().second;

    if ((x0 != 0)&&(y0 != 0))
    {

    }
    else
    {
        p->setOccupant(obj);
        obj->setCoord(x,y);
    }
}

int deplacer(carte &m, Objet *obj, int x, int y)
{
    //Coordonnees source
    int x1 = obj->getx();
    int y1 = obj->gety();
    //Coordonnees destination, initialement identiques
    int x2 = x1;
    int y2 = y1;
    //On vérifie que l'objet ne sort pas de la carte
    int l = largeur(m);
    int h = hauteur(m);
    if ((x>=0)&&(x<=l)){
        x2 = x;}
    if ((y>=0)&&(y<=l)){
        y2 = y;}

    point *p1 = &(m[coord (x1,y1)]);
    point *p2 = &(m[coord (x2,y2)]);

    Objet* occ = p1->getOccupant();

    if (p2->estOccupe())
    {
        return 0;
    }
    else
    {
        if (occ == obj){
            p1->setOccupant(NULL);}

        p2->setOccupant(obj);
        obj->setCoord(x2,y2);

        return 1;
    }
}

void initialiserCarte(listeTypeObstacle types, carte &m, const char * fichier)
{
    ifstream is(fichier);
    if(!is)
        {
            cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
	string s;
	getline(is,s);

	int longueur_niveau;
	longueur_niveau = (s.size()+1)/2; // on récupère la taille du niveau (nombre de cases sur une ligne)
	is.seekg(0,ios::beg);

    string typeCase;
    int NumeroCase = 1;


    while (is >> typeCase)
    {

		int NumeroLigne;
		int NumeroColonne;
		NumeroLigne = (NumeroCase-1)/longueur_niveau + 1;
		NumeroColonne = NumeroCase - (NumeroCase-1)/longueur_niveau*longueur_niveau;

        char* adresseImage = "assets/sol.bmp";
		m[coord (NumeroLigne,NumeroColonne)] = point(NumeroLigne,NumeroColonne,adresseImage);

        if (typeCase != "0")
        {
            if (types[typeCase] != NULL){
                char* f = types[typeCase]->getImage();
                Obstacle obs(types[typeCase],f);
                //string nom = "obstacle";
                //obs.setName(nom);
                deplacer(m, &obs, NumeroLigne, NumeroColonne);
            }else{
                cerr << "Le numéro indiqué dans le niveau ne correspond pas à un type d'obstacle";
            }


        }

		NumeroCase++;

    }

    is.close();

}
