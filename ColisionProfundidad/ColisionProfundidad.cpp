// ColisionProfundidad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "P2D.h"
#include "Circunferencia.h"
#include "Quad.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "omp.h"


using namespace std;


int main()
{

	srand((int) time(NULL));

	vector<Circunferencia> lc;


	for (int i = 0; i < 100000; i++)
	{
		P2D c = P2D((int)(1 + rand() % (10000 - 1)), (int)(1 + rand() % (10000 - 1)));
		lc.push_back (Circunferencia(c ,(int) (rand()%100) , "Circunferencia"));
	}

	double time1, time2;
	P2D esquina = P2D(0, 0);

	time1 = omp_get_wtime();
	Quad q = Quad(lc, esquina, 10000);
	time2 = omp_get_wtime();
	cout << "Tiempo de Generación de Quadtree: " << time2 - time1 << endl;

	P2D random = P2D((int)(1 + rand() % (10000 - 1)), (int)(1 + rand() % (10000 - 1)));
	

	time1 = omp_get_wtime();
	Circunferencia sol = q.Query(random);
	time2 = omp_get_wtime();
	cout << "Tiempo de busqueda: " << time2 - time1 << endl;

	//Si la circunferencia solucion del query tiene z=200 significa que es la candidata base que creabamos, lo que significa que no ha
	//encontrado ninguna instersección con otra circunferencia.

	if (sol.z != 200)
	{
		cout << "La circunferencia con menor z que incluye el punto (" << random.x << "," << random.y << ")"
			<< " es la circunferencia de radio 100 y centro (" << sol.centro.x << "," << sol.centro.y << ") y con z " << sol.z << endl;
	}
	else
		cout << "El punto ("<< random.x << "," << random.y <<") no esta contenido en ninguna circunferencia" << endl;

    return 0;
}

