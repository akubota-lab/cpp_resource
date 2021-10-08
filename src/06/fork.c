#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
   int i;

   for (i=0;i<3;i++)
   {
      pid_t pid = fork();
      if (pid==0) // child process
      {
        printf("Child:  This=%d, sleep(2), i=%d, &i = %p, Parent=%d\n", getpid(), i, &i, getppid());
        sleep(2);
      } 
      else // parent process
      {
        printf("Parent: This=%d, sleep(4), i=%d, &i = %p, Parent=%d, Child=%d\n", getpid(), i, &i, getppid(), pid);
        sleep(4);
      }
   }
   printf("Done:   This=%d\n", getpid());
}
