#include "Graph.hpp"
#include "Node.hpp"
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
#include <queue>

using namespace std;

Graph::Graph(void){}

Graph::~Graph(void) {
  for (auto itr : theGraph) {
    delete itr.second;
  }
}

/* Read in relationships from an inputfile to create a graph */
bool Graph::loadFromFile(const char* in_filename) {
  ifstream infile(in_filename);

  while (infile) {
    string s;

    //no more lines to read break from loop
    if (!getline(infile, s)) break;

    istringstream ss(s);
    vector<string> record;

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
   
     int firstInd = std::stoi(record[0]);
     int secondInd = std::stoi(record[1]);
    
     Node* node = new Node();
    
     Node* node2 = new Node();
    
     //if number is not already key in theGraph, make key value with value shown in text
     if(theGraph.find(firstInd) == theGraph.end()){
         theGraph.insert(make_pair (firstInd, node) ); 
     }
    
     if(theGraph.find(secondInd) == theGraph.end()){
         theGraph.insert(make_pair (secondInd, node2) ); 
     }

     //add number to adjacency vector
     theGraph[firstInd]->adj.push_back(secondInd);
     theGraph[secondInd]->adj.push_back(firstInd);

    }

    if (!infile.eof()) {
        cerr << "Failed to read " << in_filename << "!\n";
        return false;
    }


    infile.close();
    return true;
  
}
 

bool Graph::pathfinder(int from, int to, const char* in_filename){

    ofstream myfile;
    myfile.open("in_filename");

    for( auto v : theGraph){
        v.second->prev = -1;
        v.second->dist = std::numeric_limits<int>::max();
    }    

    stack<int> toPrint;
 
    stack<int> toExplore;

    // starts path search from certain index node
    theGraph[from]->dist = 0;
    toExplore.push(from);
    toPrint.push(from);

    //while stack isn't empty
    while(!toExplore.empty()){
        //index of reference node to find next closest node
        int currInd = toExplore.top();

	//ref to reference node
        Node * curr = theGraph[toExplore.top()];
   
        toExplore.pop();
  
        for(int n : curr->adj){
 
	    // add closest node to stack, initializing dist and index to old reference node
            if(curr->dist + 1 < theGraph[n]->dist){
	        theGraph[n]->dist = curr->dist+1;
		theGraph[n]->prev = currInd;
		toExplore.push(n);

		// once destination is reached, push the path gotten there to a stack
                if(n == to){
		    int num = n;
                    Node * print = theGraph[num];
    		    theGraph[from]->prev = -1;                
		    while(print->prev != -1){
                       toPrint.push(num);
                       print = theGraph[theGraph[num]->prev];
                    }
                    toPrint.push(from);

    	        }
          
	    }
	}
    }

    // prints all but last node 
    while(toPrint.size() != 1 ){
       myfile << toPrint.top() + " ";
       toPrint.pop();
    }
   
    // prints last node 
    myfile << toPrint.top();
    toPrint.pop();

    myfile.close();
    return true;
}
/* Implement social gathering*/
//TODO
void Graph::socialgathering(vector<string>& invitees, const int& k) {

}

