#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
	struct stat buf;
	if(lstat(argv[1],&buf)<0){
		perror("stat error");	
	}
	printf("%llu\n",buf.st_ino);

}
