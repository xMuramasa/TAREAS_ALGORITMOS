#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

// header
string myAnd(string n1, string n2);
int eqLength(string &str1, string &str2);
string resta(string num1, string num2, string num3);
string juntar(string num1, string num2, string num3);
string twoComp(string number);
string shift(string num, int amt);
string mySum(string num1, string num2, int flag);
string multiplicar(string num1, string num2);


//lista
string myAnd(string n1, string n2)
{

    if (n1[0] == '1' && n1[0] == n2[0])
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

    cout << "0p1: " << p1 << "\n";
    cout << "0p2: " << p2 << "\n";
    cout << "0p3: " << p3 << "\n";


    p1 = twoComp(p1);
    p2 = twoComp(p2);
    cout << "Cp1: " << p1 << "\n";
    cout << "Cp2: " << p2 << "\n";

    res = mySum(p3, p1, 0);
    cout << "Rp3: " << p3 << "\n";
    cout << "Rp1: " << p1 << "\n";

    overFlow = largo - res.size();
    overFlow = abs(overFlow);

    if(largo < res.size()){
        res = res.substr(overFlow, res.size());
    }
    cout << "res p3- p1: " << res << "\n";

    int temp = eqLength(res,p2);
    
    cout << "Rp3: " << res << "\n";
    cout << "Rp2: " << p2 << "\n";

    res = mySum(res, p2, 0);

    if(largo < res.size()){
        res = res.substr(overFlow, res.size());
    }
    cout << "res p3 - p2: " << res << "\n";

    return res;
}

string juntar(string num1, string num2, string num3)
{
    int largo;
    string res;

    largo = eqLength(num1, num2);
    largo = eqLength(num2, num3);
    largo = eqLength(num3, num1);

    cout << "Jp1: " << num1 << "\n";
    cout << "Jp2: " << num2 << "\n";
    cout << "Jp3: " << num3 << "\n";
    cout << "JCp3: " << num3 << "\n";

    res = mySum(num1, num2, 0);
    largo = eqLength(res, num3);
    res = mySum(res, num3, 0);

    cout << "Jres: " << res << "\n";

    return res;
}

//lista
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

//lista

string mySum(string num1, string num2, int substract)
{

    string res = ""; // resultado
    int sum = 0;     // bit suma

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



string multiplicar(string num1, string num2)
{

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

    cout << "-----------------------------\n";
    cout << "num1: " << num1 << "\t";
    cout << "num2: " << num2 << "\n";
    cout << "Xl: " << num1_left << "\t";
    cout << "Xr: " << num1_right << "\n";
    cout << "Yl: " << num2_left << "\t";
    cout << "Yr: " << num2_right << "\n";
    cout << "-----------------------------\n";

    string p1 = multiplicar(num1_left, num2_left);
    cout << "-----------------------------\n";
    cout << "P1 = " << p1 << "\n";
    cout << "-----------------------------\n";

    string p2 = multiplicar(num1_right, num2_right);

    cout << "-----------------------------\n";
    cout << "P2 = " << p2 << "\n";
    cout << "-----------------------------\n";

    int temp = eqLength(num1_left, num1_right);
    string sum1 = mySum(num1_left, num1_right,0);
    
    temp = eqLength(num2_left, num2_right);
    string sum2 = mySum(num2_left, num2_right,0);
    
    string p3 = multiplicar(sum1,sum2);

    cout << "-----------------------------\n";
    cout << "P3 = " << p3 << "\n";
    cout << "-----------------------------\n";

    string subs = resta(p1,p2,p3);
    cout << "-----------------------------\n";
    cout << "subs: \t"<< subs << "\n";
    cout << "-----------------------------\n";

    p1 = shift(p1,midDer*2);

    subs = shift(subs,midDer);
    
    //else  subs = shift(subs, midDer);
    
    string res = juntar(p1, subs, p2);

    return res;
}



string removeZeros(string str){
    for(int i = 0; i < str.size(); i++){
        if(str[0] == '0'){
            str = str.substr(i, str.size());
        }
        else if (str[1] == '1') break;
    }
    return str;
}

int main(int argc, char **argv)
{
    //bits de los numeros
    int digits = 0;
    string num1;
    string num2;
    cout << multiplicar("101", "010") << "\n";
    //cout << resta("010011","001011","111111") << "\n";
    //leer cantidad de bits de multiplicacion
    while (cin >> digits)
    {

        //get numero 1
        cin >> num1;
        //get numero 2
        cin >> num2;
        //cout << "\nayy lmaao\n" << num1 << "\n" << num2 << "\nayy lmaao\n";
        cout << "res: " << multiplicar(num1, num2);

        cout << "\n";
    }

    cout << "\n";

    return 0;
}
