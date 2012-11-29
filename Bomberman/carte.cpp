#include "carte.h"
#include "obstacle.h"
#include <cstring>
//#include <string>
#include <sstream>
using namespace std;

void deplacer (carte &m, objet *obj, int x, int y)
{
    int x1 = obj->getx();
    int y1 = obj->gety();

    int x2 = x;
    int y2 = y;

    point *p1 = &(m[coord (x1,y1)]);
    point *p2 = &(m[coord (x2,y2)]);

    p1->setOccupant(NULL);
    p2->setOccupant(obj);

    obj->setCoord(x2,y2);

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

		m[coord (NumeroLigne,NumeroColonne)] = point(NumeroLigne,NumeroColonne);

        if (typeCase != "0")
        {
            if (types[typeCase] != NULL){
                obstacle obs(types[typeCase]);
                char* nom = "obstacle";
                obs.setName("obstacle");
                deplacer(m, &obs, NumeroLigne, NumeroColonne);
            }else{
                cerr << "Le numéro indiqué dans le niveau ne correspond pas à un type d'obstacle";
            }


        }

		NumeroCase++;

    }

    is.close();

}
