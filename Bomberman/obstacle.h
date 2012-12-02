#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

#include "objet.h"
#include "typeObstacle.h"


class Obstacle : public Objet
{
    public:
        Obstacle(typeObstacle* t);
        Obstacle(typeObstacle* t, char* f);//f est l'adresse du fichier image
        typeObstacle*   getType();
        void            changerType(typeObstacle*);
    private:
        typeObstacle*   type;
};


#endif // OBSTACLE_H_INCLUDED
