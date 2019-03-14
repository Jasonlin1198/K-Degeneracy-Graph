#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.hpp"

using namespace std;

void usage(char* program_name) {
  cerr << program_name << " called with incorrect arguments." << endl;
  cerr << "Usage: " << program_name
       << " friendship_pairs_file k_value output_file"
       << endl;
  exit(-1);
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    usage(argv[0]);
  }
  char* graph_filename = argv[1];
  char* output_filename = argv[3];
  istringstream ss(argv[2]);

  Graph network;
  
  // loads theGraph with strings from file
  network.loadFromFile(graph_filename);

  ofstream myfile(output_filename);

  // vector to check vistited adjacent nodes
  vector<bool> checked(network.theGraph.size());

  // gets k core number
  int k;
  ss >> k; 

  int start;

  for(unsigned int i = 0; i < network.theGraph.size(); i++){
      if(!network.theGraph[i]){
      }
      else{
	  // gets first non null index in theGraph
          start = i;
	  break;
      }
      // input file was empty, dont print or call anything
 //     return -1; 
  }

  network.socialgathering(start, checked, k);

  int next;
 
  for(unsigned int x = 0 ; x < network.theGraph.size(); x++){
      // if node has enough core
      if(network.theGraph[x]){
          if(network.theGraph[x]->degree >= k){
              //prints first node
	      myfile << x; 
	      next = x; 
              break;
          }
      }
  }

  // prints rest of nodes with new lines 
  for(unsigned int y = next+1; y < network.theGraph.size(); y++){
      if(network.theGraph[y]){
          if(network.theGraph[y]->degree >= k){

              myfile << "\n" << y;
          }
      }
  }
  return 1;
  myfile.close();

}
