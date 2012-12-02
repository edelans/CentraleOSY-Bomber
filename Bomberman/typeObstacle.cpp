
#include "typeObstacle.h"
#include "carte.h"

using namespace std;

typeObstacle::typeObstacle(bool destructible, bool passable, bool protection,char* f):
    m_destructible(destructible),
    m_passable(passable),
    m_protection(protection),
    m_image(f)
    {
    }

int typeObstacle::getId(){
    return this->m_id;}

bool typeObstacle::estDestructible(){
    return this->m_destructible;}

bool typeObstacle::estPassable(){
    return this->m_passable;}

bool typeObstacle::estProtection(){
    return this->m_protection;}

char* typeObstacle::getImage(){
    return this->m_image;}


void initialiserTypeObstacle(listeTypeObstacle &types, const char * fichier)
{
    std::ifstream is(fichier);
    is.seekg(0,ios::beg);

    //map<string,typeObstacle*> types;
    string typesId;
    map<int,bool> typesParam;
    char* adresseImage;

    string s;
    streamoff nb_commentaires = 0;
    //char commentaire =
    getline(is,s);
    char c = s[0];
	while(c == '#')
	{
	    nb_commentaires++;
	    getline(is,s);
	}

    if (nb_commentaires == 0)
    {
        is.seekg(0,ios::beg);
    }

    string donnee;
    int compteur = 0;

    while (getline(is,s))
    {
        istringstream split(s);

        while(split >> donnee){
            compteur++;
            if (compteur == 1)
            {
                typesId = donnee; //identifiant du type
            }else if (compteur<=4){
                if ((donnee != "0") and (donnee != "1")){
                    cerr << "Le fichier de configuration d'obstacles est invalide :\n Les colonnes ne doivent contenir que des 0 ou des 1\n" << donnee <<"\n\n";
                }else{
                    typesParam[compteur] = bool (donnee == "1");
                }
            }else if (compteur == 5){
                adresseImage = new char [donnee.size()+1];//adresse de l'image correspondante
                strcpy(adresseImage,donnee.c_str());
            }
        }

        typeObstacle t (typesParam[1], typesParam[2], typesParam[3], adresseImage);
        types[typesId] = &t;
        compteur = 0;

    }

}
