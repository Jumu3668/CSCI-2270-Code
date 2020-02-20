#include "Graph.hpp"
#include <iostream>

using namespace std;

void Graph::addEdge(string v1, string v2, int num)
{

    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] -> name == v1)
        {
            for (int j = 0; j < vertices.size(); j++)
            {
                if (vertices[j] -> name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i] -> adj.push_back(av);
                    av.weight = num;

                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j] -> adj.push_back(av2);
                    av2.weight = num;
                }
            }
        }
    }
}



void Graph::addVertex(string name)
{
    bool found = false;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] -> name == name)
        {
            found = true;
        }
    }
    if (found == false)
    {
        vertex *v = new vertex;
        v -> name = name;
        vertices.push_back(v);
    }

}

void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->key<<" --> ";
        for(int j = 0; j < vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->key << " ";
        }
        cout<<endl;
    }
}

void DFTraversal(vertex *n)
{
    n->visited = true;
    cout << n -> name << " --> ";
    for(unsigned int x = 0; x < n->adj.size(); x++ )
    {
        // TODO
        if (n -> adj[x].v -> visited != true)
        {
            DFTraversal(n -> adj[x].v);
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex)
{
    //Find the vertex pointer given string
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] -> name == sourceVertex)
        {
            DFTraversal(vertices[i]);
        }
    }
    cout << "Done";
}

vertex* Graph::DijkstraAlgorithm(string start, string end)
{
    // mark each vertex at a time as it discovers shortestpath
    vertex* startV;
    vertex* endV;
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] -> name == start)
        {
            startV = vertices[i];
        }
        else if (vertices[i] -> name == end)
        {
            endV = vertices[i];
        }
    }
    //Mark start node as solved and distance = 0
    startV -> visited = true;
    startV -> distance = 0;
    //Store list of solved vertices
    vector<vertex*> solved;
    solved.push_back(startV);
    vertex* parent = NULL;
    //looping to solve
    while (!endV -> visited)
    {
        vertex* solvedV = NULL;
        int minDistance = 100000;
        for (unsigned int i = 0; i < solved.size(); i++)
        {
            vertex* s = solved[i];
            // look at all the adjacent vertices
            for (unsigned int j = 0; j < s -> adj.size(); j++)
            {
                if (!s -> adj[j].v -> visited)
                {
                    int dist = s -> distance + s -> adj[j].weight;
                    if (dist < minDistance)
                    {
                        solvedV = s -> adj[j].v;
                        minDistance = dist;
                        parent = s;
                    }
                }
            }
        }
        solvedV -> distance = minDistance;
        solvedV -> pred = parent;
        solvedV -> visited = true;
        solved.push_back(solvedV);
    }
    return endV;
}

void shortestPathHelper(vertex* n)
{
    if (n == NULL)
    {
        return;
    }
    else
    {
        shortestPathHelper(n -> pred)
        cout << end -> name << " ";
    }
}
//void Graph::shortestpath(string start, string end)

void Graph::shortestpath(string s1, string s2)
{
    vertex* end;
    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] -> name == s2)
        {
            end = vertices[i];
        }
    }
    if (end -> pred != NULL)
    {
        shortestPathHelper(end -> pred);
    }
    cout << end -> name << endl;
}

void Graph::setAllVerticesUnvisited()
{

}
