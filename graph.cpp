#include "graph.h"

using namespace std;

map<int, User*> Graph::getUserBase() {
  return users;
}

// Make sure to delete users map at end, doesn't check for user overlap
// because in reality, it is impossible for two users to be the exact same
void Graph::addUser(int id, int version = 0, int siteTime = 0)
{
  // Create a new user with id and version number;
  if(getUser(id) != NULL) {

  }
  User* temp = new User(id, version, siteTime);
  users.insert(make_pair(id, temp));
}

void Graph::addEdge(int id1, int id2) {

  if(getUser(id1) != NULL && getUser(id2) != NULL) {
    getUser(id1)->getConnections().push_back(getUser(id2));
    getUser(id2)->getConnections().push_back(getUser(id1));
  }

}

// Returns the User with the specified id;
// User&
User* Graph::getUser(int id) {
  map<int, User*>::iterator it;
  it = users.find(id);
  if(it != users.end()) {
    return it->second;
  }
  else return NULL;
}

void Graph::printGraph() {
  // cout << "PRINTING GRAPH" << endl;
  for(map<int, User*>::iterator it = users.begin(); it != users.end(); it++) {
    cout << (*it).first << endl;
  }
}

// modified BFS adds the size of the graph and all users in a graph to a pair
pair<int, vector<User*> > Graph::modifiedBFS(int id)
{
  // Queue of Users to search through
  std::queue<User*> search;
  vector<User*> graphNodes;
  User* temp;
  User* begin = getUser(id);
  search.push(begin);
  int count = 0;

  while(!search.empty())
  {
      temp = search.front();
      cout << "CURRENT MOD IS: " << temp->getId() << " " << endl;
      search.pop();

      if(temp->getVisited() == false)
      {
        // Push back the nodes that I just visited in the graph
        graphNodes.push_back(temp);
        count++;
        temp->setVisited(true);
      }

      // Go through the current user's connections, and add them to the queue
      // if they have not been visited
      if(temp->getConnections().size() != 0) {
        for (list<User*>::iterator it = temp->getConnections().begin(); it != temp->getConnections().end(); ++it)
        {
          if((*it)->getVisited() == false) {
            search.push(*it);
          }
        }
      }
  }

  pair<int, vector<User*> > tempPair = make_pair(count, graphNodes);
  return tempPair;
}

// Total infection BFS algorithm with the id of a specific user
void Graph::totalInfection(int id, int update)
{
    // Queue of Users to search through
    std::queue<User*> search;
    User* temp;
    User* begin = getUser(id);
    search.push(begin);

    while(!search.empty())
    {
        temp = search.front();
        cout << "CURRENT IS: " << temp->getId() << " " << endl;
        search.pop();

        if(temp->getVisited() == false)
        {
          // If the version is not correct, set it to the correct version
          if(temp->getVersion() != update) {
            cout << "Version original is: " << temp->getVersion() << endl;
            temp->setVersion(update);
            cout << "Version set to: " << temp->getVersion() << endl;
          }
          temp->setVisited(true);
        }

        // Go through the current user's connections, and add them to the queue
        // if they have not been visited
        if(temp->getConnections().size() != 0) {
          for (list<User*>::iterator it = temp->getConnections().begin(); it != temp->getConnections().end(); ++it)
          {
            if((*it)->getVisited() == false) {
              search.push(*it);
            }
          }
        }
    }
    cout << endl;
}

// Sorting helper, returns if i is greater than j
bool Graph::sortHelper(int i,int j) {
  return (i > j);
}

// Total infection BFS algorithm with the id of a specific user
void Graph::limitedInfectionWeights(vector<int> rootId, int version, int target)
{
    int traverse = 0;
    int current = 0;

    vector< vector<int > > aboutGraphs;
    vector<int> userID;

    for(int i = 0; i < rootId.size(); i++) {
      // Sort the vector of Users in the current graph
      vector<User*> temp = modifiedBFS(rootId[i]).second;

      // Very brute force way to go about it, I didn't have enough time for this
      // second part and decided to do it this way to conserve time, runtime of n^2
      // for these nested for loops
      for(int j = 0; j < temp.size(); j++) {
        userID.push_back(temp[i]->getId());
      }

      // userID vector now has all the ids, and sorts it greatest to least
      sort(userID.begin(), userID.end(), sortHelper);

      // Push back into the vector of graphs
      aboutGraphs.push_back(userID);
    }

    while(current != target) {
      for(int i = 0; i < aboutGraphs.size(); i++) {
        if(aboutGraphs[i].size() > traverse) {
          User* currentUser = getUser(aboutGraphs[i][traverse]);
          if(currentUser->getVersion() != version) {
            current++;
            currentUser->setVersion(version);
            cout << "Infected " << current << " Users: " << currentUser->getId() << "with site time of " << endl;
          }
        }
      }
      traverse++;
    }
}

int main() {
  Graph test;

  test.addUser(12345);
  test.addUser(13395);
  test.addEdge(12345, 13395);
  test.addUser(56789);
  test.addUser(00000);
  test.addUser(11111);
  test.addEdge(13395, 11111);
  test.addEdge(13395, 00000);

  test.totalInfection(12345, 1);

  cout << "PRINTING GRAPH:" << endl;
  test.printGraph();

  return 0;
}
