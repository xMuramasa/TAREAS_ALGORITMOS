#include <map>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graphw;

/* vector<adjacencyList> setDFS(Graph G)
* accion  : prepara los datos de un grafo para el dfs
* prints  : nada
* returns : vector con datos inicializados para el dfs
*/
vector<vector<int>> setDFS(graphw G)
{

    vector<int> dfs_vis(G.size() + 1, -1);
    vector<int> dfs_parent(G.size() + 1, -1);
    vector<int> dfs_low(G.size() + 1, 0);
    vector<int> dfs_disc(G.size() + 1, -1);

    vector<vector<int>> ret;

    ret.push_back(dfs_vis);    //[0]
    ret.push_back(dfs_parent); //[1]
    ret.push_back(dfs_low);    //[2]
    ret.push_back(dfs_disc);   //[3]

    /*
  [0] lista de si esta visitado o no?
  [1] padre del nodo
  [2] indicates earliest visited vertex reachable from subtree rooted with v
  [3] cuando el nodo fue visitado
  */

    return ret;
}

void dfs(graphw G, vector<vector<int>> &datos, int u, int &flag)
{
    // se declara el tiempo de descubrimiento del nodo
    static int time = 0;
    int j;
    //marco como visitado
    datos[0][u] = 1;
    //igual disc con low
    datos[3][u] = datos[2][u] = ++time;

    for (j = 0; j < int(G[u].size()); j++)
    {
        int v = G[u][j];
        if (datos[0][v] == -1) // no esta visitado
        {

            datos[1][v] = u;

            dfs(G, datos, v, flag);

            if (datos[2][v] > datos[3][u])
            {
                flag = 1;
                cout << u << " " << v << endl;
            }

            datos[2][u] = min(datos[2][u], datos[2][v]);
        }
        else if (v != datos[1][u])
        {
            datos[2][u] = min(datos[2][u], datos[3][v]);
        }
    }
}

/* void hacerTarea
* accion  : hace un dfs por todos los nodos del grafo
* prints  : si existe la arista que divide el grafo en 2 componentes conexas;
*           si no hay un puente en el grafo
* returns : nada 
*/
void hacerTarea(graphw G)
{
    // set de flag para ver si existe corte
    int flag = 0;
    // datos dfs
    vector<vector<int>> datosDFS = setDFS(G);
    //if(G.size() <= 1)
    //cout << "No existe corte" << endl;
    ///else{
    for (auto x : G)
        dfs(G, datosDFS, x.first, flag); // se hace un dfs nodo por nodo

    if (flag == 0)
        cout << "No existe corte" << endl;
}


    int n, v, w;
    cin >> n;
    graphw gw(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v >> w;
        gw[i].push_back(make_pair(v, w));
        //gw[v].push_back( make_pair(i, w) );
    }
    int main(int argc, char **argv)
    {
        int V = 0;
        
        while (cin >> V)
        {
            for (i = 0; i < V; i++)
            {
                int n, v, w;
                cin >> n;
                graphw gw(n);
                for (int i = 0; i < n; i++)
                {
                    cin >> v >> w;
                    gw[i].push_back(make_pair(v, w));
                    //gw[v].push_back( make_pair(i, w) );
                }
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
    hacerTarea(gw);
    return 0;
}