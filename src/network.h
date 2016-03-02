#include <sys/socket.h>
#include <netinet/ip.h>
#define PORT 6606

int initialize(long ip){
    int sockid = socket(PF_UNIX, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in net_data;
    //net_data.
    //bind()
}