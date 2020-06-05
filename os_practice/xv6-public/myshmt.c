#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int pid, parent;
  char *shmem;
  parent = getpid();

  if ((pid = fork()) < 0)
  {
    printf(1, "fork failed!\n");
    exit();
  }
  if (pid == 0)
  {
    sleep(100);
    shmem = getshmem(parent);
    printf(1, "A message from the parent  arddress : %p char : %c\n", shmem, *shmem);
  }
  else
  {
    shmem = getshmem(parent);
    *shmem = 'H';
    printf(1, "parent adrress : %d char : %c\n", shmem, *shmem);
    wait();
    
  }

  exit();
  return 0;
}
