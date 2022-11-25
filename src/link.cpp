// #include "shadow_path.h"
#include "funcs.h"
#include <string.h>
using namespace FishHook;

#include <sys/socket.h>
#include <iostream>
#include <arpa/inet.h>


int mygetnameinfo(const struct sockaddr * addr, socklen_t addrlen,
                       char * host, socklen_t hostlen,
                       char * serv, socklen_t servlen, int flags) {
    std::cout << "getting address info" << std::endl;
    return CallOld<Name_getnameinfo>(addr, addrlen, host, hostlen, serv, servlen, flags);
}
rl_hook(getnameinfo)


int mygetaddrinfo(const char * node, const char * service, const struct addrinfo * hints, struct addrinfo ** res) {
    auto status = CallOld<Name_getaddrinfo>(node, service, hints, res);
    if (res != nullptr && !strcmp(node, "trends.google.com")) {
        struct addrinfo * resref = *res;
        void * ptr;
        switch (resref->ai_family)
        {
        case AF_INET:
          ptr = &((struct sockaddr_in *) resref->ai_addr)->sin_addr;
          break;
        case AF_INET6:
          ptr = &((struct sockaddr_in6 *) resref->ai_addr)->sin6_addr;
          break;
        }
        char addrstr[100];
        inet_pton(AF_INET, "127.0.0.1", ptr);
    }
    return status;
}
rl_hook(getaddrinfo)