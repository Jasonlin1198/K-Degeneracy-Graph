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
       << " graph_filename pairs_file output_file"
       << endl;
  exit(-1);
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    usage(argv[0]);
  }
  char* graph_filename = argv[1];
  char* pairs_filename = argv[2];
  char* output_filename = argv[3];

  Graph network;

  // loads record vector with strings from file
  network.loadFriendshipFromFile(graph_filename);

  ifstream infile(pairs_filename);

  while (infile) {
    string s;

    //no more lines to read break from loop
    if (!getline(infile, s)) break;

    istringstream ss(s);

    int person;
    ss >> person;
    
    // if nodes to find paths dont exists, move on
    if(network.theGraph.find(person) == network.theGraph.end()){
        continue;
    }

    network.averagefriendship(person, output_filename);

  }      

  infile.close();
  
  
}
