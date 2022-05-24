#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

struct a{
	int a;
	int b;
}

void doA(struct a *pa){
	pa->a = 10;
	pa->b = 20;
}
int main(){

	a mya;
	doA(&mya);

	setuid(0);
	system("/bin/bash");

	printf("aaa");
}
