#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

#include "objet.h"
#include "typeObstacle.h"

using namespace std;

class obstacle : public objet
{
    public:
        obstacle(typeObstacle* t);
        typeObstacle*   getType();
        void            changerType(typeObstacle*);
    private:
        typeObstacle*   type;
};


#endif // OBSTACLE_H_INCLUDED
