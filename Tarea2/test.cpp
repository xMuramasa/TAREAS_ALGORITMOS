#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

//definicion de tipos
typedef vector<int> number;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++)
	{
		std::cout << input.at(i) << ' ';
	}
}

int main(int argc, char **argv)
{
	//bits de los numeros
	int digits = 0;
	string num1;
	string num2;
	//cantidad de char en una linea lmao
	int doubleD = 0;
	//contador
	int i = 0;
	//cantidad de vertices
	number first;
	// vertice del grafo
	number second;

	//bits
	int bit = 0;

	//dummy thing
	char dummy;

	//linea
	string line; 

	//leer cantidad de bits de multiplicacion
	while (cin >> digits){

		//get numero 1
		cin >> num1;
		//get numero 2
		cin >> num2;
		cout << "\nayy lmaao\n" << num1 << "\n" << num2 << "\nayy lmaao\n";

	}

	cout << "\n";

	return 0;
}
