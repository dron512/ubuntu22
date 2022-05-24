#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	if(fork()==0){
		system("ls -al");
		return 0;
	}
	else{
		system("ps");
	}
	return 0;
}
