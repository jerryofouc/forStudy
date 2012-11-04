#include"include/apue.h"

#define BUFFSIZE 4

int main(void){
	int n;
	char buf[BUFFSIZE];

	while((n = read(STDIN_FILENO,buf,BUFFSIZE))>0){
		if(write(STDOUT_FILENO,buf,n)!=n){
			printf("eror\n");
		}
		printf("####\n");
	}
	
	if(n<0){
			printf("eror\n");
	}
	exit(0);

}
