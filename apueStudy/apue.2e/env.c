#include<stdio.h>
extern char **environ;
int main(){
	int i=0;
	for(;i<10;i++){
		printf("%s\n",environ[i]);	
	}
}
