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
	string buffer0 = "0";
	string buffer1 = "1";

	if(n1.compare("1") == 0 && n1.compare(n2) == 0){
		return buffer1;
	}

	else return buffer0;
}


// lista
void  eqLength(string &str1, string &str2){

	int len1 = str1.size();
	int len2 = str2.size();

	int overFlow = abs(len1 - len2);
	if(len1 < len2){
		for(int i = 0; i < overFlow; i++){
			str1 = '0' + str1;
		}
	}
	else if (len2 < len1)
	{
		for (int i = 0; i < overFlow; i++)
		{
			str2 = '0' + str2;
		}
	}
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
		buffer.append("0");
	}
	return num.append(buffer);
}




string mySum(string num1, string num2, int substract){

	string res = ""; 	// resultado
	int sum = 0;	 	// bit suma

	eqLength(num1, num2);

	int oSize = num1.size();

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

	if(substract){
		return res.substr(1,res.size());
	}
	return res;
}



string multiplicar(string num1, string num2 ){

	eqLength(num1, num2);

	int largo = num1.size();
	
	if (largo != 1){

		int mid = largo / 2;

		string num1_left, num1_right;
		string num2_left, num2_right;

		num1_left = num1.substr(0, mid);
		num2_left = num2.substr(0, mid);

		num1_right = num1.substr(mid, largo - mid);
		num2_right = num2.substr(mid, largo - mid);

		cout << "-----------------------------\n";
		cout << "num1: " << num1 << "\t";
		cout << "num2: " << num2 << "\n";
		cout << "-----------------------------\n";

		cout << "-----------------------------\n";
		cout << "Xl: " << num1_left << "\t";
		cout << "Xr: " << num1_right << "\n";
		cout << "Yl: " << num2_left << "\t";
		cout << "Yr: " << num2_right << "\n";
		cout << "-----------------------------\n";

		string p1 = multiplicar(num1_left, num2_left);
		string p2 = multiplicar(num1_right, num2_right);
		string p3 = multiplicar(mySum(num1_left, num1_right, 0), mySum(num2_left, num2_right, 0));

		cout << "-----------------------------\n";
		cout << "p1: " << p1 << "\n";
		cout << "p2: " << p2 << "\n";
		cout << "p3: " << p3 << "\n";
		cout << "-----------------------------\n";

		cout << "-----------------------------\n";
		p3 = mySum(p3, twoComp(p1), 1);

		cout << "comp p1: " << twoComp(p1) << "\t";
		cout << "p3 - p1: " << p3 << "\n";
		p3 = mySum(p3, twoComp(p2), 1);

		cout << "comp p2: " << twoComp(p2) << "\t";
		cout << "p3 - p2: " << p3 << "\n";
		p3 = shift(p3, mid);
		cout << "p3: " << p3 << "\n";
		cout << "-----------------------------\n";

		p1 = shift(p1, largo);
		cout << "p1: " << p1 << "\t\t";
		p1 = mySum(p1, p3, 0);
		cout << "after sum p1: " << p1 << "\n";

		cout << "-----------------------------\n";
		p1 = mySum(p1, p2, 0);
		cout << "res:\t" << p1 << "\n-----------------------------\n";

		return p1;
	}

	return myAnd(num1,num2);
}


int main(int argc, char **argv)
{
	//bits de los numeros
	int digits = 0;
	string num1;
	string num2;
	//cout << multiplicar("10","10") << "\n";

	//leer cantidad de bits de multiplicacion
	while (cin >> digits){

		//get numero 1
		cin >> num1;
		//get numero 2
		cin >> num2;
		//cout << "\nayy lmaao\n" << num1 << "\n" << num2 << "\nayy lmaao\n";
		cout << "res: "<< multiplicar(num1, num2);
	
		
		cout << "\n";

	}
	

	cout << "\n";

	return 0;
}
