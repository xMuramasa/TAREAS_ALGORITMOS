#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;


int multiplicar(int digits, string num1, string num2){

}

int main(int argc, char **argv)
{
	//bits de los numeros
	int digits = 0;
	string num1;
	string num2;

	//leer cantidad de bits de multiplicacion
	while (cin >> digits){

		//get numero 1
		cin >> num1;
		//get numero 2
		cin >> num2;
		cout << "\nayy lmaao\n" << num1 << "\n" << num2 << "\nayy lmaao\n";
		cout << multiplicar(digits, num1, num2) << "\n";

	}

	cout << "\n";

	return 0;
}
