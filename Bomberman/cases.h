#ifndef CASES_H_INCLUDED
#define CASES_H_INCLUDED
#include <map>
#include <stdio.h>
#include <string>

using namespace std;

typedef pair <int,int> coord;

class objet
{
    public:
        string  getName();
        void    setName(string s);
        coord   getCoord();
        int     getx();
        int     gety();
        void    setCoord(int x, int y);
        //void    setx(int x);
        //void    sety(int y);
        bool    estPassable();
    private:
        string  name;
        coord   coordonnees;
        //int     coordx;
        //int     coordy;
        bool    passable;
};

class typeObstacle
{
    public:
        typeObstacle(bool destructible, bool passable, bool protection);
        int     getId();
        bool    estDestructible();
        bool    estPassable();
        bool    estProtection();

    private:
        int     id;
        bool    destructible;
        bool    passable;
        bool    protection;
};

typedef map<string,typeObstacle*> listeTypeObstacle;

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

class obstacle : public objet
{
    public:
        obstacle(typeObstacle* t);
        typeObstacle*   getType();
        void            changerType(typeObstacle*);
    private:
        typeObstacle*   type;
};



#endif // CASES_H_INCLUDED
