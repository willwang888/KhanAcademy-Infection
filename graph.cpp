
#include "graph.h"

Graph::Graph(int V)
{
    this->num_of_vertices = V;
    Adj = new std::vector<int>[V];
}

void Graph::addEdge(int from, int to)
{
    Adj[from].push_back(to);
}

void Graph::totalInfection(int Start)
{
    bool* visited = new bool[this->num_of_vertices]();
    std::queue<int> queue;
    std::queue.push(Start);
    std::vector<int>::iterator i;
    std::cout << "BFS: ";
    while(!queue.empty())
    {
        Start = queue.front();
        cout << Start << " ";
        visited[Start] = true;
        queue.pop();
        for (i = Adj[Start].begin(); i != Adj[Start].end(); i++)
        {
            if (!visited[*i])
                queue.push(*i);
        }
    }
    cout << endl;
}
