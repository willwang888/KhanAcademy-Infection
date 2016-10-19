#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Graph
{
private:
    int num_of_vertices;
    std::vector<int> *Adj;
public:
    Graph(int V);
    void addEdge(int from, int to);
    void totalInfection(int Start);
};
