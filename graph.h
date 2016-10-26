#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "User.h"
#include <map>

class Graph
{
private:
    // Map stores the user id and the User wth that id
    std::map<int, User*> users;
public:
    std::map<int, User*> getUserBase();
    void addUser(int id, int version, int siteTime);
    void addEdge(int v, int w);
    User* getUser(int id);
    void printGraph();
    static bool sortHelper(int i,int j);
    std::pair<int, std::vector<User*> > modifiedBFS(int id);
    void limitedInfectionWeights(std::vector<int> rootId, int version, int target);
    void totalInfection(int id, int update);
    void DFS();
};
