#include "stdafx.h"
#include "Circunferencia.h"


Circunferencia::Circunferencia()
{
	centro = P2D();
	z = 200;
	nombre = "NULL";
}

Circunferencia::Circunferencia(P2D c, double z0, string N): centro(c), z(z0), nombre(N)
{
}

