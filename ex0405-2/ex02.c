#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// shift + v drag = auto indent
int main(){
	int fd = open("myfile",O_RDWR|O_CREAT|O_EXCL,0600);
	if (fd ==-1)
		perror("error open file");
	close(fd);
	return 0;
}
