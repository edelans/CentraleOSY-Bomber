#ifndef TYPEOBSTACLE_H_INCLUDED
#define TYPEOBSTACLE_H_INCLUDED

#include <string>
#include <map>

using namespace std;

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

void initialiserTypeObstacle(listeTypeObstacle &types, const char * fichier);


#endif // TYPEOBSTACLE_H_INCLUDED
