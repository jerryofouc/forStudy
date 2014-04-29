#include<stdio.h>
int main(int argc, char* argv[]){
	int i;
	char **pr;
	extern char **environ;

	for(i = 0;i<argc;i++){
		printf("argv[%d]: %s\n",i,argv[i]);
	}

	for(ptr = environ;)
}
