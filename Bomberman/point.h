#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "Objet.h"
#include <string>

using namespace std;

class point //le nom case est déjà pris
{
    public:
        point();
        point(int x, int y);
        coord   getCoord();
        int     getx();
        int     gety();
        bool    estOccupe();
        string  etat();
        Objet*  getOccupant();
        void    setOccupant(Objet* obj);
    private:
        coord   coordonnees;
        //int     coordx;
        //int     coordy;
        bool    occupe;
        Objet*  occupant;
};


#endif // POINT_H_INCLUDED
