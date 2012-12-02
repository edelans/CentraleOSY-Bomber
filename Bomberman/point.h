#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "Objet.h"


class point //le nom case est déjà pris
{
    public:
        point();
        point(int x, int y);
        point(int x, int y, char* f);//f est l'adresse de l'image correspondant au sol
        coord       getCoord();
        int         getx();
        int         gety();
        bool        estOccupe();
        bool        estPassable();
        std::string etat();
        Objet*      getOccupant();
        void        setOccupant(Objet* obj);
        Image       affiche();

    private:
        coord       coordonnees;
        //int       coordx;
        //int       coordy;
        bool        occupe;
        Objet*      occupant;
        char*       m_image;
};


#endif // POINT_H_INCLUDED
