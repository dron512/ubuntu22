#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    setuid(0);
    setgid(0);
    system("whoami");
    system("/bin/bash");
}