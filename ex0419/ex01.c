#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd1, fd2;

    fd1 = creat("myfile2", 0600);

    char *str = "Hello Linux";
    write(fd1, str, strlen(str));

    fd2 = dup(fd1);
    write(fd2, str, strlen(str));

    dup2(fd1, 1);
    write(fd1, str, strlen(str));

    printf("\n\n hello stdout\n");

    return 1;
}