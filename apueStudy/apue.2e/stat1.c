#include"include/apue.h"
int main(){
	struct stat s;
	if(stat("3.4.c",&s)<0){
		printf("error\n");
	}
	printf("mode:%d\n",s.st_mode);
}
