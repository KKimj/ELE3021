#include "types.h"
#include "defs.h"
//#define VERBOSE

int getadmin(char *password);
int exec2(char *path, char **argv, int stacksize);
int setmemorylimit(int pid, int limit);
char * getshmem(int pid); 

#ifdef VERBOSE
// char * msg_start = "Start";
// char * msg_exit = "Exit";
// char * msg_getadmin = "GetAd";
// char * msg_exec2 = "ExeTw";
// char * msg_setmemorylimit = "SetML";
// char * msg_getshmem = "GetShM";

char * msg_start = "Start!";
char * msg_exit = "Exit!";
char * msg_getadmin = "Getadmin ";
char * msg_exec2 = "extwo ";
char * msg_setmemorylimit = "SetmemLmit";
char * msg_getshmem = "Getshmem";
#endif

int
sys_getadmin(void)
{
    char * passwd = "2018008159";
    return getadmin(passwd);
}

int
sys_exec2(void)
{
    char * path = "pmanager";
    char * argv[] = {"argv0", "argv1"};
    int stacksize = 0;
    return exec2(path, argv, stacksize);
}

int
sys_setmemorylimit(void)
{
    int pid = 0, limit=0;
    if(argint(0,&pid) < 0)
        return -1;

    cprintf("%d\n", pid);
    
    return setmemorylimit(pid, limit);
}

int
sys_getshmem(void)
{
    int pid = 0;
    getshmem(pid);
    return 0;
}


int getadmin(char *password)
{
    #ifdef VERBOSE
    cprintf("%s%s\n", msg_getadmin, msg_start);
    #endif

    if(1)  // login fail
    {
        return -1;
    }

    #ifdef VERBOSE
    cprintf("%s%s\n", msg_getadmin, msg_exit);
    #endif
    return 0; // login success
}


int exec2(char *path, char **argv, int stacksize)
{
    #ifdef VERBOSE
    cprintf("%s%s\n", msg_exec2, msg_start);
    #endif


    if(1) // exec2 fail
    {
        return -1;
    }

    #ifdef VERBOSE
    cprintf("%s%s\n", msg_exec2, msg_exit);
    #endif
    return 0; // exec2 success
}


int setmemorylimit(int pid, int limit)
{
    #ifdef VERBOSE
    // cprintf("%s%s", msg_setmemorylimit, msg_start);
    cprintf("%d", pid);
    // cprintf("%d", limit);
    cprintf("\n");
    #endif

    if(1) // setmemory limit fail
    {
        return -1;
    }

    #ifdef VERBOSE
    cprintf("%s%s\n", msg_setmemorylimit, msg_exit);
    #endif
    return 0; // setmemory limit success
}
char * getshmem(int pid)
{
    char * ret_val = (char *) 0xFFFFFFFF;

    #ifdef VERBOSE
    cprintf("%s%s\n", msg_getshmem, msg_start);
    #endif


    #ifdef VERBOSE
    cprintf("%s%s\n", msg_getshmem, msg_exit);
    #endif
    return ret_val;
}

