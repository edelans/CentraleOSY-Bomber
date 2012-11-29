#include <cstring>
#include <sstream>
#include "typeObstacle.h"
#include "carte.h"


typeObstacle::typeObstacle(bool destructible, bool passable, bool protection):
    destructible(destructible),
    passable(passable),
    protection(protection)
    {
    }

int typeObstacle::getId(){
    return this->id;}

bool typeObstacle::estDestructible(){
    return this->destructible;}

bool typeObstacle::estPassable(){
    return this->passable;}

bool typeObstacle::estProtection(){
    return this->protection;}



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
                if ((donnee != "0") and (donnee != "1")){
                    cerr << "Le fichier de configuration d'obstacles est invalide :\n Les colonnes ne doivent contenir que des 0 ou des 1\n" << donnee <<"\n\n";
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
