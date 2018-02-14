#include "stdafx.h"
#include "P2D.h"


P2D::P2D() 
{
	x = 0;
	y = 0;
}

P2D::P2D(double a, double b): x(a), y(b)
{
}

double P2D::Distancia(P2D p)
{
	return sqrt(pow(p.x - this->x, 2) + pow(p.y - this->y, 2));
}

