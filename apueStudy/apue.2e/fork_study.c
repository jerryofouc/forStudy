#include<unistd.h>
#include<stdio.h>
int main(){
	pid_t fpid;
	fpid = fork();
	int count = 0;
	fpid = fork();
	if(fpid < 0){
		printf("fork error\n");
	}else if(fpid==0){
		printf("I am a childProcess\n");	
		count++;
	}else{
		printf("in parent\n");
		count++;
	}
	
	printf("result=%d\n",count);
	return 0;
}
