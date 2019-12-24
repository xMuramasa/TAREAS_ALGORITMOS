#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;



//lista
string myAnd(string n1, string n2){

	if(n1[0] == '1' && n1[0] == n2[0]){
		return "1";
	}

	else return "0";
}


// lista
int  eqLength(string &str1, string &str2, int substract){

	int len1 = str1.size();
	int len2 = str2.size();

	int overFlow = abs(len1 - len2);

	if(len1 < len2){
		for(int i = 0; i < overFlow; i++){
			str1 = "0" + str1;
		}
		return len2;
	}
	else if (len2 < len1)
	{
		if(!substract){
			for (int i = 0; i < overFlow; i++)
			{
				str2 = "0" + str2;
			}
		}
		else
		{
			for (int i = 0; i < overFlow; i++)
			{
				str2 = "1" + str2;
			}
		}
	}
	return len1;
}


//lista
string twoComp(string number){
	int flag = 0;
	int i = 0;

	if(number.size() > 1){
		for (i = number.size() - 1; i > 0; i--)
		{
			if(number[i] == '1'){
				flag = 1;
				break;
			}
		}

		if (flag){
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


//lista
string shift(string num, int amt)
{
	string buffer = "";
	int i;
	for (i = 0; i < amt; i++)
	{
		buffer = buffer +"0";
	}
	return num + buffer;
}


//lista

string mySum(string num1, string num2, int substract){

	string res = ""; 	// resultado
	int sum = 0;	 	// bit suma

	int oSize = eqLength(num1, num2, substract);

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

	if(substract){
		return res.substr(1, res.size());
	}
	else 
		return res;
}

/*
string mySum(string first, string second, int flag)
{
	string result; // To store the sum bits
	// make the lengths same before adding
	int length = eqLength(first, second);
	int carry = 0; // Initialize carry

	// Add all bits one by one
	for (int i = length - 1; i >= 0; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';

		// boolean expression for sum of 3 bits
		int sum = (firstBit ^ secondBit ^ carry) + '0';

		result = (char)sum + result;

		// boolean expression for 3-bit addition
		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}

	// if overflow, then add a leading 1
	if (carry)
		result = '1' + result;

	return result;
}
*/

string testmult(string num1, string num2){

	int largo = eqLength(num1, num2, 0);

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

	cout << "-----------------------------\n";
	cout << "num1: " << num1 << "\t";
	cout << "num2: " << num2 << "\n";
	cout << "Xl: " << num1_left << "\t";
	cout << "Xr: " << num1_right << "\n";
	cout << "Yl: " << num2_left << "\t";
	cout << "Yr: " << num2_right << "\n";
	cout << "-----------------------------\n";

	string p1 = testmult(num1_left, num2_left);
	cout << "P1 = " << p1 << "\n";
	string p2 = testmult(num1_right, num2_right);
	cout << "P2 = " << p2 << "\n";

	string sum1 = mySum(num1_left, num1_right,0);
	string sum2 = mySum(num2_left, num2_right,0);
	string p3 = testmult(sum1,sum2);
	cout << "P3 = " << p3 << "\n";

	cout << "Before shift-----------------------------\n";
	cout << "p1: " << p1 << "\n";
	cout << "p2: " << p2 << "\n";
	cout << "p3: " << p3 << "\n";
	cout << "-----------------------------\n";

	string sum3;
	string p4 = twoComp(p1);
	string p5 = twoComp(p2);

	cout << "COMPLEMENT-----------------------------\n";
	cout << "p1: " << p1 << "\t";
	cout << "p4: " << p4 << "\n";
	cout << "p2: " << p2 << "\t";
	cout << "p5: " << p5 << "\n";
	cout << "-----------------------------\n";

	sum3 = mySum(p3, p4, 1);
	cout << "p31 " << sum3 << "\n";
	
	sum3 = mySum(p3, p5, 1);
	cout << "p32 " << sum3 << "\n";
	
	sum3 = shift(sum3, midIzq);
	cout << "p33 " << sum3 << "\n";

	p1 = shift(p1,largo);
	/*
	cout << "Sp1: " << p1 << "\n";
	cout << "p2: " << p2 << "\n";
	cout << "Sp3: " << sum3 << "\n";
	*/

	cout << "After shift-----------------------------\n";
	cout << "p1: " << p1 << "\n";
	cout << "p2: " << p2 << "\n";
	cout << "p3: " << sum3 << "\n";
	cout << "-----------------------------\n";

	string res;
	res = mySum(sum3,p2,0);
	res = mySum(p1,res,0);

	return res;
}
/*
string multiplicar(string num1, string num2){

	int largo = eqLength(num1, num2);
	
	if (largo == 0) return "0";
	else if (largo == 1) return myAnd(num1, num2);

	int midIzq = largo / 2;
	int midDer = largo - midIzq;
	
	string num1_left = num1.substr(0, midIzq);
	string num1_right = num1.substr(midIzq, midDer);

	string num2_left = num2.substr(0, midIzq);
	string num2_right = num2.substr(midIzq, midDer);
	/*
	cout << "-----------------------------\n";
	cout << "num1: " << num1 << "\t";
	cout << "num2: " << num2 << "\n";
	cout << "Xl: " << num1_left << "\t";
	cout << "Xr: " << num1_right << "\n";
	cout << "Yl: " << num2_left << "\t";
	cout << "Yr: " << num2_right << "\n";
	cout << "-----------------------------\n";
	/
	string p1 = multiplicar(num1_left, num2_left); cout << "P1 = "<<p1<<"\n";
	string p2 = multiplicar(num1_right, num2_right);
	cout << "P2 = " << p2 << "\n";
	string aux1 = mySum(num1_left, num1_right, 0);
	string aux2 = mySum(num2_left, num2_right, 0);
	int temp = eqLength(aux1, aux2);
	string p3 = multiplicar(aux1, aux2);
	cout << "P3 = "<<p3<<"\n";

	//eqLength(p1,p2);
	//eqLength(p2,p3);

	
	cout << "Before-----------------------------\n";
	cout << "p1: " << p1 << "\n";
	cout << "p2: " << p2 << "\n";
	cout << "p3: " << p3 << "\n";
	cout << "-----------------------------\n";

	int oSize = eqLength(p3, p1);
	p3 = mySum(p3, twoComp(p1), 1);
	cout << "p31 " << p3 << "\n";
	oSize = eqLength(p3, p2);
	p3 = mySum(p3, twoComp(p2), 1);
	cout << "p32 " << p3 << "\n";
	p3 = shift(p3, midIzq);
	cout << "p33 " << p3 << "\n";

	p1 = shift(p1, largo);

	cout << "After-----------------------------\n";
	cout << "p1: " << p1 << "\n";
	cout << "p2: " << p2 << "\n";
	cout << "p3: " << p3 << "\n";
	cout << "-----------------------------\n";

	string result = mySum(mySum(p1, p3, 0), p2, 0);
	
	return result;
}
*/


int main(int argc, char **argv)
{
	//bits de los numeros
	int digits = 0;
	string num1;
	string num2;
	cout << testmult("100","101") << "\n";
	//leer cantidad de bits de multiplicacion
	while (cin >> digits)
	{

		//get numero 1
		cin >> num1;
		//get numero 2
		cin >> num2;
		//cout << "\nayy lmaao\n" << num1 << "\n" << num2 << "\nayy lmaao\n";
		cout << "res: "<< testmult(num1, num2);
	
		
		cout << "\n";

	}
	

	cout << "\n";

	return 0;
}
