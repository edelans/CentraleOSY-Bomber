#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include "assets/CImg.h"
#include <map>
#include <string>

// using namespace std; ATTENTION : PAS de namespace std dans les .h (cf site du zero)

typedef std::pair <int,int> coord;
typedef cimg_library::CImg<unsigned char> Image;

class Objet
{
    public:
		Objet();
		Objet(coord xy);
		Objet(char* f);//f est l'adresse de l'image de l'objet
		~Objet();

        coord       getCoord();
        int         getx();
        int         gety();
        void        setCoord(int x, int y);
        bool        estPassable();
        Image       affiche();

    protected:  // pour que les attributs soient accessibles depuis les classes filles (nécessaire pour le deposeBombe() de Personnage)
        coord       m_coordonnees;
        bool        m_passable;
        char*       m_image;
};



#endif // OBJET_H_INCLUDED
