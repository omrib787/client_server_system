//Ben Levintan 
//Omri Buhbut 
//Or Avital 


#include "std_lib_facilities.h"

void loadCSV(String filename){

}

int main(){

    ifstream ofs("db.csv");
    
    // if there is an error in opening the file, display error message in the terminal
    if(!ofs) std::cout << "ERROR: file did not open" << '\n';


    vector<int> destinationVector;
    vector<int> sourceVector;

    string line;

    // go throw ofs, add the data from the file to the subsequent vector // 
    while (getline(ofs, line)) {        
        istringstream iss(line);        //passing the string we want to parse as argument
        int source, destination;
        if (iss >> source >> destination) {        //extract two integers from the iss stream
            sourceVector.push_back(source);
            destinationVector.push_back(destination);
        }
    }

    // Display the contents of the source and destination vectors for testing
    cout << "Source Vector:\n";
    int index = 0;
    for (int source : sourceVector) {
        cout << index + 1 << ")  " << source << '\t' << destinationVector[index] << '\n';
        index++;
    }
    cout << '\n';

    
    return 0;
}
