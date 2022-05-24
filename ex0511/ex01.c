/*
    디렉토리 만들기
    mkdir('파일명',777);
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
/*
    ./ex01 argc =1
    ./ex01 aa argc=2
*/
int main(int argc, char **argv)
{
    char di_name1[20];
    char *di_name2 = "aaa";

    if (argc != 2)
        strcpy(di_name1, "temp");
    else
        strcpy(di_name1, argv[1]);

    printf("di_name1 = %s\n", di_name1);

    if (mkdir(di_name1, 0777) == -1)
    {
        perror("만들기 실패");
        return 1;
    }

    // if (argc == 3)
    // {
    //     int perm = strtol(atgv[2], (char **)NULL, 8);
    //     chmod(argv[2], perm);
    // }

    return 0;
}