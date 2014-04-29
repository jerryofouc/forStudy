#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	printf("hello world from process ID %d\n",getpid());
	printf("%d",STDOUT_FILENO);
	
}

