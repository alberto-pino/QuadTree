#include "stdafx.h"
#include "Quad.h"


Quad::Quad()
{
	q1 = nullptr;
	q2 = nullptr;
	q3 = nullptr;
	q4 = nullptr;

}

Quad::Quad(vector<Circunferencia> l, P2D e, int s)
{

	esq = e;
	size = s;


	//El constructor lo he programado de manera recursiva de manera que dandole la lista de circunferencias inicial, la esquina y el tamaño
	// nos contruye el quad inicial y todos sus hijos.

	if (l.size()>5) // como condicion de parada para no seguir creando hijos es que tengamos una lista de 5 o menos circunferencias
	{
		vector<Circunferencia> laux;

		vector<Circunferencia> v1;
		vector<Circunferencia> v2;
		vector<Circunferencia> v3;
		vector<Circunferencia> v4;

		// en el siguiente for, vamos mandando cada circunferencia al  vector de circunferencias que ira al quad hijo teniendo en cuenta 
		// la cruz central de radio 100 de manera que cualquiera que este en esta cruz se quedará en el quad padre

		for (int i = 0; i < (int) l.size(); i++)
		{
			if (l[i].centro.x < e.x + ((s / 2)-100))
			{
				if (l[i].centro.y < e.y + (s / 2) - 100)
					v1.push_back(l[i]);
				else if (l[i].centro.y > e.y + (s / 2) + 100)
					v3.push_back(l[i]);
			}
			else if (l[i].centro.x > e.x + (s / 2) + 100)
			{
				if (l[i].centro.y < e.y + (s / 2) - 100)
					v2.push_back(l[i]);
				else if (l[i].centro.y > e.y + (s / 2) + 100)
					v4.push_back(l[i]);
			}
			else laux.push_back(l[i]);
		}

		P2D e2 = P2D(e.x + s / 2, e.y);
		P2D e3 = P2D(e.x, e.y + s / 2);
		P2D e4 = P2D(e.x + s / 2, e.y + s / 2);

		q1 = new Quad(v1, e, (int)(s / 2));
		q2 = new Quad(v2, e2, (int)(s / 2));
		q3 = new Quad(v3, e3, (int)(s / 2));
		q4 = new Quad(v4, e4, (int)(s / 2));

		lista = laux;
	}
	else
	{
		q1 = nullptr;
		q2 = nullptr;
		q3 = nullptr;
		q4 = nullptr;
		lista = l;
	}
}


Quad::~Quad()
{
	delete q1;	
	delete q2;
	delete q3;
	delete q4;
}


Circunferencia Quad::Query(P2D p)
{
	//hemos creado el constructor base de manera que cree una circunferencia de z=200 cuando las que creamos para el quad son de z max 100

	Circunferencia candidata= Circunferencia();

	if (q1 != nullptr)
	{
		if (p.x < esq.x + (size / 2))
		{
			if (p.y < esq.y + (size / 2))
			candidata = q1->Query(p);
			else if (p.y > esq.y + (size / 2))
			candidata = q3->Query(p);
		}

		else if (p.x > esq.x + (size / 2))
		{
			if (p.y < esq.y + (size / 2))
			candidata = q2->Query(p);
			else if (p.y > esq.y + (size / 2))
			candidata = q4->Query(p);
		}

	}

	// tras el anterior if saldrá una candidata de uno de los 4 hijos (en caso de que los tenga) y ahora la comparará con las circunferencias
	// del padre (tened en cuenta que por la manera en la que hemos construido el quad, ninguna circunferencia del padre está en el hijo y
	// viceversa.

	for (int i = 0; i < (int) lista.size(); i++)
	{
		if (lista[i].centro.Distancia(p) < 100)
		{
			if (lista[i].z < candidata.z)
				candidata = lista[i];
		}
	}

	return candidata;

}