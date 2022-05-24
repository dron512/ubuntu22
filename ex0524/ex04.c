#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void doA()
{
    printf("메인함수 종료\n");
}
void main()
{
    atexit(doA);
    int pid = fork();

    if (pid == 0)
    {
        system("ps");
        sleep(5);
        printf("자식프로세스종료\n");
    }

    int ret = wait(&pid);
    if (ret == 0)
    {
        printf("자식프로세스 종료됨\n");

        exit(0);
    }
}
