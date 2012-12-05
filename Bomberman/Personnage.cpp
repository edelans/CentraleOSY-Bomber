#include "Personnage.h"

#define TAILLE_CASE				32
#define TAILLE_PERSONNAGE		TAILLE_CASE-10 // la différence de taille doit être paire
#define VITESSE_DEPLACEMENT		TAILLE_CASE/4

using namespace std;


char* pictoJoueur = "assets/Joueur.png";
char* pictoEnnemi = "assets/Ennemi.png";



void Personnage::decrementeCompteurDeBombe(Personnage* p)
{
	p->m_compteurDeBombe-=1;
}


Personnage::Personnage(int typePerso) : Objet() // constructeur du personnage
{
	if (m_typePerso == 1)
	{
		this->m_image = pictoJoueur; // personnage du joueur
	}
	else
	{
		this->m_image = pictoEnnemi;
	}
	this->m_vie = m_maxVie;
	this->m_maxVie = 3;
	this->m_tailleSacBombe = 2;
	this->m_typePerso = typePerso;
	this->m_scopeDestruction = 3; // zone de destruction des bombes poseés par le personnage
}


void Personnage::modifVie(signed int deltaVie) // prévoit les bonus de type potions ou autre
{
	if (m_vie + deltaVie <= 0)
	{
		m_vie = 0;
		//m_estVivant = false;
	}
	else if (m_vie + deltaVie >= m_maxVie)
	{
		m_vie = m_maxVie;
	}
	else
	{
		m_vie += deltaVie;
	}
}

void Personnage::powerUpSacBombe(int deltaSac)
{
	m_tailleSacBombe += deltaSac;
}

bool Personnage::estVivant()
{
	if (m_vie > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Personnage::afficheLastAction()
{
	return m_lastAction;
}

int Personnage::getVitesse()
{
    return m_vitesse;
}

void Personnage::modifVitesse(int deltaVitesse)
{
    int nouvelleVitesse = this->m_vitesse + deltaVitesse;
    if (nouvelleVitesse > 0)
    {
        this->m_vitesse = nouvelleVitesse;
    }
}

void Personnage::updateLastAction(time_t time)
{
	m_lastAction = time;
}


void Personnage::deposeBombe(carte &m)
{
	if (m_compteurDeBombe<m_tailleSacBombe)
	{
		Bombe b( m_coordonnees, m_scopeDestruction, this);   //on appelle le constructeur de la classe Bombe avec les coordonnées du personnage.
		deplacer(m, &b, m_coordonnees.first, m_coordonnees.second);  // a checker pour le & ...
		m_compteurDeBombe +=1;
	}
}

void Personnage::deplacerhaut(carte &m)
{
	int x = this->getx();
	int y = this->gety();
	int decalage_x_gauche = x-x/TAILLE_CASE*TAILLE_CASE; // nombre positif, calcule de combien de pixels le personnage est décalé du bord de sa case actuelle

	if (decalage_x_gauche < TAILLE_PERSONNAGE/2) // empiète sur la case de gauche
	{
		if (y/TAILLE_CASE > 0 && m[coord(x/TAILLE_CASE, y/TAILLE_CASE)].estPassable() && m[coord(x/TAILLE_CASE+1, y/TAILLE_CASE)].estPassable()) // les 2 cases gauche haut et haut doivent être passables
		{
			m_coordonnees.second -= VITESSE_DEPLACEMENT;
		}

	}
	else if (decalage_x_gauche > TAILLE_CASE-TAILLE_PERSONNAGE) // empiète sur la case de droite
	{
		if (y/TAILLE_CASE > 0 && m[coord(x/TAILLE_CASE+1, y/TAILLE_CASE)].estPassable() && m[coord(x/TAILLE_CASE+2, y/TAILLE_CASE)].estPassable()) // les 2 cases droite haut et haut doivent être passables
		{
			m_coordonnees.second -= VITESSE_DEPLACEMENT;
		}
	}
	else
	{
		if (y/TAILLE_CASE > 0 && m[coord(x/TAILLE_CASE+1, y/TAILLE_CASE)].estPassable()) // la case du dessus doit etre passable
		{
			m_coordonnees.second -= VITESSE_DEPLACEMENT;
		}
	}
}

//-----

void deplacerPerso(carte &m, Personnage* perso, int direction)
{
    //direction : 1 = droite, 2 = haut, 3 = gauche, 4 = bas

    int x = perso->getx();
    int y = perso->gety();

    int distance = perso->getVitesse();
    int i = 0;
    int estDeplace;

    switch (direction)
    {
        case 1:
            estDeplace = deplacer(m, perso, x+1, y);
            while ((estDeplace)&&(i<distance))
            {
                estDeplace = deplacer(m, perso, x+1, y);
                i++;
            }
            break;
        case 2:
            estDeplace = deplacer(m, perso, x, y+1);
            while ((estDeplace)&&(i<distance))
            {
                estDeplace = deplacer(m, perso, x, y+1);
                i++;
            }
            break;
        case 3:
            estDeplace = deplacer(m, perso, x-1, y);
            while ((estDeplace)&&(i<distance))
            {
                estDeplace = deplacer(m, perso, x-1, y);
                i++;
            }
            break;
        case 4:
            estDeplace = deplacer(m, perso, x, y-1);
            while ((estDeplace)&&(i<distance))
            {
                estDeplace = deplacer(m, perso, x, y-1);
                i++;
            }
            break;
        default:
            break;
    }

}
