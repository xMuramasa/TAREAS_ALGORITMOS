#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

string myAnd(string n1, string n2){
	string buffer0 = "0";
	string buffer1 = "1";

	if(n1.compare("1") == 0 && n1.compare(n2) == 0){
		return buffer1;
	}

	else return buffer0;
}

string twoComp(string number){
	int flag = 0;
	int i = 0;
	for (i = number.size() - 1; i > 0; i--)
	{
		if(number[i] == '1'){
			break;
		}
	}

	for(i = i-1; i > -1; i--){
		if (number[i] == '1'){
			number[i] = '0';
		}
		else number[i] = '1';
	}
	return number;
}


string mySum(string num1, string num2){

	string res = ""; 	// resultado
	int sum = 0;	 	// bit suma

	// se empieza pro los bits del final
	int i = num1.size() - 1, j = num2.size() - 1;

	while (i >= 0 || j >= 0 || sum == 1)
	{
		// suma de los digitos y el resto
		sum += ((i >= 0) ? num1[i] - '0' : 0);
		sum += ((j >= 0) ? num2[j] - '0' : 0);

		// si el digito suma es 1 o 3 se agrega 
		res = char(sum % 2 + '0') + res;

		// carry
		sum /= 2;

		// sigiuente digito
		i--;
		j--;
	}
	return res;
}

string multiplicar(string num1, string num2 ){

	int largo = max(num1.length(),num2.length());
	int mid = largo/2;
	
	if (largo == 1){
		return myAnd(num1,num2);
	}

	string num1_left, num1_right;
	string num2_left, num2_right;

	num1_left = num1.substr(0, mid);
	num2_left = num2.substr(0, mid);

	num1_right = num1.substr(mid, largo);
	num2_right = num2.substr(mid, largo);

	cout << num1 << "\tleft: " << num1_left << "\tright: " << num1_right;
	cout << "\n";
	cout << num2 << "\tleft: " << num2_left << "\tright: " << num2_right;
	cout << "\n";


	string p1 = multiplicar(num1_left, num2_left);
	string p2 = multiplicar(num1_right, num2_right);
	string p3 = multiplicar(mySum(num1_left, num1_right), mySum(num2_left, num2_right));

	cout << "p1: " << p1 <<"\np2: "<< p2<<"\np3: "<< p3;

	return "hola";
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
		//cout << mySum(twoComp(num1), num2) << "\n";
		cout << multiplicar(num1, num2);
		cout << "\n";

	}

	cout << "\n";

	return 0;
}
