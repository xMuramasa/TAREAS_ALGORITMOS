#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;



int transformToDec(string str){
    string num = str;
    int n = 0;

    int base = 1;

    int len = num.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            n += base;
        base = base * 2;
    }
    return n;
}

int slowPokeMul(int x, int y){
    return x*y;
}

int main(int argc, char **argv)
{
	//bits de los numeros
	int digits = 0;
	string num1;
	string num2;
	//leer cantidad de bits de multiplicacion
	while (cin >> digits)
	{

		//get numero 1
		cin >> num1;
		//get numero 2
		cin >> num2;
		cout << slowPokeMul(transformToDec(num1), transformToDec(num2))<< "\n";

	}
}