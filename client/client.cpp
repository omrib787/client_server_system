#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "std_lib_facilities.h"

using namespace std;

void printInput(const std::string& ip, int port, int source, int destination) {
    cout << "IP address: " << ip << "\nPort number: " << port 
         << "\nSource: " << source << "\nDestination: " << destination << endl;
}

// following zoom recording of Michael from 19-03
int main(int argc, char *argv[]) {
    std::string ip = argv[1];
    int port = atoi(argv[2]);
    int source = atoi(argv[3]);
    int destination = atoi(argv[4]);

//    printInput(ip, port, source, destination);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);
    connect(fd, (sockaddr*)&addr, sizeof(addr));


    // Send source and destination to the server
    string payload = to_string(source) + "," + to_string(destination);
    send(fd, payload.c_str(), payload.length(), 0);

    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(fd, buffer, sizeof(buffer), 0);

    string result(buffer, bytes_received);
    cout << result << endl;


    close(fd);
    return 0;
}

