#include"include/apue.h"
#include<sys/wait.h>
char *env_init[] = {"USER=unknown","PATH=/tmp",NULL};
int main(){
	pid_t pid;
	if((pid=fork())<0){
		err_sys("fork error");
	}else if(pid==0){
		if(execle("/home/zhangxiaojie/git_hub/forStudy/apueStudy/apue.2e/echoall.o","echoall","myarg1",
		"MY ARG2",(char*)0,env_init)<0){
			err_sys("fork error");
		}
	}
	
	if(waitpid(pid,NULL,0)<0){
			err_sys("fork error");
	}

	if((pid=fork())<0){
		err_sys("fork error");
	}else if(pid==0){
		if(execlp("echoall.o","echoall","only one arg",(char*)0)<0){
			err_sys("fork error");
		}
	}
	
	if(waitpid(pid,NULL,0)<0){
			err_sys("fork error");
	}
}

