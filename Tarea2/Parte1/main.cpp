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

// header
string myAnd(string n1, string n2);
int eqLength(string &str1, string &str2);
string resta(string num1, string num2, string num3);
string juntar(string num1, string num2, string num3);
string twoComp(string number);
string shift(string num, int amt);
string mySum(string num1, string num2, int flag);
string multiplicar1(string num1, string num2);
string multiplicar2(string x, string y, int n);

	/* string myAnd
* accion  : multiplicacion de un bit
* prints  : nada
* returns : resultado de la multiplicacion
*/
	string myAnd(string n1, string n2)
{

	if (n1[0] == '1' && n1[0] == n2[0])
	{
		return "1";
	}

	else
		return "0";
}


/* string myAnd2
* accion  : multiplicacion de un bit, pero recibe char
* prints  : nada
* returns : resultado de la multiplicacion
*/
string myAnd2(char n1, char n2)
{

	if (n1 == '1' && n1 == n2)
	{
		return "1";
	}

	else
		return "0";
}


/* int eqLength
* accion  : cambia el largo de dos strings para que sean iguales
* prints  : nada
* returns : el tamano final
*/
int eqLength(string &str1, string &str2)
{

	int len1 = str1.size();
	int len2 = str2.size();

	int overFlow = abs(len1 - len2);

	if (len1 < len2)
	{
		for (int i = 0; i < overFlow; i++)
		{
			str1 = "0" + str1;
		}
		return len2;
	}
	else if (len2 < len1)
	{
		for (int i = 0; i < overFlow; i++)
		{
			str2 = "0" + str2;
		}
	}
	return len1;
}


/* string resta
* accion  : hace el calculo de la resta en el algoritmo de multiplicacion
* prints  : nada
* returns : la resta de p1 - p2 - p3
*/
string resta(string num1, string num2, string num3)
{

	int largo, overFlow;
	string p1, p2, p3, res;

	largo = eqLength(num1, num2);
	largo = eqLength(num2, num3);
	largo = eqLength(num3, num1);

	p1 = "0" + num1;
	p2 = "0" + num2;
	p3 = "0" + num3;

	p1 = twoComp(p1);
	p2 = twoComp(p2);

	res = mySum(p3, p1, 0);

	overFlow = largo - res.size();
	overFlow = abs(overFlow);

	if (largo < res.size())
	{
		res = res.substr(overFlow, res.size());
	}

	int temp = eqLength(res, p2);

	res = mySum(res, p2, 0);

	if (largo < res.size())
	{
		res = res.substr(overFlow, res.size());
	}

	return res;
}


/* string juntar
* accion  : hace el calculo final del algoritmo de multiplicacion
* prints  : nada
* returns : la suma de p1, p2, p3
*/
string juntar(string num1, string num2, string num3)
{
	int largo;
	string res;

	largo = eqLength(num1, num2);
	largo = eqLength(num2, num3);
	largo = eqLength(num3, num1);

	res = mySum(num1, num2, 0);
	largo = eqLength(res, num3);
	res = mySum(res, num3, 0);

	return res;
}


/* string twoComp
* accion  : hacel el 2 complemento de un numero binario
* prints  : nada
* returns : el numero complementado 
*/
string twoComp(string number)
{
	int flag = 0;
	int i = 0;

	if (number.size() > 1)
	{
		for (i = number.size() - 1; i > 0; i--)
		{
			if (number[i] == '1')
			{
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			for (i = i - 1; i > -1; i--)
			{
				if (number[i] == '1')
				{
					number[i] = '0';
				}
				else
					number[i] = '1';
			}
		}
	}

	return number;
}


/* string shift
* accion  : hace un logical left shift de un numero bin representado como string
* prints  : nada
* returns : el numero shifteado
*/
string shift(string num, int amt)
{
	string buffer = "";
	int i;
	for (i = 0; i < amt; i++)
	{
		buffer = buffer + "0";
	}
	return num + buffer;
}


/* string mmySum
* accion  : suma dos numeros bin representados como strings
* prints  : nada
* returns : suma de los numeros
*/
string mySum(string num1, string num2, int substract)
{

	string res = ""; // resultado
	int sum = 0;	 // bit suma

	int oSize = eqLength(num1, num2);

	// se empieza pro los bits del final
	int i = oSize - 1;
	int j = oSize - 1;

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


/* string multiplicar
* accion  : multiplica dos numeros bin representados como strings
* prints  : nada
* returns : multiplicacion de los dos strings 
*/
string multiplicar1(string num1, string num2)
{

	// se igualan los largos de los numeros para facilidad de calculos
	int largo = eqLength(num1, num2);

	if (largo == 0)
		return "0";
	else if (largo == 1)
		return myAnd(num1, num2);

	int midIzq = largo / 2;
	int midDer = largo - midIzq;

	string num1_left = num1.substr(0, midIzq);
	string num1_right = num1.substr(midIzq, midDer);

	string num2_left = num2.substr(0, midIzq);
	string num2_right = num2.substr(midIzq, midDer);

	string p1 = multiplicar1(num1_left, num2_left);

	string p2 = multiplicar1(num1_right, num2_right);

	int temp = eqLength(num1_left, num1_right);
	string sum1 = mySum(num1_left, num1_right, 0);

	temp = eqLength(num2_left, num2_right);
	string sum2 = mySum(num2_left, num2_right, 0);

	string p3 = multiplicar1(sum1, sum2);


	string subs = resta(p1, p2, p3);


	p1 = shift(p1, midDer * 2);

	subs = shift(subs, midDer);

	//else  subs = shift(subs, midDer);

	string res = juntar(p1, subs, p2);

	return res;
}


/* string multiplicar2
* accion  : multiplica dos numeros bin representados como strings fuerza bruta
* prints  : nada
* returns : multiplicacion de los dos strings 
*/
string multiplicar2(string x, string y, int n)
{

	string result = "0";
	string temp = "";
	int cont = 0;

	for (int i = n - 1; i > -1; i--)
	{
		for (int j = n - 1; j > -1; j--)
		{
			temp = myAnd2(x[i], y[j]) + temp;
		}

		temp = shift(temp, cont);
		result = mySum(result, temp, 0);

		cont++;
		temp = "";
	}

	return result;
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
		//tiempo
		clock_t tStart = clock();

		//cout << multiplicar1(num1, num2) << "\n";
		multiplicar1(num1, num2);

		//cout << multiplicar2(num1, num2, digits) << "\n";
		//multiplicar2(num1, num2, digits);

		// Esta linea indica el tiempo que demora en ejecutarse
		printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	}


	return 0;
}
