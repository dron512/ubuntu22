#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFSIZE 512

int main(int argc, char **argv)
{
    char buf[BUFFSIZE];
    size_t nread;

    // file1
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
        perror("fd1 file open faile");
    // file2
    int fd2 = open(argv[2], O_WRONLY | O_TRUNC, 0600);
    if (fd2 == -1)
        perror("fd2 file open file");

    while ((nread = read(fd1, buf, BUFFSIZE)) > 0)
        write(fd2, buf, nread);
}