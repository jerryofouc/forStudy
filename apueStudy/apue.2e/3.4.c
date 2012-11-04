#include"include/apue.h"
#include <fcntl.h>
int main(int argc,char* argv[]){
	int val;
	printf("O_ACCMODE:%d,O_RDONLY:%d,O_WRONLY:%d,O_RDWR:%d\n",O_ACCMODE,O_RDONLY,O_WRONLY,O_RDWR);
	if(argc!=2){
		err_quit("usage:a.out<descp>");
	}
	if((val = fcntl(atoi(argv[1]),F_GETFL,0))<0){
		err_sys("fct1 error for fd %d",atoi(argv[1]));
	}
	switch(val & O_ACCMODE){
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read write");
			break;
		default:
			err_dump("unknown access mode");
	}
	if(val&O_APPEND){
		printf(",append");
	}
	if(val&O_NONBLOCK){
		printf(",nonblock");
	}
	putchar('\n');
	exit(0);

}
