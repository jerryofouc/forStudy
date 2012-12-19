#include<stdio.h>
#include<string.h>
typedef int (*cmpfun)(char* p ,char* q);
char inputchars[50000000];
char* words[100000];	
int nwords;
int k = 2;

int wordcmp(char *p,char *q){
	int n = k;
	while(*p==*q){
		if(*p==0&&--n==0){
			return 0;	
		}
		p++;
		q++;
	}
	return *p-*q;
}

void swap(char* words[], int i,int j){
	char* temp = words[i];
	words[i] = words[j];
	words[j] = temp;
}

void qsort(char* words[],int start, int end,cmpfun cmp){
	if(start<end){
		int i = start-1;	
		int j ;
		for(j=start;j<end;j++){
			if(cmp(words[j],words[end])<0){
				swap(words,++i,j);
			}
		}
		swap(words,++i,end);
		qsort(words,start,i-1,cmp);
		qsort(words,i+1,end,cmp);
	}

}

int main(){
	words[0] = inputchars;
	nwords = 0;
	while(scanf("%s",words[nwords])!=EOF){
		words[nwords+1] = words[nwords] + strlen(words[nwords]) + 1;
		nwords++;
	}
	int i = 0;
	for(i=0;i<k;i++){
		words[nwords][i] = 0;	
	}
	i = 0;
	for(;i<nwords;i++){
		printf("%s\n",words[i]);
	}
	qsort(words,0,nwords-1,wordcmp);
	i = 0;
	for(;i<nwords;i++){
		printf("%s\n",words[i]);
	}
}
