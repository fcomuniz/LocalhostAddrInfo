// #include "shadow_path.h"
// #include "funcs.h"
// #include <unistd.h>
// #include <string.h>
// #include <iostream>
// using namespace FishHook;
// using std::cout;
// using std::endl;

// static gid_t fake_groups[1024] = {0};
// static size_t group_num = 1;

// static int mysetgroups(size_t size, const gid_t *list)
// {
//     assert(size < 1024);
//     memcpy(fake_groups, list, size * sizeof(gid_t));
//     group_num = size;
//     return 0;
// }
// rl_hook(setgroups)


// static int mygetgroups(size_t size, gid_t *list)
// {
//     memcpy(list, fake_groups, std::min(size, group_num) * sizeof(gid_t));
//     return group_num;
// }
// rl_hook(getgroups)

// static gid_t mygid = 0;
// static gid_t myegid = 0;
// static gid_t mysgid = 0;

// static int mysetegid(gid_t v)
// {
//     myegid = v;
//     return 0;
// }
// rl_hook(setegid)


// static int mysetgid(gid_t v)
// {
//     mygid = v;
//     return 0;
// }
// rl_hook(setgid)


// static gid_t mygetgid()
// {
//     const char * gid = getenv("OVRGID");
//     if (gid != nullptr) {
//         // cout << "GID: " << gid << endl;
//         return atoi(gid);
//     }
//     return mygid;
// }
// rl_hook(getgid)

// static gid_t mygetegid()
// {
//     const char * egid = getenv("OVREGID");
//     if (egid != nullptr) {
//         // cout << "EGID: " << egid << endl;
//         return atoi(egid);
//     }
//     return myegid;
// }
// rl_hook(getegid)

// static int mysetresgid(gid_t r, gid_t e, gid_t s)
// {
//     mygid = r;
//     myegid = e;
//     mysgid = s;
//     return 0;
// }
// rl_hook(setresgid)

// static int mygetresgid(gid_t *r, gid_t *e, gid_t *s)
// {
//     *r = mygid;
//     *e = myegid;
//     *s = mysgid;
//     return 0;
// }
// rl_hook(getresgid)

// static uid_t myuid = 0;
// static uid_t myeuid = 0;
// static uid_t mysuid = 0;
// static int mysetresuid(uid_t r, uid_t e, uid_t s)
// {
//     myuid = r;
//     myeuid = e;
//     mysuid = s;
//     return 0;
// }
// rl_hook(setresuid)

// static int mygetresuid(uid_t *r, uid_t *e, uid_t *s)
// {
//     *r = myuid;
//     *e = myeuid;
//     *s = mysuid;
//     return 0;
// }
// rl_hook(getresuid)

// static int myseteuid(uid_t v)
// {
//     myeuid = v;
//     return 0;
// }
// rl_hook(seteuid)

// static uid_t mygeteuid()
// {
//     const char * euid = getenv("OVREUID");
//     if (euid != nullptr) {
//         // cout << "EUID: " << euid << endl;
//         return atoi(euid);
//     }
//     return myeuid;
// }
// rl_hook(geteuid)

// static int mysetuid(uid_t v)
// {
//     myuid = v;
//     return 0;
// }
// rl_hook(setuid)

// static uid_t mygetuid()
// {
//     const char * uid = getenv("OVRUID");
//     if (uid != nullptr) {
//         // cout << "UID: " << uid << endl;
//         return atoi(uid);
//     }
//     return myuid;
// }
// rl_hook(getuid)
