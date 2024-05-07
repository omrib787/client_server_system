//Ben Levintan 318181831
//Omri Buhbut 209379536


#include "std_lib_facilities.h"

void loadCSV(String filename){

}

int main(){

    ifstream ofs("db.csv");
    
    // if there is an error in opening the file, display error message in the terminal
    if(!ofs) std::cout << "ERROR: file did not open" << '\n';


    vector<int> destinationVector;
    vector<int> sourceVector;
    std::string line;
    while (getline(ofs, line)) {
        std::istringstream iss(line);
        int source, destination;
        if (iss >> source >> destination) {
            sourceVector.push_back(source);
            destinationVector.push_back(destination);
        }
    }

    // Display the contents of the source and destination vectors
    std::cout << "Source Vector:\n";
    int index = 0;
    for (int source : sourceVector) {
        std::cout << index + 1 << ")  " << source << '\t' << destinationVector[index] << '\n';
        index++;
    }
    std::cout << '\n';

    // std::cout << "Destination Vector:\n";
    // for (int destination : destinationVector) {
    //     std::cout << destination << ' ';
    // }
    // std::cout << '\n';
    
    return 0;
}