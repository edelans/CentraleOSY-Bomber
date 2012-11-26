#ifndef DRAWING
#define DRAWING

#include "CImg.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

#define LONGUEUR_MAX		24
#define LARGEUR_MAX			12
#define TAILLE_CASE			32

class drawing
{
public:
	void initialize(const string file) const;
};