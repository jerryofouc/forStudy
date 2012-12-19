#include"include/apue.h"
#include<pthread.h>
pthread_t ntid;

void printtids(const char*s){
	pid_t pid;	
	pid = getpid();
	pthread_t tid;
	tid = pthread_self();
	printf("%s pid %u tid %u (0x%x)\n",s,(unsigned int )pid,(unsigned int)tid,(unsigned int)tid,(unsigned int)tid);
}

void* thr_fn(void *arg){
	printtids("new thread: ");
	return ((void *)0);
}

int main(void){
	int err;
	err = pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err != 0){
		err_quit("can't create thread: %s\n",strerror(err));
	}
	printtids("main thread:");
	sleep(1);
	exit(0);
}
