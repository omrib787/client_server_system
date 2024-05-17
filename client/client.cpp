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

// following zoom recording of Michael from 19-03
int main(int argc, char *argv[]) {
    // template for quick and easy testing //
    // string input_file = argv[1];
    // string output_file = argv[2];
    // string old_string = argv[3];
    // string new_string = argv[4];

    std::string ip = argv[1];
    int port = atoi(argv[2]);
    int source = atoi(argv[3]);
    int destination = atoi(argv[4]);

    cout << "ip adrress: " << ip << "\nport num: " << port << "\nsource: " << source << "\ndestination: " << destination << endl;


    int fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(4444);
    connect(fd, (sockaddr*)&addr, sizeof(addr));

    //work

    close(fd);
}
