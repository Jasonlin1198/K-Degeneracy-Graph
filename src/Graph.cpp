#include "Graph.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <unordered_map>
#include <stack> 

using namespace std;

Graph::Graph(void){}

Graph::~Graph(void) {
  for (auto itr : theGraph) {
    delete itr.second;
  }
}

/* Add a node to the graph representing person with id idNumber and add a connection between two nodes in the graph. */
//TODO
/* Read in relationships from an inputfile to create a graph */

bool Graph::loadFromFile(const char* in_filename) {
  ifstream infile(in_filename);

  while (infile) {
    string s;

    //no more lines to read break from loop
    if (!getline(infile, s)) break;

    istringstream ss(s);
//  vector<string> record;

    while (ss) {
      string s;

      //if there is no friendship and only node break and dont add to vector
      if (!getline(ss, s, ' ')) break;

      //add string to vector
      record.push_back(s);
    }

    // size of vector is not 2, continue
    if (record.size() != 2) {
      continue;
    }

    if (!infile.eof()) {
    cerr << "Failed to read " << in_filename << "!\n";
    return false;
    }

    infile.close();
    return true;
}



    return true;
    //TODO - YOU HAVE THE PAIR OF IDS OF 2 FRIENDS IN 'RECORD'. WHAT DO NEED TO DO NOW? 
  
}
 

bool Graph::fillMap() {
   //vector index has string that looks like "1 2"
   //  | 1 2 | 3 4 | 1 3 | 2 4 |   //
    
   for(unsigned int i = 0; i < record.size(); i++){
        string s = record[i];
        string space = " ";
        // parses first number
        string first = s.substr(0, s.find(space));
        // turns string into int for indexing
        int firstInd = std::stoi(first);
        Node* node;
        node->index = firstInd; 
        node->prev = -1;
 	node->dist = 10000;

        int end = s.find(space) + space.length();
        string second = s.substr(end);
        int secondInd = std::stoi(second); 
        Node* node2;
        node2->index = secondInd; 
        node2->prev = -1;
 	node2->dist = 10000;


        //if number is not already key in theGraph, make key value with value shown in text
        if(theGraph.find(firstInd) == theGraph.end()){
            theGraph.insert({ firstInd, node } ); 
        }
    
        if(theGraph.find(secondInd) == theGraph.end()){
            theGraph.insert({ secondInd, node2 } ); 
        }

        //add number to adjacency vector
        theGraph[firstInd]->adj.push_back(secondInd);
        theGraph[secondInd]->adj.push_back(firstInd);
    }
return true;

}


/* Implement pathfinder*/
//TODO 
//bool Graph::pathfinder(Node* from, Node* to) {

//}

bool Graph::pathfinderOwn(int from, int to, const char* in_filename){

    ofstream myfile;
    myfile.open("in_filename");
    
    stack<int> toExplore;

    // starts path search from certain index node
    theGraph[from]->dist = 0;
    toExplore.push(from);

    //while stack isn't empty
    while(!toExplore.empty()){
        //index of reference node to find next closest node
        int currInd = toExplore.top();

	//ref to reference node
        Node * curr = theGraph[toExplore.top()];
     
        //IS THIS WHERE TO PRINT?//
        //myfile << toExplore.pop() << endl;
      
        for(int n : curr->adj){

	    // final node is reached
            if(n == to){
                return true;
	    }
 
	    // add closest node to stack, initializing dist and index to old reference node
            if(curr->dist + 1 < theGraph[n]->dist){
	        theGraph[n]->dist = curr->dist+1;
		theGraph[n]->prev = currInd;
		toExplore.push(n);

           
	    }
	}
    }
myfile.close();
return true;
}
/* Implement social gathering*/
//TODO
void Graph::socialgathering(vector<string>& invitees, const int& k) {

}

