#include<sys/wait.h>
#include<stdio.h>
char *env_list[] = {"USER=unknown","PATH=/tmp",NULL};
int main(void){
	pid_t pid;
	if((pid = fork())<0){
		perror("fork error!");
		exit(1);
	}else if(pid == 0){//in child
		if(execle("/home/sar/bin/echoall","echoall","myarg1","MY_ARG2",(char *)0,env_init)<){
			perror("execle error!");
			exit(1);
		}
	}
	if(waitpid(pid,NULL,0)<0){
		err_sys("wait error");
	}
	if((pid = fork())<0){
		perror("fork error!");
		exit(1);
	}else if(pid == 0){//in child
		if(execlp("echoall","only 1 arg",(char *)0)<){
			perror("execl error!");
			exit(1);
		}
	}
}
