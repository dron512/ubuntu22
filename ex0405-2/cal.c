#include <stdio.h>
#include "add.h"

void main(){
	int a,b;
	printf("insert a \n");
	scanf("%d",&a);

	printf("insert b \n");
	scanf("%d",&b);

	add(a,b);
}
