#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <unordered_map>
#include <vector>

#include <algorithm>
#include <fstream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <utility>

#include <stack> 
#include <queue>

#include "Node.hpp"

using namespace std;

class Graph {
 protected:


 public:
  
  unordered_map<int, Node *> theGraph; 
  
  Graph(void);

  ~Graph(void);

  //MAYBE ADD SOME MORE METHODS HERE SO AS TO ANSWER QUESTIONS IN YOUR PA
	
  /* YOU CAN MODIFY THIS IF YOU LIKE , in_filename : THE INPUT FILENAME */

  bool loadFromFile(const char* in_filename);
 
  bool loadFriendshipFromFile(const char* in_filename);
 
  // bool pathfinder(Node* from, Node* to);
  bool pathfinder( int from, int to, const char * in_filename);   
 
  bool socialgathering(int i, vector<bool>&checked, const int& k);

  double averagefriendship( int person, const char * in_filename);

};

#endif  // GRAPH_HPP
