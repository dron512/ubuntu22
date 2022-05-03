#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

struct myval
{   
    int a;
    int b;
};
void myvalset(struct myval *my){
    my->a = 10;
    my->b = 20;
}
// tuple myval(){
//     return 10,20;
// }
// class AA{ int a; int b;}
// doA(AA aa){ aa.a = 10; aa.b=20 }
int main(int argc, char **argv){
    printf("argc =%d\n",argc);    // 파라메타 개수

    printf("argv[0] = %s\n",argv[0]);
    printf("argv[1] = %s\n",argv[1]);

    struct stat buf;
    lstat(argv[1], &buf);

    // struct myval myv;
    // myvalset(&myv);

    printf("stat %o %x\n",buf.st_mode,buf.st_mode);
    // 10777
    // 111 111 111

    // stmod & 111 111 111
    if( S_ISREG(buf.st_mode))
        printf("-rwxrwxrwx \n");
    if( S_ISDIR(buf.st_mode))
        printf("디렉토리 파일 입니다.\n");
}