#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include <map>

using namespace std;

typedef pair <int,int> coord;

class objet
{
    public:
        char*   getName();
        void    setName(char* s);
        coord   getCoord();
        int     getx();
        int     gety();
        void    setCoord(int x, int y);
        bool    estPassable();
    private:
        char*   name;
        coord   coordonnees;
        bool    passable;
};



#endif // OBJET_H_INCLUDED
