#include<unistd.h>
#include<stdio.h>
int main(){
	int i=0;
	for(i=0;i<3;i++){
		pid_t fpid = fork();
		if(fpid==0){
			printf("son\n");
		}else{
			printf("farther\n");
		}
	}
	return 0;
}
