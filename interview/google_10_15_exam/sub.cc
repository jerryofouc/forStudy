#include<stdio.h>
#define SUB(x,y) x-y
#define ACCESS_BEFORE(element,offset,value) *SUB(&element,offset)=value

int main(){
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	ACCESS_BEFORE(array[5],4,6);
	printf("array:");
	for(int i=0;i<10;i++){
		printf("%d",array[i]);
	}
	printf("\n");
}
