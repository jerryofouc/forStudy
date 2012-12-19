#include"include/apue.h"
#include<pthread.h>

struct s_aa{
	int a;
	int b;
};
void* thr_fun1(void* arg){
	printf("thread 1 returing code\n");
	struct s_aa* sp = (struct s_aa*)malloc(sizeof(struct s_aa));
	sp->a = 10;
	sp->b = 20;
	return ((void*)sp);
}

void* thr_fun2(void* arg){
	printf("thread 2 returing code\n");
	pthread_exit((void*)2);
}

int main(void){
	int erro;	
	pthread_t tid;
	void* tret;
	erro = pthread_create(&tid,NULL,thr_fun1,NULL);
	if(erro){
		printf("error create thread1\n");
	}
	int rval_ptr;
	erro = pthread_join(tid,&tret);
	if(erro){
		printf("error\n");
	}
	printf("fun1 returning code is %d\n",((struct s_aa*)tret)->a);

	erro = pthread_create(&tid,NULL,thr_fun2,NULL);
	if(erro){
		printf("error create thread2\n");
	}
	erro = pthread_join(tid,&tret);
	if(erro){
		printf("error\n");
	}
	printf("fun2 returning code is %d\n",(int)tret);
}
