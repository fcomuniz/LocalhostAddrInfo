// #include "shadow_path.h"
#include "funcs.h"
#include <string.h>
#include <cstdlib>
using namespace FishHook;

#include <sys/socket.h>
#include <iostream>
#include <arpa/inet.h>
#include <vector>
#include <sstream>

int mygetnameinfo(const struct sockaddr * addr, socklen_t addrlen,
                       char * host, socklen_t hostlen,
                       char * serv, socklen_t servlen, int flags) {
    std::cout << "getting address info" << std::endl;
    return CallOld<Name_getnameinfo>(addr, addrlen, host, hostlen, serv, servlen, flags);
}
rl_hook(getnameinfo)



std::vector<std::string> splitString(const std::string & str, const char separator) {
    std::stringstream sstream(str);
    std::vector<std::string> output_array = {};
    std::string val;
    
    while (std::getline(sstream, val, separator)) {
        output_array.push_back(val);
    }
    return output_array;
}

bool isinOverride(const char * node, const char * overrides) {
    // split overrides in ;
    const auto & node_s = std::string(node);
    const auto & overrides_s = std::string(overrides);
    auto splittedArray = splitString(overrides_s, ';');
    for (const auto & v : splittedArray) {
        if (node_s.compare(v)==0){
            return true;
        }
    }
    return false;
}

int mygetaddrinfo(const char * node, const char * service, const struct addrinfo * hints, struct addrinfo ** res) {
    auto status = CallOld<Name_getaddrinfo>(node, service, hints, res);
    const char * overrides = std::getenv("LOCALHOST_OVERRIDES");
    if (res != nullptr and overrides != nullptr and isinOverride(node, overrides)) {
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