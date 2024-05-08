//Ben Levintan 
//Omri Buhbut 
//Or Avital 

/*add IDs before submition*/


#include "std_lib_facilities.h"

void loadCSV(String filename){

}

/* template for the final signiture of the main function

int main(int argc, char* argv[]){

    string input_file = argv[1];
    int port = argv[2];

}


*/


int main(){

    ifstream ofs("db.csv");
    
    // if there is an error in opening the file, display error message in the terminal
    if(!ofs) cout << "ERROR: file did not open" << '\n';


    vector<vector<int>> adjacencyList; // Adjacency list representation of the graph
    unordered_map<int, int> nodeIndexMap; // Map to store node value to index mapping
    
    string line;

    // Parse the file and build the adjacency list
    while (getline(ofs, line)) {        
        istringstream iss(line); // Create a string stream from the line
        int source, destination;
        if (iss >> source >> destination) { // Extract source and destination from the line
            // Check if source and destination nodes already exist in the map
            if (nodeIndexMap.find(source) == nodeIndexMap.end()) {
                // If not, add them to the map and the adjacency list
                nodeIndexMap[source] = adjacencyList.size();
                adjacencyList.push_back({});
            }
            if (nodeIndexMap.find(destination) == nodeIndexMap.end()) {
                nodeIndexMap[destination] = adjacencyList.size();
                adjacencyList.push_back({});
            }
            // Add the edge to the adjacency list
            adjacencyList[nodeIndexMap[source]].push_back(nodeIndexMap[destination]);
            adjacencyList[nodeIndexMap[destination]].push_back(nodeIndexMap[source]); // If the graph is undirected
        }
    }

    // Display the adjacency list for testing
    cout << "Adjacency List:\n";
    for (int i = 0; i < adjacencyList.size(); ++i) {
        cout << "Node " << i << " -> ";
        for (int neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    return 0;
}
