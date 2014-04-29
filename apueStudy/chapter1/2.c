#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define BUFFERSIZE 4096

int main(void){
	int n;
	char buf[BUFFERSIZE];

	while((n = read(STDIN_FILENO,buf,BUFFERSIZE)) > 0){
		if(write(STDOUT_FILENO,buf,n) != n){
			perror("error write");
			exit(1);
		}
	}

	if(n < 0){
		perror("error read");
		exit(1);
	}

	return 0;
}