#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "objet.h"
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
        objet*  getOccupant();
        void    setOccupant(objet* obj);
    private:
        coord   coordonnees;
        //int     coordx;
        //int     coordy;
        bool    occupe;
        objet*  occupant;
};


#endif // POINT_H_INCLUDED
