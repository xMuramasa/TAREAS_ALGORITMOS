#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

// definicion de tipos
typedef vector<int> adjacencyList;
typedef map<int, adjacencyList> Graph;


/* void dfs
* accion  : hace un dfs en el grafo G, con datos de dfs datos y partiendo 
*           por el nodo u
* prints  : si hay una arista que separe el grafo en 2 componentes conexas
* returns : nada
*/
void dfs(Graph G, map<int, int> &dfs_vis, map<int, int> &dfs_parent, map<int, int> &dfs_low, map<int, int> &dfs_disc, int u, int &flag)
{
    // se declara el tiempo de descubrimiento del nodo
    static int time = 0;
    int j;
    //igual disc con low
    dfs_low[u] = dfs_disc[u] = ++time;

    for (j = 0; j < int(G[u].size()); j++)
    {
        int v = G[u][j];
        if (dfs_vis[v] == -1) // no esta visitado
        {
            //marco como visitado
            dfs_vis[u] = 1;
            dfs_parent[v] = u;

            dfs(G, dfs_vis, dfs_parent, dfs_low, dfs_disc, v, flag);

            if (dfs_low[v] > dfs_disc[u])
            {
                flag = 1;
                cout << u << " " << v << endl;
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
        {
            dfs_low[u] = min(dfs_low[u], dfs_disc[v]);
        }
    }
}

/* void hacerTarea
* accion  : hace un dfs por todos los nodos del grafo
* prints  : si existe la arista que divide el grafo en 2 componentes conexas;
*           si no hay un puente en el grafo
* returns : nada 
*/
void hacerTarea(Graph G)
{

    map<int, int> dfs_vis;
    map<int, int> dfs_parent;
    map<int, int> dfs_low;
    map<int, int> dfs_disc;

    for (auto x : G)
    {
        dfs_vis[x.first] = -1;
        dfs_parent[x.first] = -1;
        dfs_low[x.first] = 0;
        dfs_disc[x.first] = -1;
    }

    // set de flag para ver si existe corte
    int flag = 0;
    for (auto x : G){
        //cout << x.first << endl;
        if(dfs_vis[x.first] == -1){
            dfs(G, dfs_vis, dfs_parent, dfs_low, dfs_disc, x.first, flag);
        } // se hace un dfs nodo por nodo
    }
    if (flag == 0)
        cout << "No existe corte" << endl;
}
/*
dfs_parent[u]: Nodo a través del cuál visitamos el nodo u durante la ejecución de nuestro DFS
dfs_num[u]: Número de iteración en la que el nodo u es recorrido durante un dfs.
dfs_low[u]: El menor valor de dfs_num que puede alcanzar u sin contar su antescesor directo durante un dfs 
(es decir, sincontar el nodo desde el que se llegó a u). Al principio, el valor de dfs_low[u] será dfs_num[u].
*/

// ########### Lmao #############

/* void printGraph
* accion  : muestra un grafo por pantalla usando el struct Graph y un iterador
* prints  : print el grafo en forma de lista de adyacencia
* returns : nada
*/
void printGraph(Graph G)
{

    Graph::iterator itr; // iterador del grafo

    cout << "\nLa forma del grafo es: \n";
    cout << "\tLLAVE:\tVALOR\n";

    for (itr = G.begin(); itr != G.end(); ++itr)
    {
        cout << '\t' << itr->first << ":\t";
        for (auto x : itr->second)
            cout << x << " -> ";
        cout << '\n';
    }
}

int main(int argc, char **argv)
{
    //creacion grafo
    Graph G;
    // creacion lista de adjacencia
    adjacencyList buffer;
    //contador
    int i = 0;
    //cantidad de vertices
    int V = 0;
    // vertice del grafo
    int u = 0;
    //vertice de la lista de adjacencia
    int v = 0;


    // buffer de una lista de adjacencia para I/O;
    // es de la forma: nodo1 nodo2 nodo2 ... nodo_n;
    // ejemplo: 1 2 3 4 5 6
    string buffer2;

    // cout << "Ingrese cantidad de nodos del grafo:\t";
    while (cin >> V)
    {
        for (i = 0; i < V; i++)
        {
            // cout << "\nIngrese vertice: "
            scanf("%d", &u);
            getline(cin, buffer2);
            stringstream is(buffer2);
            // cout << "\nIngrese lista de adjacencia (forma: a b c d): ";

            // parseo de lista de adjacencia
            while (is >> v)
            {
                // insert nodo v en lista de adjacencia del nodo u
                buffer.push_back(v);
            }
            // insert lista de adjacencia del nodo u en grafo
            G[u].swap(buffer);
            buffer.clear(); // para no usar muchas variables se limpia el buffer
        }
        printGraph(G);

        hacerTarea(G);
        G.clear();
        puts("");
        /*
  G es el dicc
  key es un int, elemento es una lista
  G[x]: lista de llave x
  G[x][y]: elemento de la lista y de llave x
  */
    }

    return 0;
}
//  g++ archivo.cpp -o output -Wall
//  valgrind ./hashmaputput -Wall
//  valgrind ./hashmap
//  g++ hashmapp.cpp -o out && valgrind ./out < test.txt