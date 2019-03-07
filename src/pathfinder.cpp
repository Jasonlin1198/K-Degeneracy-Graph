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
  // wrong number of arguments   
  if (argc != 4) {
    usage(argv[0]);
  }
  

  char* graph_filename = argv[1];
  char* pairs_filename = argv[2];
  char* output_filename = argv[3];

  Graph network;

  // loads record vector with strings from file
  network.loadFromFile(graph_filename);

  // fills unorderedMap with all nodes from input file
  network.fillMap();

  ifstream infile(pairs_filename);

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
   
    int from = std::stoi(record[0]);
    int to = std::stoi(record[1]);






 for(unsigned int i = 0; i < network.record.size(); i++){
        string s = network.record[i];

        string space = " ";
        // parses first number
        string first = s.substr(0, s.find(space));
        // turns string into int for indexing
        int firstInd = std::stoi(first);

        auto end = s.find(space) + space.length();
        string second = s.substr(end);
        int secondInd = std::stoi(second);

        network.pathfinderOwn( firstInd, secondInd, output_filename);
 
  }


  
  
  
    
}  
