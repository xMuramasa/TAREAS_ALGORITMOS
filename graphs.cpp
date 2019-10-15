#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>
#include <algorithm>

//añadir vertices a la lista de adjacencia del grafo
void addEdge(vector<int> adjMatrix[], int u, int v, int V){
    int flag = 0;
    for (auto x : adjMatrix[v]) if (x == u) flag = 1;
    
    if (!flag){
        adjMatrix[u].push_back(v);
        cout << "Edge: " << u << " - " << v << "\n";
    }
    flag = 0;
    for (auto x : adjMatrix[u]) if (x == v) flag = 1;

    if (!flag){
        adjMatrix[u].push_back(v);
        cout << "Edge: " << u << " - " << v << "\n";
    }
    puts("");
}

//print lista de adjacencia del grafo
void printGraph(vector<int> adjMatrix[], int V){
    for (int i = 0; i < V; i++){
        cout << "Adjacency list of vertex " << i << ":\n Head" ;
        for (auto x: adjMatrix[i]) cout << "->" << x;
        puts("");
    }
}

int main(){
    //cantidad de vertices
    int V = 0;
    int u;
    int v;
    //line con lista de adjacencia
    string adjList;

    // creacion del grafo vacio
    cout << "Please enter vertex numbers: ";
    cin >> V;    
    vector<int> adjMatrix[V];

    for (int i = 0; i < V; i++){
        // vertice i
        cout << "\nEnter vertex: ";
        scanf("%d", &u);
        cout << "Your number: " << u << "\nEnterline: ";
        cin.ignore(); 
        getline(cin, adjList);


        istringstream is(adjList);
        while(is >> v){
            addEdge(adjMatrix, u, v, V);
        }
    }
    
    printGraph(adjMatrix, V);

    return 0;
}
