#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int search(string tree, vector<int> Preorder, int floor, int value){

	int i,k;
	int parIzq = 0;
	int ret;

	for(i = 0; parIzq < floor + 1; i++){
		if (tree[i] == '('){
			parIzq++;
		} 
	}
	
	ret = parIzq-1;

	for(k = i-1; -1 < k; k--){
		if(tree[k] == ')'){
			k--;
			parIzq--;
		}
		else if (tree[k]=='('){
			if (Preorder[parIzq-1] >= value){
				ret = parIzq - 1;
				parIzq--;
			}
			else return ret;
		}
	}
	return ret;
}


int main(){

	// parentesis del arbol
	string tree;

	string bufferParentesis;
	
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
/*
		cout << "Nodes: " << nodeQuantity << "\nTree: " << tree << "\nPreorder: ";
		for(auto x: Preorder){
			cout << x << " ";
		}
		*/
		cout << Q << "\n"; 
		// get numeros para cada consulta
		for (int i = 0; i < Q; i++)
		{
			cin >> Q1;
			cin >> Q2;
			cout << search(tree, Preorder, Q1, Q2) << "\n";
		}
		Preorder.clear();
	}
	return 0;

}