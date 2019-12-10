#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

char myAnd(char n1, char n2){
	char buffer0 = '0';
	char buffer1 = '1';
	if(n1 == buffer1 && n2 == n1){
		return buffer1;
	}

	else return buffer0;
}

int multiplicar(int digits, string num1, string num2 ){

	
	int mid = digits/2;
	string num1_left, num1_right;
	string num2_left, num2_right;

	num1_left = num1.substr(0, mid);
	num2_left = num2.substr(0, mid);

	num1_right = num1.substr(mid, digits);
	num2_right = num2.substr(mid, digits);

	cout << num1 << "\tleft: " << num1_left << "\tright: " << num1_right;
	cout << "\n";
	cout << num2 << "\tleft: " << num2_left << "\tright: " << num2_right;
	cout << "\n";
	return 0;
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
		cout << multiplicar(digits, num1, num2);
		cout << "\n";

	}

	cout << "\n";

	return 0;
}
