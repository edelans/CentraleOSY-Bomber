#include <string>


//nos en-t�tes .h en lien direct avec le main (� compl�ter) :
#include "Objet.h"
#include "bombe.h"

#define TEMPS_BOUCLE		200

using namespace cimg_library;
using namespace std;

int main()
{
	Bombe a,b,c;
	cout << "Il y a" << (int) Bombe::instances.size() << "instances de Bombe" << endl;
}