#include <unistd.h>
#include <stdio.h>

int main()
{

    if (symlink("a1", "alink") < 0)
    {
        perror("에러");
    }
}