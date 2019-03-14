#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

using namespace std;

class Node{
public:
    vector<int> adj; // the adjacency list
    int dist;  // current best dist from origin to this node 
    int prev;  // how we discovered this vertex
    int index;
    int degree;
    Node(){};

};


#endif

