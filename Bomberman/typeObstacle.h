#ifndef TYPEOBSTACLE_H_INCLUDED
#define TYPEOBSTACLE_H_INCLUDED

#include <string>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <istream>
#include <iomanip>
#include <iostream>
#include <stdio.h>

class typeObstacle
{
    public:
        typeObstacle(bool destructible, bool passable, bool protection, char* f);//f est l'adresse de l'image
        int         getId();
        bool        estDestructible();
        bool        estPassable();
        bool        estProtection();
        char*       getImage();

    private:
        int     m_id;
        bool    m_destructible;
        bool    m_passable;
        bool    m_protection;
        char*   m_image;
};

typedef std::map<std::string,typeObstacle*> listeTypeObstacle;

void initialiserTypeObstacle(listeTypeObstacle &types, const char * fichier);


#endif // TYPEOBSTACLE_H_INCLUDED
