#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int fd = open("aaa", O_RDWR);

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 100;

    fcntl(fd, F_GETLK, &lock); // 잠금검사
    if (lock.l_type == F_WRLCK)
    {
        printf("파일이 락걸려있음");
    }
    else if (lock.l_type == F_UNLCK)
    {
        printf("파일락이 풀려 있음");
    }
    close(fd);
}