#include"Graph.hpp"
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

    ofstream myfile(in_filename);

    for( auto v : theGraph){
        v.second->prev = -1;
        v.second->dist = std::numeric_limits<int>::max();
    }    

    stack<int> toPrint;
 
    stack<int> toExplore;

    // starts path search from certain index node
    theGraph[from]->dist = 0;

    for(int x: theGraph[from]->adj){
	if(x == to){
	    toPrint.push(from);
	    toPrint.push(to);
	    goto print; 
	}
    }


    toExplore.push(from);

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
            }
		// once destination is reached, push the path gotten there to a stack
            if(n == to){
	        int num = n;
                Node * print = theGraph[num];
                theGraph[from]->prev = -1;                
	        while(print->prev != -1){
                   toPrint.push(num);
                   print = theGraph[theGraph[num]->prev];
		   num = theGraph[num]->prev;
                }
                toPrint.push(from);
	        break;
    	    }
          
	    
	}
    }
print:
    // prints all but last node 
    while(1){
       myfile << toPrint.top();
       toPrint.pop();

       if(toPrint.empty()){
           break;
       }
       myfile << " ";
    }
    myfile << "\n";
    myfile.close();
    return true;
}
/* Implement social gathering*/
//TODO
void Graph::socialgathering(vector<string>& invitees, const int& k) {

}

vector<int> Graph::socialgathering( const int& k){
    int n, degree, maxDeg, i, start, num; 
    int v, u, w, du, pu, pw;
    

    vector<int> tableVert;
    vector<int> tableDeg;
    vector<tableVert> vert, pos, deg;
    vector<tableDeg> bin;

    // number of vertex
    n = theGraph.size();
    // max degree to be 0 
    md = 0;

    // each vertex
    for( int z = 0 ; z < n ; v++ ){
        d = 0;
	// each neighbor of vertex
	for( int u : theGraph[v]->adj ){
	    // increments and sets degree in vector to return
	    d++;
            deg[v] = d;
	    // sets new max degree
	    if( d > md ){
	        md = d;
            }
	}
    }
    // intialize bin to 0
    // bin contains for each possible degree the position of the first vertex of that degree in array vert
    for( int x = 0; x <= md ; x++){
        bin[x] = 0;
    } 
    // increment the bin's indexes repective to degree of each vertex in theGraph
    for( int y = 0 ; y < n; y++){
	bin[deg[v]]++;
    }
    start = 1;

    // from bin sizes we can determine starting positions of bins in the array vert
    for( int b = 0; b <= md; b++){
        num = bin[b];
	bin[b] = start;
	start++;
	num++;
    }

    // put vertices of graph into the array vert. 
    // for each vertex we know which bin it belongs and what is the starting positions of that bin
    // we can put the current vertex to the proper place, remember it position in the table pos, and increase the starting position of the bin we used.
    for( int a = 0; a < n; a++){
        pos[a] = bin[deg[a]];
	vert[pos[a]] = a;
	bin[deg[a]]++;
    }
    
    for( int temp = md; temp > 0 ; temp--){
        bin[temp] = bin[temp-1];
    }
    bin[0] = 1;

    for( int i = 0; i < n; i++){
        v = vert[i];
	for( int r: theGraph[v]->adj){
	    if(deg[r] > deg[v]){
	        du = deg[r];
		pu = pos[r];
		pw = bin[du];
		w = vert[pw];
	        if(r != w){
		    pos[r] = pw;
		    pos[w] = pu;
		    vert[pu] = w;
		    vert[pw] = r;
		}
		bin[du]++;
		deg[r]--;
	    }
	}
    }

}

