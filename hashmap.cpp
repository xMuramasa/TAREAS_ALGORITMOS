#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

// definicion de tipos
typedef vector<int> adjacencyList;
typedef map<int,  adjacencyList> Graph;


vector<adjacencyList> setDFS(Graph G){
  
  vector<int> dfs_num(G.size(), -1);
  vector<int> dfs_parent(G.size(), -1);
  vector<int> dfs_low(G.size(), 0);
  vector<int> puntos_articulacion(G.size(), 0);

  vector<adjacencyList> ret;

  ret.push_back(dfs_num);               //[0]
  ret.push_back(dfs_parent);            //[1]
  ret.push_back(dfs_low);               //[2]
  ret.push_back(puntos_articulacion);   //[3]

  return ret;

}



void dfs(Graph G, vector<adjacencyList> datos, int u, int contadorDfs)
{
  cout << "\ndfs\n";
  datos[0][u] = datos[2][u] = contadorDfs++;
  for (int j = 0; j < int(G[u].size()); j++)
  {
    int v = G[u][j];
    //cout << v << " " << datos[0][v];
    if (datos[0][v] == -1)
    {
      datos[1][v] = u;
      dfs(G,datos,v,contadorDfs);
      if (datos[2][v] >= datos[0][u])
        datos[3][u] = 1;
      cout << datos[2][v] << " " << datos[0][u];
      if (datos[2][v] > datos[0][u])
          cout << "Puente " << u << " " << v << '\n';
      datos[2][u] = min(datos[2][u], datos[2][v]);
    }
    else if (v != datos[3][u])
        datos[2][u] = min(datos[2][u], datos[0][v]);
    } cout << endl;
}



void doDFS(Graph G,int u)
{
    vector<adjacencyList> datosDFS = setDFS(G);
    /*for(auto x: datosDFS){
      for(auto y: x){
        cout << y << " ";
      }
      cout << endl;
    }*/
    dfs(G, datosDFS, u, 0);
    /*for (auto x : datosDFS)
    {
      for (auto y : x)
      {
        cout << y << " ";
      }
      cout << endl;
    }*/
}
/*
dfs_parent[u]: Nodo a través del cuál visitamos el nodo u durante la ejecución de nuestro DFS
dfs_num[u]: Número de iteración en la que el nodo u es recorrido durante un dfs.
dfs_low[u]: El menor valor de dfs_num que puede alcanzar u sin contar su antescesor directo durante un dfs 
(es decir, sincontar el nodo desde el que se llegó a u). Al principio, el valor de dfs_low[u] será dfs_num[u].
*/


// ########### Lmao #############

/* void createNode
* accion  : agrega un nodo a un grafo
* prints  : nada
* returns : nada 
*/
void createNode(Graph G, int nambaWan){
  adjacencyList adjListGet;  
  G.insert(pair<int, adjacencyList>(nambaWan, adjListGet));
}


/* void addEdge
* accion  : agrega una arista a un grafo
* prints  : nada
* returns : nada 
*/
void addEdge(Graph G, int vertex1, int vertex2)
{
  Graph::iterator itr; // iterador del grafo
  int flag = 0;           // flag para verficar si la arista existe
  for (itr = G.begin(); itr != G.end(); ++itr){

    flag = 0;
    for (auto x : itr->second) if (x == vertex1) flag = 1;
    if (!flag){
        itr->second.push_back(vertex2);
        cout << "Edge: " << vertex1 << " - " << vertex2 << "\n";
    }

    flag = 0;
    for (auto x : itr->second) if (x == vertex2) flag = 1;
    
    if (!flag){
        itr->second.push_back(vertex1);
        cout << "Edge: " << vertex2 << " - " << vertex1 << "\n";
    }
  }

}


/* void printGraph
* accion  : muestra un grafo por pantalla usando el struct Graph y un iterador
* prints  : print el grafo en forma de lista de adyacencia
* returns : nada
*/
void printGraph(Graph G){

  Graph::iterator itr; // iterador del grafo

  cout << "\nThe map G is : \n";
  cout << "\tKEY\tELEMENT\n";

  for (itr = G.begin(); itr != G.end(); ++itr)
  {
      cout << '\t' << itr->first << ": ";
      for (auto x : itr->second)
        cout << x << " -> ";
      cout << '\n';
  }
}


int main(int argc, char **argv)
{
   //creacion grafo
  adjacencyList adj;

  Graph G;
  createNode(G, 1);
  createNode(G, 2);
  createNode(G, 3);
  createNode(G, 4);
  createNode(G, 5);
  createNode(G, 6);
  
  adj.push_back(2);
  adj.push_back(5);
  adj.push_back(6);
  G[1].swap(adj);
  adj.clear();
  
  adj.push_back(1);
  adj.push_back(4);
  G[2].swap(adj);
  adj.clear();

  adj.push_back(6);
  adj.push_back(4);
  G[3].swap(adj);
  adj.clear();

  adj.push_back(3);
  adj.push_back(2);
  G[4].swap(adj);
  adj.clear();

  adj.push_back(1);
  G[5].swap(adj);
  adj.clear();

  adj.push_back(1);
  adj.push_back(3);
  G[6].swap(adj);
  adj.clear();

  //printGraph(G);
  doDFS(G,1);
  

  return 0;
}
//unordered_map
// g++ archivo.cpp -o output -Wall
//   valgrind ./hashmaputput -Wall
//   valgrind ./hashma