//Ben Levintan 
//Omri Buhbut 
//Or Avital 

/*add IDs before submition*/

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "std_lib_facilities.h"



void loadCSV(String filename){

}

/* template for the final signiture of the main function

int main(int argc, char* argv[]){

    string input_file = argv[1];
    int port = argv[2];

}


*/

list<int> BFSsearch(const vector<vector<int>>& adjacencyList, int source, int destination) {

    

    // If destination is not reachable from source, return an empty list
    return {};
}


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
        // Add the edge to the adjacency list (both directions)
        adjacencyList[nodeIndexMap[source]].push_back(nodeIndexMap[destination]);
        adjacencyList[nodeIndexMap[destination]].push_back(nodeIndexMap[source]); // Add the reverse edge
    }
}

    // Open a text file for writing the adjacency list
    ofstream outputFile("adjacency_list.txt");
    if (!outputFile) {
        cout << "ERROR: Unable to create/open file for writing" << endl;
        return 1;
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


    // Write the adjacency list to the text file
    outputFile << "Adjacency List:\n";
    for (int i = 0; i < adjacencyList.size(); ++i) {
        outputFile << "Node " << i << " -> ";
        for (int neighbor : adjacencyList[i]) {
            outputFile << neighbor << " ";
        }
        outputFile << endl;
    }

    // Close the text file
    outputFile.close();
    /*creating a socket*/

    

    int server_fd = socket(AF_INET, SOCK_STREAM , 0);

    if (server_fd < 0) ("ERROR opening socket");

    sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(4444);
    bind(server_fd, (sockaddr*)&addr, sizeof(addr));

    

    close(server_fd);
    
    return 0;
}
