#include <iostream>
#include <list>

#ifndef USER_H_
#define USER_H_

class User {

public:
  User();
  User(int id, int version, int siteTime);
  std::list<User*>& getConnections();
  int getId();
  void setVersion(int update);
  int getVersion();
  bool getVisited();
  void setVisited(bool newVisited);

private:
  int _version;
  int _id;
  int _siteTime;
  bool visited;

  // Arraylist of connections to this user
  std::list<User*> connections;
};

#endif /* USER_H_ */
