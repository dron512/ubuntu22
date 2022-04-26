#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct
{
    char name[24];
    int id;
    int score;
} STUDENT;

int main()
{
    int fd1;
    fd1 = open("studentdb", O_WRONLY | O_CREAT | O_TRUNC, 0640);
    if (fd1 == -1)
    {
        printf("fd1 create 실패");
        return -1;
    }
    printf("학번 이름 점수 입력하세요");
    STUDENT student;

    while (scanf("%d %s %d", &student.id, student.name, &student.score) == 3)
    { // 3개 입력 했으면...
        lseek(fd1, student.id * sizeof(student), SEEK_SET);
        write(fd1, &student, sizeof(student));
    }
    close(fd1);
}