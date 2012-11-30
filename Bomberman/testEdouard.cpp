#include <iostream>

#include <ctime>

using namespace std;

int main()
{

clock_t debut, fin;

debut = clock();

fin = clock();

while ((fin - debut)< 5000) // 5000 ms
{

fin = clock();

}

cout << "Temps ecoule en secondes : " <<(fin - debut)/1000 << endl << endl;

system("PAUSE");
return 0;
}