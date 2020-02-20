#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addEdge(int v1, int v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->key == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}


// function to add a vertex to the graph
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
    }
}

bool recursivecheck(vertex* n, vertex* p)
{

    n -> visited = true;
    for (int i = 0; i < n -> adj.size(); i++)
    {
        if (!n -> adj[i].v -> visited)
        {
            if (recursivecheck(n -> adj[i].v, n))
                return true;
        }
        else if (n -> adj[i].v != p)
            return true;
    }
    return false;
}

bool Graph::fun()
{
    for (int u = 0; u < vertices.size(); u++)
        if (!vertices[u] -> visited)
            if (recursivecheck(vertices[u], NULL))
                return true;
    return false;
}
