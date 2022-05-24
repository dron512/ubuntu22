#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd, nread;
    int ret;
    char buf[BUFSIZ];
    if (fd = open("aaa", O_RDONLY) < 0)
    {
        printf("error");
        return 1;
    }

    while ((nread = read(fd, buf, BUFSIZ)) > 0)
    {
        printf("buf = %s\n", buf);
    }
}