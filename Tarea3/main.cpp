#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
#include <string>

// para cada hora de clase
typedef pair<long int, long int> horarioClase;

// para cada dia con cat
typedef vector<horarioClase> totalClases;

// funcion que imprime el vector de pares X
void display(totalClases X)
{
	for (auto x : X)
	{
		cout << x.first << " " << x.second << "\n";
	}
}

// funcion para sort de vector por primer elemento
bool myComp(horarioClase &a, horarioClase &b)
{
	return (a.first < b.first);
}

int main(int argc, char **argv)
{
	int flag1 = 1; // recorrido para obtener horarios
	int flag2 = 1; // horario valido

	// contad
	long int i,ii;

	//cantidad de lineas
	long int rowCount;
	// elementos de horario
	long int s, f;

	totalClases horarios;  // contiene lineas del archivo original
	totalClases inscritos; // output

	cin >> rowCount; // get cantidad de lineas

	int diff = 1; // diferencia de horas en horario

	long int max = 0; // hora maxima

	// get horarios disponibles
	for (i = 0; i < rowCount; i++)
	{
		cin >> s >> f;

		if (s < f){
			if (max < f)
				max = f;
		}


		horarios.push_back(make_pair(s, f)); // make_pair hace un par de elementos y push_back anade elementos al vector
	}


	// se inicializa el arreglo de horas ocupadas
	long int arr[max++];
	for (i = 0; i < max; i++)
	{
		arr[i] = 0;
	}

/*
	cout << "ANTES\n";
	display(horarios);
	cout << "\n\nDESPUES\n";
*/
	for (i = 0; i < rowCount; i++, diff++)
	{

		// se recorre el vector de horarios disponibles
		for (auto x : horarios)
		{
			flag2 = 1;

			if (diff == (x.second - x.first))
			{
				//agrego, no estan
				if ((arr[x.first] == 0) && (arr[x.second] == 0))
				{	
					if (diff == 1) // para la diferencia de horas igual a 1
					{
						inscritos.push_back(x);
						// se cambia las horas disponibles
						arr[x.first] = 1;
						arr[x.second] = 1;
					}

					else if (diff > 1)
					{
						// se verifica que no haya nada entre horarios disponibles
						for (ii = x.first; (ii < x.second + 1) && flag2; ii++)
						{
							if (arr[ii] == 1)
								flag2 = 0;	// horario no es valido
							
						}

						if (flag2)
						{
							inscritos.push_back(x);
							arr[x.first] = 1;
							arr[x.second] = 1;
						}
					}
				}
			}
		}
	}
	
	cout << inscritos.size() << "\n";
	sort(inscritos.begin(), inscritos.end(), myComp);
	display(inscritos);

	return 0;
}
