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
    std::string ip = argv[1];
    int port = atoi(argv[2]);
    int source = atoi(argv[3]);
    int destination = atoi(argv[4]);

    cout << "ip adrress: " << ip << "\nport num: " << port << "\nsource: " << source << "\ndestination: " << destination << endl;




    int fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);
    bind(fd, (sockaddr*)&addr, sizeof(addr));
    listen(fd, 5);

    for(;;){
        int fd2 = accept(fd, NULL, NULL);
        if (fork() == 0){
            for ( int i = 0 ; i < 4 ; ++i){
                string s = to_string(i) + "\n";
                write(fd2, &s[0], s.size());
                // write(fd2, &source, sizeof(source));
                // write(fd2, &destination, sizeof(destination));
                sleep(1);
            }
            close(fd2);
            exit(0);
        }
    }
    close(fd);
}
