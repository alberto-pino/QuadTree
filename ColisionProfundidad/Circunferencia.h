#pragma once
#include <iostream>
#include "P2D.h"
#include <string>
using namespace std;

class Circunferencia
{
public:
	P2D centro;
	double z;
	string nombre;

	Circunferencia();
	Circunferencia(P2D c, double z0, string n);

};

