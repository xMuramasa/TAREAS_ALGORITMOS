#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>

//añadir vertices a la lista de adjacencia del grafo
void addEdge(vector<int> adjMatrix[], int u, int v){
    adjMatrix[u].push_back(v);
    adjMatrix[v].push_back(u);
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
    // Declaring iterator
    std::string::iterator it;

    // creacion del grafo vacio
    cout << "Please enter vertex numbers: ";

    cin >> V;
    cin.ignore();
    
    vector<int> adjMatrix[V];

    for (int i = 0; i < V; i++){
        // vertice i
        cout << "Enter vertex: ";
        cin >> u;
        cin.ignore();
        cout << "Your number: " << u << "\nEnterline: ";
        getline(cin, adjList);
        cin.ignore();
        puts("");
        
    }
    
    
    V = 6;
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 5);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 2, 5);

    printGraph(adjMatrix, V);

    return 0;
}
