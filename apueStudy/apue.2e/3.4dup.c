#include"include/apue.h"
#include<fcntl.h>
int main(){
	int fd = open("3.4.c",O_RDONLY);	
	if(fd<0){
		printf("eror open \n");
		exit(1);
	}
	printf("fd:%d\n",fd);
	int dufd = dup(fd);
	printf("dufd:%d\n",dufd);
	int val = fcntl(fd,F_GETFL,0);
	printf("val:%d\n",val);
//	val &= ~O_RDWR;
	val |= O_APPEND;
	printf("val:%d\n",val&O_ACCMODE);
	if(fcntl(dufd,F_SETFL,val)<0){
		printf("error set\n");
		exit(1);
	};
	val = fcntl(fd,F_GETFL,0);
	printf("val:%d\n",val);
	
	
}
