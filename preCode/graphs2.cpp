#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

 template<typename T>class gVertex{
    public:
        typename map<T, int>:: iterator vtxMapLoc;
        gVertex<T>(int index){}
        gVertex<T>(typename map<T, int>:: iterator& iter) : vtxMapLoc{ *iter }{}
 };

 template<typename T> class graph{
    private:
        typename map<T, int>::iterator iter;
        map<T, int> vtxMap;
        vector< gVertex<T> > vInfo;
    public:
        void addEdge(graph<T>&, const T&, const T&);
        void show(graph<T>&);
        void showMapElement(graph<T>&);
 };

 template<typename T>
 void graph<T> :: show(graph<T>& g){
     for (g.iter = g.vtxMap.begin(); g.iter != g.vtxMap.end(); g.iter++){
        cout << (*(g.iter)).first << "->" << (*(g.iter)).second;
        puts("");
    }
}

template<typename T>
void graph<T> :: showMapElement(graph<T>&g){
    cout << "LAMAO";
}

template<typename T>
void graph<T> :: addEdge(graph<T>&g, const T& v1, const T& v2){
    pair <map<int, int> :: iterator, bool > ret;
    static int index = 0;
    ret = g.vtxMap.insert(pair<int, int>(v1, index));

    if(ret.second){
        g.vInfo.push_back(index);
        (g.vInfo[index].vtxMapLoc) = vtxMap.find(index);
        index++;
    }

}




int main()
{
    graph<int> G;

    int i = 0;
    //cantidad de vertices
    int V = 0;
    int u = 0;
    int v = 0;

    // creacion del grsssssafo vacio
    cout << "Please enter vertex numbers: ";
    cin >> V;
    string adjList;

    for (i = 0; i < V; i++){
        // vertice i
        cout << "\nEnter vertex: ";

        scanf("%d", &u);
        cout << "Your number: " << u << "\nEnterline: ";
        cin.ignore();
        getline(cin, adjList);

        istringstream is(adjList);
        while (is >> v)
        {
            G.addEdge(G, u, v);
        }
    }
    G.show(G);
   
}
