#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class P2D
{
public:
	double x, y;

	P2D();
	P2D(double a,double b);

	double Distancia(P2D p);
};

