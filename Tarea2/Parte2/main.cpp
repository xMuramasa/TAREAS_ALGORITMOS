#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
#include <time.h>


int main(){

	// parentesis del arbol
	string tree;
	
	//recorrido preorder
	string preOrder;
	vector<int> Preorder;
	int buffer;
	
	// cantidad de nodos del arbol
	int nodeQuantity;
	
	// cantidad de queries y numeros para ellas
	int Q;
	int Q1, Q2;
	
	while (cin >> nodeQuantity)
	{
		// get de los parentesis
		cin >> tree;
		cin.ignore(256, '\n'); // se ignora el slto de linea

		// se toma la linea de preorder como string para almacenarla en un vector de enteros
		// con esto se cubre la posicion de preorden y el almacenamiento de numero
		// por mientras 
		// TODO
		getline(cin, preOrder);

		istringstream iss (preOrder);
		while (iss >> buffer)
		{
			Preorder.push_back(buffer);
		}
		
		// Get cantidad de queries
		cin >> Q;

		cout << "Nodes: " << nodeQuantity << "\nTree: " << tree << "\nPreorder: ";
		for(auto x: Preorder){
			cout << x << " ";
		}
		
		cout << "\nQ: " << Q << "\n"; 

		// get numeros para cada consulta
		while (cin >> Q1){
			cin >> Q2;
			cout << "Q1: " << Q1 << "\tQ2: " << Q2;
			puts("");
		}
		
	}
	return 0;

}