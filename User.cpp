#include "User.h"

using namespace std;

User::User() {
  _id = 0;
  _version = 0;
  visited = false;
  _siteTime = 0;
}

User::User(int id, int version, int siteTime = 0) {
  _id = id;
  _version = version;
  visited = false;
  _siteTime = siteTime;
}

list<User*>& User::getConnections() {
  return connections;
}

void User::setVersion(int update) {
  _version = update;
}

int User::getId() {
  return _id;
}

int User::getVersion() {
  return _version;
}

bool User::getVisited() {
  return visited;
}

void User::setVisited(bool newVisited) {
  visited = newVisited;
}
