#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
        printf("Hello world\n");

        for (;;) {
                int pid = fork();
                int pid2;
                int ret;

                if (pid < 0) {
                        printf("[init] fork() failed [errno=%d]\n", errno);
                        sleep(10);
                        continue;
                }

                if (pid == 0) {
                        /* Child. */
                        ret = execl("/bin/sh", "sh", NULL);
                        printf("[init] execl() returned %d [errno=%d]\n",
                               ret, errno);
                        exit(0);
                }

                /* Parent. */
                pid2 = waitpid(pid, NULL, 0);
                printf("[init] Child %d terminated\n", pid2);
        }
        sleep(999999999);
        return 0;
}

