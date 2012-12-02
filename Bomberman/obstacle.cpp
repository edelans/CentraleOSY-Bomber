#include "obstacle.h"

Obstacle::Obstacle(typeObstacle* t):
    type(t)
    {
    }

Obstacle::Obstacle(typeObstacle* t, char* f):
    Objet(f),
    type(t)
    {
    }

