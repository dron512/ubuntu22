#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MYEMPTY while( getchar()=='\n' );
typedef struct
{
    char name[24];
    int id;
    int score;
} STUDENT;

// 입력 버퍼 지우기
void stdempty(){
    while( getchar() !='\n' ){}
}

int main()
{
    int fd, fd1;
    fd = open("studentdb", O_RDWR);

    if (fd == -1)
    {
        printf("file open fail");
    }

    // fd1 = open("studentdb", O_RDONLY);
    // printf("fd = %d", fd);
    // printf("fd1 = %d", fd1);
    char c;
    STUDENT student;
    // STUDENT *student1 = &student;
    do
    {
        printf("검색하실 학번을 입력하세요");
        scanf("%d", &student.id);
        getchar();
        if (student.id != 0)
        {
            lseek(fd, sizeof(student), SEEK_SET);
            read(fd, &student, sizeof(student));

            printf("학번 = %d, 이름= %s, 점수= %d", student.id, student.name, student.score);

            printf("수정하실 점수 입력?");
            scanf("%d",&student.score);
            stdempty();
            if(student.score !=0){
                lseek(fd,-(sizeof(student)),SEEK_CUR);
                write(fd,&student,sizeof(student));
            }
            
        }
        printf("계속하시겠습니까? (Y/N) ");
        scanf("%c", &c);
        printf("c = %c", c);

        // fflush(stdin);
        // getchar(); // 버퍼에 있는 엔터키 비우기...
    } while (c == 'Y');
    close(fd);
    return 0;
}