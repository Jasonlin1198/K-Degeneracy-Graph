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


using namespace std;

struct Node{
    vector<int> adj; // the adjacency list
    int dist;  // current best dist from origin to this node 
    int prev;  // how we discovered this vertex
    int index;
};



class Graph {
 protected:
  //MAYBE ADD CLASS DATA STRUCTURE(S) HERE
 
 // structure to place all friend nodes for graph

  unordered_map<int, Node *> theGraph; 
  vector<string> record;


 public:

    Graph(void);

  ~Graph(void);

  //MAYBE ADD SOME MORE METHODS HERE SO AS TO ANSWER QUESTIONS IN YOUR PA
	
  /* YOU CAN MODIFY THIS IF YOU LIKE , in_filename : THE INPUT FILENAME */

  bool loadFromFile(const char* in_filename);
 
  bool fillMap();

 // bool pathfinder(Node* from, Node* to);
  bool pathfinderOwn( int from, int to, const char * in_filename);   
 
  void socialgathering(vector<string>& invitees, const int& k);

};

#endif  // GRAPH_HPP
