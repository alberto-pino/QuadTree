#pragma once
#include <iostream>
#include "P2D.h"
#include "Circunferencia.h"
#include <vector>
using namespace std;

class Quad
{
public:
	
	// El quad lo construimos con referencia a sus 4 quads interiores, el tamaño, la esquina superior izquierda y la lista de circunferencias 
	// asignadas a nuestro quad. 
	// Solamente guardaremos todas las circunferencias interiores si es un quad final, que no tenga quad hijos, en caso de ser padre solo
	// guardamos las circunferencias de la cruz central de radio 100 que son las que podrían dar problemas.

	Quad* q1;
	Quad* q2;
	Quad* q3;
	Quad* q4;

	vector<Circunferencia> lista;

	int size;
	P2D esq;

	Quad();
	Quad(vector<Circunferencia> l, P2D e, int s);
	~Quad();
	
	Circunferencia Query(P2D p);
};

