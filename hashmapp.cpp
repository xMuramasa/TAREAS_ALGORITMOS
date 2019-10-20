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
  
  vector<int> dfs_vis(G.size(), -1);
  vector<int> dfs_parent(G.size(), 0);
  vector<int> dfs_low(G.size(), 0);
  vector<int> dfs_disc(G.size(), 0);
  vector<int> puntos_articulacion(G.size(), 0);

  vector<adjacencyList> ret;

  ret.push_back(dfs_vis);               //[0]
  ret.push_back(dfs_parent);            //[1]
  ret.push_back(dfs_low);               //[2]
  ret.push_back(dfs_disc);              //[3]
  ret.push_back(puntos_articulacion);   //[4]

  return ret;

} 
/*
[0] lista de si esta visitado o no?
[1] padre del nodo
[2] indicates earliest visited vertex reachable from subtree rooted with v
[3] cuando el nodo fue visitado
[4] Stores parent vertices in DFS tree
*/

void dfs(Graph G, vector<adjacencyList> datos, int u)
{
  static int time = 0;
  int j;
  cout << "entro dfs" << endl;

  //marco como visitado
  datos[0][u] = 1;
  //igual disc con low
  datos[3][u] = datos[2][u] = ++time;

  /*
  for (i = G.begin(); i != G.end(); ++i)
  {
    //cout  << i->first << endl;
  }*/
  for (j = 0; j < int (G[u].size()); j++)
  {
    int v = G[u][j];
    //cout << v << " " << datos[0][v];
    if (datos[0][v] == -1) // no esta visitado
    {
      cout << "no visitado: "<< v << endl;
      datos[1][v] = u;
      cout << "u: "<< u << endl;
      cout << "v: "<< v << endl;
      dfs(G,datos,v);

      datos[2][u] = min(datos[2][u], datos[2][v]);

      cout << "comp" << endl;
      cout << "low: " << datos[2][v] << endl;
      cout << "disc: " << datos[3][u] << endl;
      if (datos[2][v] > datos[3][u]) {
        cout << "puente" << endl;
        cout << u << " " << v << endl;
      }

    }
    
    else if (v != datos[1][u]){
      cout << "visitado: " <<  u << endl;
      datos[2][u] = min(datos[2][u], datos[3][v]);
    }
  } 
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
    dfs(G, datosDFS, u);
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
  
  /*
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
  */
  adj.push_back(2);
  G[1].swap(adj);
  adj.clear();
  adj.push_back(3);
  G[2].swap(adj);
  adj.clear();
  adj.push_back(4);
  G[3].swap(adj);
  adj.clear();
  adj.push_back(5);
  G[4].swap(adj);
  adj.clear();
  adj.push_back(6);
  G[5].swap(adj);
  adj.clear();
  G[6].swap(adj);
  adj.clear();

  printGraph(G);
  doDFS(G,1);
  /*
  G es el dicc
  key es un int, elemento es una lista
  G[x]: lista de llave x
  G[x][y]: elemento de la lista y de llave x
  */

  return 0;
}
//unordered_map
// g++ archivo.cpp -o output -Wall
//   valgrind ./hashmaputput -Wall
//   valgrind ./hashma