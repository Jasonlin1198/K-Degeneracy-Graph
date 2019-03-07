#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Graph.hpp"

using namespace std;

void usage(char* program_name) {
  cerr << program_name << " called with incorrect arguments." << endl;
  cerr << "Usage: " << program_name
       << " friendship_pairs_file test_pairs_file output_file"
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

  //TODO   
 /* You can call the pathfinder function from here */

  // loads record vector with strings from file
  network.loadFromFile(graph_filename);

  // fills unorderedMap with all nodes from input file
  network.fillMap();

  // loads record vector with friendship paths to find
  network.loadFromFile(pairs_filename);

  for(unsigned int i = 0; i < network.record.size(); i++){
        string s = record[i];

        string space = " ";
        // parses first number
        string first = s.substr(0, s.find(space));
        // turns string into int for indexing
        int firstInd = std::stoi(first);

        string second = s.substr(end);
        int secondInd = std::stoi(second);

        pathfinderOwn(theGraph, firstInd, secondInd, output_filename);
 
  }


  
  
  
    
}  
