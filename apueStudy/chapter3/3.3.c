#include<unistd.h>
#include<stdio.h>
#define BUFFERSIZE 4096

int main(void){
	int n;
	char buff[BUFFERSIZE];

	while((n = read(STDIN_FILENO,buff,BUFFERSIZE))>0){
		if(write(STDOUT_FILENO,buff,n) != n){
			perror("write error");
		}

		if(n < 0){
			perror("read error");
		}
	}
}
