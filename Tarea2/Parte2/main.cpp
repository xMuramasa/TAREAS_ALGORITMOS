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


int main(){
	string tree;
	string Preorder;
	int nodeQuantity;
	int Q;
	while (cin >> nodeQuantity)
	{
		cin >> tree;
		cin.ignore(256, '\n');
		getline(cin, Preorder);
		cin >> Q;

		cout << "Nodes: " << nodeQuantity << "\nTree: " << tree << "\nPreorder: ";
		cout << Preorder << "\nQ: " << Q << "\n"; 
		break;
	}
	return 0;

}