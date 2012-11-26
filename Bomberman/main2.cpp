#include <iostream>
//#include <map>
//#include <stdio.h>
//#include <string>
//#include <iomanip>
//#include <fstream>
#include "cases.h"
#include "carte.h"
//#include "CImg.h"

using namespace std;

int main()
{
    carte m;
    listeTypeObstacle types;

    initialiserTypeObstacle(types, "obstacles.config");
    initialiserCarte(types,m,"level.config");

    objet obj;

    objet* obj2 = m[coord (2,2)].getOccupant();
    //string s = (*obj2).getName(); //ça plante ici
    //typeObstacle *t = obs->getType();


    //cout << s << endl;
    cout << obj.getx() << "," << obj.gety() << endl;

    cout << "Point (1,1) : " << m[coord (1,1)].etat() << endl;
    cout << "Point (2,2) : " << m[coord (2,2)].etat() << endl;

    deplacer(m, &obj, 2, 2);

    cout << obj.getx() << "," << obj.gety() << endl;

    cout << "Point (1,1) : " << m[coord (1,1)].etat() << endl;
    cout << "Point (2,2) : " << m[coord (2,2)].etat() << endl;

    // << " " << m[coord (1,2)] << " " << m[coord (1,3)] << endl
    //     << m[coord (2,1)] << " " << m[coord (2,2)] << " " << m[coord (2,3)] << endl
    //     << m[coord (3,1)] << " " << m[coord (3,2)] << " " << m[coord (3,3)];

}


/*
void changer (int &n, int m)
{
    n = m;
}

int main()
{
    int n = 1;
    int m = 2;

    changer(n,m);

    cout << n;


}
*/
