#include<stdlib.h>
#include<stdio.h>
int main(){
	if(system("ls -l")){
		printf("error\n");
	}
}
