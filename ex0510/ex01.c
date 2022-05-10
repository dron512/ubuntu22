#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aa
{
    char name[512];
};
void printstat(char *pathname, char *file, struct stat *st);

void setaa(struct aa *pa)
{
    printf("pa = %d\n", pa);
    strcpy((*pa).name, "안녕하세요 이름입니다");
}
void printaa(struct aa *pa)
{
    printf("pa->name = %s\n", pa->name);
}
int main(int argc, char **argv)
{
    struct aa maina;
    printf("&maina %d\n", &maina);
    setaa(&maina);
    printaa(&maina);

    // 디렉토리,파일 엔트
    DIR *dp;
    // 디렉토리,파일 담는곳
    struct dirent *d;
    char path[BUFSIZ];
    struct stat st;

    printf("BUFSIZ = %d\n", BUFSIZ);

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
        sprintf(path, "%s/%s\n", directoryname, d->d_name);
        lstat(path, &st);
        // printstat(path, d->d_name, &st);
        // printf("%5d", st.st_blocks);

        // printf("%s\n", d->d_name);
        printf("path = %s", path);
    }

    return 0;
}