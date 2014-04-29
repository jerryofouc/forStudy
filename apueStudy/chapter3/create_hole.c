#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
 #define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) 
char buffer1[] = "abcdefj";
char buffer2[] = "ABCDEFJ";
int main(void){
	int fd;
	if((fd = open("file.hole",O_RDWR | O_CREAT | O_TRUNC,FILE_MODE))<0){
		perror("create error");
		exit(1);
	}
	if((write(fd,buffer1,10))!=10){
		perror("error write buffer1");
		exit(1);
	}
	if(lseek(fd,16384,SEEK_SET) == -1){
		perror("seek error");
		exit(1);
	}
	if((write(fd,buffer2,10))!=10){
		perror("error write buffer2");
		exit(1);
	}
	int fd1;
	if((fd1 = open("file.nhole",O_RDWR | O_CREAT | O_TRUNC,FILE_MODE))<0){
		perror("create error");
		exit(1);
	}
	int i =0 ;
	char bb[] = "a";
	for(i=0;i<16404;i++){
		write(fd1,bb,1)	;
	}

}
