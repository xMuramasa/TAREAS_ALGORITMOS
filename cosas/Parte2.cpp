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

//lista
string myAnd(char n1, char n2)
{

    if (n1 == '1' && n1 == n2)
    {
        return "1";
    }

    else
        return "0";
}

// lista
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

//lista
string mySum(string num1, string num2)
{

    string res = ""; // resultado
    int sum = 0;     // bit suma

    int oSize = eqLength(num1, num2);
    int i = oSize - 1;
    int j = oSize - 1;

    // se empieza pro los bits del final

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

//lista
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


string slowPokeMul(string x, string y, int n)
{

    //int size = eqLength(x,y);
    string result = "0";
    string temp = "";
    int cont = 0;
    cout << "-------------------------\n";

    for (int i = n-1; i > -1; i--)
    {
        //cout << "x: " << x[i] << "\n";
        for (int j = n-1; j > -1; j--)
        {
            cout << "x " << x[i] << "\n ";
            cout << "y " << y[j] << "\n ";
            temp = myAnd(x[i], y[j]) + temp;
            cout << "TEMP: " << temp << "\n";
        }

        temp = shift(temp, cont);
        result = mySum(result, temp);

        cont++;
        temp = "";

        cout << "suma: " << result << "\n";
        cout << "-------------------------\n";
    }
    //cout << "FINAL: " << result << "\n";

    return "yes";
}

int main(int argc, char **argv)
{
	//bits de los numeros
	int digits = 0;
	string num1;
	string num2;
	//leer cantidad de bits de multiplicacion
    //cout << myAnd('1', '1');
    //cout << slowPokeMul2("11", "11", 2) << "\n";
    while (cin >> digits)
	{
        clock_t tStart = clock();
        //get numero 1
		cin >> num1;
		//get numero 2
		cin >> num2;
		//cout << slowPokeMul1(num1, num2, digits)<< "\n";
        cout << slowPokeMul(num1, num2, digits)<< "\n";
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	}
    return 0;
}