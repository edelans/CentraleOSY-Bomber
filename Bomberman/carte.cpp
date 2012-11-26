#include "carte.h"
#include <cstring>
#include <string>
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

void initialiserTypeObstacle(listeTypeObstacle &types, const char * fichier)
{
    ifstream is(fichier);
    is.seekg(0,ios::beg);

    //map<string,typeObstacle*> types;
    string typesId;
    map<int,bool> typesParam;

    string s;
	//getline(is,s);
    string donnee;
    int compteur = 0;

    while (getline(is,s))
    {
        istringstream split(s);

        while(split >> donnee){
            compteur++;
            if (compteur == 1)
            {
                typesId = donnee;
            }else{
                if ((donnee != "0") && (donnee != "1")){
                    cerr << "Le fichier de configuration d'obstacles est invalide :" << '\n' << "Les colonnes ne doivent contenir que des 0 ou des 1" << '\n' << donnee << '\n' << '\n';
                }else{
                    typesParam[compteur] = bool (donnee == "1");
                }
            }

        }

        typeObstacle t (typesParam[1], typesParam[2], typesParam[3]);
        types[typesId] = &t;
        compteur = 0;

    }

}
