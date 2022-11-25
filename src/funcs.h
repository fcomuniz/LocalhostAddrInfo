#include <HookFunc.h>
#include <unistd.h>
// #include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
struct __dirstream;
typedef __dirstream DIR;
struct timeval;
struct stat;
struct dirent;

namespace FishHook
{
    def_name(getnameinfo, int, const sockaddr *, socklen_t,
                       char * , socklen_t ,
                       char *, socklen_t , int );
    def_name(getaddrinfo, int, const char *, const char *, const struct addrinfo*, struct addrinfo **);
} // namespace FishHook

#define rl_hook(name) auto_hook(name, my##name)