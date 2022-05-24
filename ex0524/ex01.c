#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int fd;
    fd = open("aaa", O_RDWR);
    struct flock lock;

    if (fd < 0)
    {
        printf("파일 열기 실패");
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 100;

    int ret = fcntl(fd, F_SETLKW, &lock); //잠금설정

    if (ret > -1)
    {
        printf("잠금되어있음\n");
        sleep(20); // 20초동안 멈추기
    }

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock); //잠금해제
    printf("잠금해제됨\n");

    close(fd);
}