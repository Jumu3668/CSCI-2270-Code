#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>

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
    int currSize;

    for (unsigned int i = 0; i < vertices.size(); i++)
    {
        currSize = vertices[i] -> adj.size();
        //print out all adjacent edges
        cout << vertices[i] -> name << " --> " ;
        for (int j = 0; j < currSize; j++)
        {
            cout << vertices[i] -> adj[j].v -> name << " ";
        }
        cout << endl;
    }
}


void Graph::breadthFirstTraverse(string sourceVertex)
{
    vertex* start = NULL;
    int verticesSize = vertices.size();
    for (int i = 0; i < verticesSize; i++)
    {
        if (vertices[i] -> name == sourceVertex)
        {
            start = vertices[i];
        }
    }

    cout << "Starting vertex (root): " << sourceVertex << "-> ";

    start -> visited = true;
    start -> distance = 0;
    queue<vertex*> q;
    q.push(start);

    while (!q.empty())
    {
        vertex* current = q.front();
        q.pop();

        int currSize = current -> adj.size();
        for (int i = 0; i < currSize; i++)
        {
            if (!(current -> adj[i].v) -> visited)
            {
                (current -> adj[i].v) -> distance = current -> distance + 1;
                (current -> adj[i].v) -> visited = true;
                q.push(current -> adj[i].v);
                cout << (current -> adj[i].v) -> name << "(" << (current -> adj[i].v) -> distance << ") " ;
            }
        }
        current -> visited = true;
    }
}

void DFTraversal(vertex *n)
{
    n->visited = true;
    for(unsigned int x = 0; x < n->adj.size(); x++ )
    {
        // TODO
        if (n -> adj[x].v -> visited != true)
        {
            DFTraversal(n -> adj[x].v);
        }
    }
}

int Graph::getConnectedComponents()
{
    //Provide the number of connected components in the graph
    int connComp = 0;
    int vertSize = vertices.size();
    for (int i = 0; i < vertSize; i++)
    {
        if (vertices[i] -> visited == false)
        {
            DFTraversal(vertices[i]);
            connComp++;
        }
    }
    return connComp;
}

void DFSearch(int index, vector<vertex*> vertices, string color)
{
    if (color == "red")
        color = "blue";
    else if (color == "blue")
        color = "red";

    vertices[index] -> visited = true;
    vertices[index] -> color = color;

    int adjSize = vertices[index] -> adj.size();
    for (int i = 0; i < adjSize; i++)
    {
        if (vertices[index] -> adj[i].v -> visited == false)
        {
            vector<vertex*> temp;
            for (int j = 0; j < adjSize; j++)
            {
                temp.push_back(vertices[index] -> adj[j].v);
            }
            DFSearch(i, temp, color);
        }
    }
}

bool Graph::checkBipartite()
{
    int vertSize = vertices.size();
    for (int i = 0; i < vertSize; i++)
    {
        if (vertices[i] -> visited == false)
        {
            DFSearch(i, vertices, "red");
        }
    }
    for (int i = 0; i < vertSize; i++)
    {
        int vertAdjSize = vertices[i] -> adj.size();
        for (int j = 0; j < vertAdjSize; j++)
        {
            if (vertices[i] -> color == vertices[i] -> adj[j].v -> color)
            {
                return false;
            }
        }
    }
    return true;
}
