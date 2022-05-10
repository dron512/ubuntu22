#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    // 디렉토리,파일 엔트
    DIR *dp;

    // 디렉토리,파일 담는곳
    struct dirent *d;

    char directoryname[512];
    if (argc == 1)
    {
        strcpy(directoryname, ".");
    }
    else
    {
        strcpy(directoryname, argv[1]);
    }
    printf("directoryname =  %s\n", directoryname);

    dp = opendir(directoryname);
    if (dp == NULL)
    {
        perror("dp is null");
        exit(0);
    }
    while ((d = readdir(dp)) != NULL)
    {
        printf("%s\n", d->d_name);
    }

    return 0;
}